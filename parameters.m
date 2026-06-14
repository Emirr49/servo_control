Rs = 0.2;        % Stator Resistance (Ohm)
Ld = 0.002;      % d-axis Inductance (H)
Lq = 0.003;      % q-axis Inductance (H)
lambda_m = 0.05; % PM Flux Linkage (Wb) // lamda_f
N = 4;           % Pole Pairs
J_sum = 0.001;       % Rotor Inertia (kg*m^2) // J
Bm = 0.0005;     % Damping Coefficient

% DC Bus Voltage (Standard 48V system for robotics)
Vdc = 48; 

% Switching Frequency (10 kHz)
f_sw = 10000;
Ts = 1/f_sw;