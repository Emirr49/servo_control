function [x_hat_out, w_m_est, theta_m_est] = SMO_DQ_5State_impl(u, y)

persistent x_hat Ed Eq int_pll theta_hat theta_m_hat we_est initialized

%% 1. Updated Nominal Model Parameters
Ts    = 0.0001;
Pn    = 4;
Ld    = 0.002;
Lq    = 0.003;
Rs    = 0.20;
psi_m = 0.050;

%% 2. SMO & PLL Tuning Constants
K_smo = 80;
Phi   = 0.05;
wc    = 2*pi*100;

Kp_pll = 0.5;
Ki_pll = 300.0;

%% 3. Initialization
if isempty(initialized)

    x_hat = [0;0];

    Ed = 0;
    Eq = 0;

    int_pll = 0;

    theta_hat = 0;
    theta_m_hat = 0;

    we_est = 0;

    initialized = true;
end

%% 4. Inputs

vd = u(1);
vq = u(2);

id_meas = y(1);
iq_meas = y(2);

id_hat = x_hat(1);
iq_hat = x_hat(2);

%% 5. Sliding surface

e_d = id_hat - id_meas;
e_q = iq_hat - iq_meas;

z_d = -K_smo * max(-1,min(1,e_d/Phi));
z_q = -K_smo * max(-1,min(1,e_q/Phi));

%% 6. LPF

Ed = Ed + Ts*(-wc*Ed + wc*z_d);
Eq = Eq + Ts*(-wc*Eq + wc*z_q);

%% 7. Phase compensation

ratio = we_est/wc;

Ed_tmp  = Ed;
Ed_comp = Ed_tmp - ratio*Eq;
Eq_comp = Eq + ratio*Ed_tmp;

%% 8. PLL

emf_mag = sqrt(Ed_comp^2 + Eq_comp^2) + 0.01;

dir_sign = sign(we_est);
if dir_sign == 0
    dir_sign = 1;
end

e_theta = (Ed_comp/emf_mag)*dir_sign;

w_e_max = 400;

we_candidate = Kp_pll*e_theta + int_pll;

if (we_candidate < w_e_max && we_candidate > -w_e_max) || ...
   (we_candidate >= w_e_max && e_theta < 0) || ...
   (we_candidate <= -w_e_max && e_theta > 0)

    int_pll = int_pll + Ts*Ki_pll*e_theta;

end

we_est = max(-w_e_max,min(w_e_max,Kp_pll*e_theta + int_pll));

theta_hat = theta_hat + Ts*we_est;
theta_hat = atan2(sin(theta_hat),cos(theta_hat));

%% 9. Current observer

did_dt = -(Rs/Ld)*id_hat ...
       + (Lq/Ld)*we_est*iq_hat ...
       + vd/Ld ...
       + z_d/Ld;

diq_dt = -(Rs/Lq)*iq_hat ...
       - (Ld/Lq)*we_est*id_hat ...
       - (psi_m/Lq)*we_est ...
       + vq/Lq ...
       + z_q/Lq;

x_hat(1) = id_hat + Ts*did_dt;
x_hat(2) = iq_hat + Ts*diq_dt;

%% 10. Outputs

x_hat_out = x_hat;

w_m_est = we_est/Pn;

theta_m_hat = theta_m_hat + Ts*w_m_est;
theta_m_hat = atan2(sin(theta_m_hat),cos(theta_m_hat));

theta_m_est = theta_m_hat;

end