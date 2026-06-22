# High-Fidelity Servo Actuator Control with Continuous Kalman-Bucy ADRC

This repository contains a high-fidelity MATLAB/Simulink framework for an aerospace-grade Permanent Magnet Synchronous Motor (PMSM) servo actuator operating through a **50:1 gearbox**. The project implements full cascaded **Field Oriented Control (FOC)** integrated with an **Active Disturbance Rejection Control (ADRC)** outer loop, driven by a continuous-time optimal state estimator (**Kalman-Bucy Filter**) to achieve precise speed tracking under heavy measurement noise and sudden load disturbances.

---

## 🚀 Key Features

### High-Fidelity Electromechanical Plant

Detailed simulation of:

- Continuous dq-axis electrical dynamics
- Stator resistance effects
- Rotor inertia
- Gearbox-reflected load dynamics

### Cascaded Field Oriented Control (FOC)

High-bandwidth inner current regulators (`Id`, `Iq`) nested beneath an outer mechanical speed control loop.

### Continuous Kalman-Bucy Filter

An S-domain optimal state estimator derived directly from physical plant parameters using the Continuous Algebraic Riccati Equation (CARE), enabling hidden state estimation without introducing phase lag.

### Active Disturbance Rejection Control (ADRC)

Real-time estimation of unknown external load torque (`Td`) and direct feedforward compensation into the current command path, bypassing PI integration delays.

### Dynamic Anti-Windup Logic

Custom saturation tracking and integrator clamping logic that prevents excessive overshoot when hardware current limits are reached.

---

## 📐 System Parameters & Core Mathematics

### 1. Actuator Properties

#### Electrical Parameters

| Parameter                | Value   |
| ------------------------- | ------- |
| DC Bus Voltage (`Vdc`)    | 48 V    |
| Stator Resistance (`Rs`)  | 0.2 Ω   |
| d-axis Inductance (`Ld`)  | 2 mH    |
| q-axis Inductance (`Lq`)  | 3 mH    |
| PM Flux Linkage (`λm`)    | 0.05 Wb |

#### Mechanical Parameters

| Parameter                          | Value             |
| ----------------------------------- | ----------------- |
| Gear Ratio (`Ngear`)                | 50                |
| Total Reflected Inertia (`Jsum`)    | 0.001004 kg·m²    |
| Viscous Damping (`Bm`)              | 0.0005 N·m·s/rad  |

#### Torque Constant

$$
K_t = 1.5 \cdot N \cdot \lambda_m
$$

For:

- Pole pairs: `N = 4`
- Flux linkage: `λm = 0.05 Wb`

Resulting in:

$$
K_t = 0.3 \ \text{Nm/A}
$$

---

### 2. Continuous State-Space Model

The observer estimates:

- Mechanical rotor speed (`ωm`)
- Unknown disturbance torque (`Td`)

The disturbance torque is modeled as a continuous random walk:

$$
\begin{bmatrix} \dot{\omega}_m \\ \dot{T}_d \end{bmatrix} = \begin{bmatrix} -\dfrac{B_m}{J_{sum}} & -\dfrac{1}{J_{sum}} \\ 0 & 0 \end{bmatrix} \begin{bmatrix} \omega_m \\ T_d \end{bmatrix} + \begin{bmatrix} \dfrac{K_t}{J_{sum}} \\ 0 \end{bmatrix} I_q + w(t)
$$

Measurement equation:

$$
y(t) = \begin{bmatrix} 1 & 0 \end{bmatrix} \begin{bmatrix} \omega_m \\ T_d \end{bmatrix} + v(t)
$$

where:

- `w(t)` = process noise
- `v(t)` = measurement noise

---

### 3. Optimal Gain Synthesis

Using:

$$
R = 0.05
$$

$$
Q = \text{diag}([0.1,\ 500])
$$

The continuous observer gains are obtained by solving the Continuous Algebraic Riccati Equation:

$$
AP + PA^T - PC^T R^{-1} C P + Q = 0
$$

Resulting gains:

| Gain  | Value   |
| ----- | ------- |
| `Kc1` | 445.83  |
| `Kc2` | -100.00 |

Where:

- `Kc1` = speed-state innovation gain
- `Kc2` = disturbance torque tracking gain

---

## 💻 Simulink Model Structure

The project is organized into independent validation stages:

```text
├── Open Loop Motor Model      # Raw electromechanical plant verification
├── Test Model                 # Diagnostic sandbox for validation steps
├── Speed Control              # Cascaded PI FOC implementation
└── Kalman Filter              # Observer and ADRC architecture
```

---

### Subsystem Layouts

#### Speed Controller & ADRC Stage

The outer speed controller is augmented by a disturbance rejection feedforward path.

The estimated disturbance torque (`Td`) is scaled by:

$$
\frac{1}{K_t}
$$

to compute the compensating quadrature current command.

This current is injected directly into the control path before:

- Current saturation
- Anti-windup logic

allowing rapid disturbance rejection without waiting for PI integrator action.

---

#### Kalman Filter Observer Subsystem

The observer consists of three major sections.

**Sensor Model**

Combines:

- True motor speed (`ωm`)
- Band-Limited White Noise

to generate realistic noisy measurements `y(t)`.

**Speed Estimation**

Implements the physical acceleration dynamics:

$$
\frac{K_t}{J_{sum}}, \quad \frac{B_m}{J_{sum}}, \quad \frac{1}{J_{sum}}
$$

along with the innovation correction term scaled by `Kc1`.

**Disturbance Estimation**

A continuous integration stage driven by estimation error and scaled by `Kc2`, enabling real-time extraction of unknown load torques.

---

## 📈 Validation & Verification Results

### 1. High-Frequency Noise Filtering

The speed sensor was intentionally corrupted using a **Band-Limited White Noise** block configured with:

| Parameter   | Value    |
| ----------- | -------- |
| Noise Power | 5×10⁻⁶   |
| Sample Time | 1×10⁻⁴ s |

This produces a sensor variance matching `R = 0.05`.

**Result:** The Kalman-Bucy filter successfully reconstructs a smooth speed trajectory through the center of the noise distribution while introducing negligible phase delay compared to conventional low-pass filters.

---

### 2. Transient Disturbance Rejection Test

A sudden 0.1 Nm load torque disturbance was applied at `t = 2.0 s` during a standard speed ramp.

**Observer Tracking**

The disturbance estimator converges to the true load value in approximately 10 ms, accurately identifying the full 0.1 Nm disturbance.

**Speed Tracking Robustness**

Due to direct disturbance feedforward compensation:

- Maximum speed deviation remains below **0.04 rad/s**
- Corresponding tracking error remains below **0.15%**
- Speed recovers to the reference trajectory within **15 ms**

without relying solely on outer-loop integral action.

---

## 🎯 Project Goals

- Build a high-fidelity PMSM servo actuator simulation framework
- Validate cascaded FOC architectures
- Implement continuous-time optimal state estimation
- Demonstrate Active Disturbance Rejection Control (ADRC)
- Evaluate robustness under sensor noise and load disturbances
- Provide a foundation for aerospace-grade servo actuator research and development

## Resources
- [PMSM](https://www.mathworks.com/help/sps/ref/pmsm.html)
