function [x_hat_out, w_m_est, theta_m_est] = SMO_DQ_5State_impl(u, y)
    % Persistent variables for filter memory
    persistent x_hat Ed Eq int_pll theta_hat initialized
    
    %% 1. Parameters (Aligned with your setup)
    Ts    = 0.0001;      % 10 kHz sampling rate
    Pn    = 4;           % 4 Pole Pairs
    Ld    = 0.002;       
    Lq    = 0.003;       
    Rs    = 0.15;        % Intentional parameter mismatch
    psi_m = 0.045;       
    
    %% 2. SMO & PLL Tuning Constants
    K_smo = 80;          % Sliding gain
    Phi   = 0.05;        % Boundary layer width
    wc    = 2 * pi * 100;% LPF cutoff frequency (100 Hz)
    
    % PLL Gains (Tune for target speed dynamics)
    Kp_pll = 50;         
    Ki_pll = 500;        
    
    %% 3. First-Run Initialization
    if isempty(initialized)
        x_hat     = [0; 0];  % [id_hat; iq_hat]
        Ed        = 0;
        Eq        = 0;
        int_pll   = 0;
        theta_hat = 0;
        initialized = 1;
    end
    
    %% 4. Unpack Inputs & Measurements
    vd = u(1);
    vq = u(2);
    
    id_meas = y(1);
    iq_meas = y(2);
    
    id_hat = x_hat(1);
    iq_hat = x_hat(2);
    
    %% 5. Speed & Position Feedback from internal PLL state
    we_est = Kp_pll * 0 + int_pll; % Updated in step 8
    
    %% 6. STEP 2: Current Errors & Switching Action (zd, zq)
    e_d = id_hat - id_meas;
    e_q = iq_hat - iq_meas;
    
    z_d = -K_smo * max(-1, min(1, e_d / Phi));
    z_q = -K_smo * max(-1, min(1, e_q / Phi));
    
    %% 7. STEP 1: Current State Prediction
    did_dt = -(Rs/Ld)*id_hat + (Lq/Ld)*we_est*iq_hat + (1/Ld)*vd + (1/Ld)*z_d;
    diq_dt = -(Rs/Lq)*iq_hat - (Ld/Lq)*we_est*id_hat - (psi_m/Lq)*we_est + (1/Lq)*vq + (1/Lq)*z_q;
    
    x_hat(1) = id_hat + Ts * did_dt;
    x_hat(2) = iq_hat + Ts * diq_dt;
    
    %% 8. STEP 3: LPF for Equivalent Control (Back-EMF filtering)
    % TF'nin açılmış halinde transfer fonksiyonunun backward euler ile
    % discrete yapılması sonucu yazılmış.
    Ed = Ed + Ts * (-wc * Ed + wc * z_d);
    Eq = Eq + Ts * (-wc * Eq + wc * z_q);
    
    %% 9. STEP 4: Angle Error & PLL Loop
    % Speed direction sign handling
    dir_sign = sign(we_est);
    if dir_sign == 0, dir_sign = 1; end
    
    e_theta = -Ed * dir_sign; % Angular error signal
    
    % PI Loop for Speed & Angle Integration
    int_pll = int_pll + Ts * Ki_pll * e_theta;
    we_est  = Kp_pll * e_theta + int_pll;
    
    % Mechanical Speed & Angle Output
    wm_est    = we_est / Pn;
    theta_hat = theta_hat + Ts * we_est;
    
    % Wrap angle between -pi and pi
    theta_hat = atan2(sin(theta_hat), cos(theta_hat));
    
    %% 10. Output Assignments
    x_hat_out   = [x_hat(1); x_hat(2)];
    w_m_est     = wm_est;
    theta_m_est = theta_hat / Pn; % Mechanical angle
end