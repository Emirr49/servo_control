Rs = 0.2;        % Stator Resistance (Ohm)
Ld = 0.002;      % d-axis Inductance (H)
Lq = 0.003;      % q-axis Inductance (H)
lambda_m = 0.05; % PM Flux Linkage (Wb) // lamda_f
N = 4;           % Pole Pairs
J_m = 0.001;       % Rotor Inertia (kg*m^2) // J, J_sum
Bm = 0.0005;     % Damping Coefficient
% DC Bus Voltage (Standard 48V system for robotics)
Vdc = 48; 
% Switching Frequency (10 kHz)
f_sw = 10000;
Ts = 1/f_sw;
% aerospace actuator update
T_dist = 0.1; % Nm step at t = 0.5s
N_gear = 50;
J_load = 0.01;
J_sum = J_m + J_load/(N_gear^2);
% kalman filter varibles    
% PMSM Torque Constant (Te = 1.5 * N * lambda_m * Iq)
Kt = 1.5 * N * lambda_m; 

%% Continuous-Time State-Space Representation (dot_x = A*x + B*u)
% State vector: x = [omega_m; T_d] -> [Rotor Speed; Disturbance Torque]
% Input vector: u = Iq             -> [Quadrature Current]
A = [ -Bm/J_sum,  -1/J_sum ;
            0,         0 ];
B = [ Kt/J_sum ;
             0 ];
% Measurement matrix: y = C*x (We only measure speed directly)
C = [1, 0];
% Direct transmission matrix (No direct feedthrough from Iq to speed measurement)
D = 0;

%% Phase 2: Solving the Continuous Riccati Equation
% Define Noise Covariances (Continuous-Time Spectral Densities)
R = 0.05;  % Measurement noise covariance (Variance of the speed sensor jitter)
Q = [0.1,   0;
       0, 500]; % Process noise covariance [speed_uncertainty, torque_uncertainty]

% G matrix maps how process noise enters our states. 
G = eye(2); 

% --- TOOLBOX VERIFICATION METHOD ---
% Solve via built-in function to keep as reference benchmarks
[Kc_lqe, P_lqe, E_lqe] = lqe(A, G, C, Q, R);

% --- CUSTOM ITERATIVE RICCATI SOLVER (FROM SCRATCH) ---
% Initialize the error covariance matrix P with an initial guess
P_custom = eye(2) * 10.0; % Size: 2x2

% Numerical convergence tuning parameters
dt_riccati = 0.0001;     % Small integration timestep to guarantee numerical stability
max_iterations = 500000; % Upper limit to ensure loop termination
tolerance = 1e-11;       % Tightened convergence criteria for exact match

for iter = 1:max_iterations
    % 1. Precompute the continuous Kalman gain for this iteration step
    % Formula: K = P * C' * inv(R)
    K_iter = P_custom * C' * (1.0 / R); % Size: 2x1
    
    % 2. Evaluate the continuous-time Differential Riccati Equation (dP/dt)
    % Formula: dPdt = A*P + P*A' - K*C*P + G*Q*G'
    dPdt = A * P_custom + P_custom * A' - K_iter * C * P_custom + G * Q * G'; % Size: 2x2
    
    % 3. Check for steady-state convergence (if dP/dt is effectively zero)
    if max(abs(dPdt(:))) < tolerance
        break;
    end
    
    % 4. Propagate covariance forward via an explicit numerical Euler step
    P_custom = P_custom + dPdt * dt_riccati; % Size: 2x2
    
    % 5. Enforce strict mathematical symmetry to eliminate floating-point drift
    P_custom = 0.5 * (P_custom + P_custom'); 
end

% Extract final calculated steady-state continuous Kalman Gain vector from custom solver
Kc_custom = P_custom * C' * (1.0 / R); % Size: 2x1

% Extract individual scalar gains for your continuous blocks
Kc1 = Kc_custom(1); % Speed correction gain
Kc2 = Kc_custom(2); % Disturbance torque estimation gain

%% --- PRINT AND COMPARE PERFORMANCE RESULTS ---
fprintf('\n===================================================\n');
fprintf('     KALMAN FILTER GAIN MATRIX COMPARISON          \n');
fprintf('===================================================\n');
fprintf('State 1 (Speed Gain Kc1): \n');
fprintf('  MATLAB lqe() Function : %12.6f\n', Kc_lqe(1));
fprintf('  Custom Riccati Solver : %12.6f\n\n', Kc_custom(1));

fprintf('State 2 (Torque Disturbance Gain Kc2): \n');
fprintf('  MATLAB lqe() Function : %12.6f\n', Kc_lqe(2));
fprintf('  Custom Riccati Solver : %12.6f\n', Kc_custom(2));
fprintf('===================================================\n');

fprintf('\nAbsolute Solver Discrepancy Error: \n');
fprintf('  Delta Kc1: %e\n', abs(Kc_lqe(1) - Kc_custom(1)));
fprintf('  Delta Kc2: %e\n', abs(Kc_lqe(2) - Kc_custom(2)));
fprintf('===================================================\n');