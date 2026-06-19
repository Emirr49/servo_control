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

% Define Noise Covariances
R = 0.05;  % Measurement noise covariance (Variance of the speed sensor jitter)

Q = [0.1,   0;
       0, 500]; % Process noise covariance [speed_uncertainty, torque_uncertainty]

% G matrix maps how process noise enters our states. 
% Since noise independently impacts both speed and torque equations, G is an identity matrix.
G = eye(2); 

% Solve the Continuous-Time Algebraic Riccati Equation to get optimal gains
% Kc will be a 2x1 vector: [Kc1; Kc2]
[Kc, P, E] = lqe(A, G, C, Q, R);

% Extract individual scalar gains for our continuous blocks
Kc1 = Kc(1); % Speed correction gain
Kc2 = Kc(2); % Disturbance torque estimation gain



