function [x_hat_out, z_dq] = SMO_DQ_CurrentObserver_impl(u, y)
    % persistent variables for state retention
    persistent x_hat initialized
    
    %% 1. Nominal Model Parameters (Matching EKF parameters)
    Ts    = 0.0001;      % 10 kHz sample rate
    Pn    = 4;           % Pole Pairs
    Ld    = 0.002;       % d-axis Inductance
    Lq    = 0.003;       % q-axis Inductance
    Rs    = 0.15;        % Underestimated Rs (0.15 vs true 0.2)
    psi_m = 0.045;       % Underestimated psi_m
    
    %% 2. SMO Tuning Parameters
    K_smo = 100;         % Sliding gain (must be large enough to overcome disturbance)
    Phi   = 0.05;        % Boundary layer width for sat() function
    
    %% 3. First-Run Initialization
    if isempty(initialized)
        x_hat = [0; 0];  % [id_hat; iq_hat]
        initialized = 1;
    end
    
    %% 4. Unpack Inputs & Measurements
    vd = u(1);
    vq = u(2);
    
    id_meas = y(1);
    iq_meas = y(2);
    wm_meas = y(3);      % Speed measurement (or from previous state estimate)
    
    we = Pn * wm_meas;
    
    id_hat = x_hat(1);
    iq_hat = x_hat(2);
    
    %% 5. STEP 2: Calculate Current Errors and Switching Actions (zd, zq)
    e_d = id_hat - id_meas;
    e_q = iq_hat - iq_meas;
    
    % Saturation function implementation for chattering mitigation
    z_d = -K_smo * max(-1, min(1, e_d / Phi));
    z_q = -K_smo * max(-1, min(1, e_q / Phi));
    
    %% 6. STEP 1: Current State Prediction (Euler Integration)
    did_dt = -(Rs/Ld)*id_hat + (Lq/Ld)*we*iq_hat + (1/Ld)*vd + (1/Ld)*z_d;
    diq_dt = -(Rs/Lq)*iq_hat - (Ld/Lq)*we*id_hat - (psi_m/Lq)*we + (1/Lq)*vq + (1/Lq)*z_q;
    
    % Update states
    x_hat(1) = id_hat + Ts * did_dt;
    x_hat(2) = iq_hat + Ts * diq_dt;
    
    %% 7. Outputs
    x_hat_out = x_hat;
    z_dq      = [z_d; z_q];
end