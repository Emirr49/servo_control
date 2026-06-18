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
K_hinge = 0.2; % Nm/rad