### High-Fidelity Servo Actuator Modeling & Control & Estimation

* Developed a high-fidelity Permanent Magnet Synchronous Motor (PMSM) servo actuator model for aerospace-grade motion control systems, incorporating dq-axis electrical dynamics, back-EMF, rotor inertia, saturations, rate limits and white-noise sensor models, load torque disturbances.
* Synthesized a cascaded Field-Oriented Control (FOC) architecture with high-bandwidth inner current loops, robust outer speed loops, and feedforward cross-coupling compensation to eliminate axis interference.
* Integrated an Extended Kalman Filter (EKF) for optimal state estimation, minimizing measurement noise and decoupling parameter variation effects.
* Implemented a Sliding Mode Observer (SMO) paired with a Phase-Locked Loop (PLL) for sensorless rotor speed and position estimation.
* Implemented Active Disturbance Rejection Control (ADRC) combined with an internal state estimator to dynamically compensate for unmodeled external load disturbances (T_load).
* Mathematically Derived custom EKF, Kalman-Bucy, and Sliding Mode Observer (SMO + PLL) estimation algorithms from first principles without toolboxes.
