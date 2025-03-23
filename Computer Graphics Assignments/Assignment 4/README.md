# Computer Graphics – Assignment 4: Physical Simulation

## Table of Contents
- [Computer Graphics – Assignment 4: Physical Simulation](#computer-graphics--assignment-4-physical-simulation)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements](#requirements)
    - [R1: Euler Integrator](#r1-euler-integrator)
    - [R2: Spring System](#r2-spring-system)
    - [R3: Trapezoid Integrator](#r3-trapezoid-integrator)
    - [R4: Multi-Pendulum System](#r4-multi-pendulum-system)
    - [R5: Cloth System](#r5-cloth-system)
  - [Implementation Highlights](#implementation-highlights)
  - [Controls \& Features](#controls--features)
  - [Screenshots \& Results](#screenshots--results)

---

## Overview
This assignment focuses on **numerical integration** and **particle-based physical simulation**. We explore how to:
1. Implement **ODE integrators** (Euler, Trapezoid, etc.).  
2. Formulate and solve **spring-based particle systems** (single springs, multi-segment pendulums).  
3. Simulate a **cloth** mesh using an interconnected grid of springs.

Through these systems, we learn how Newton’s laws translate into code via forces (gravity, drag, spring forces) and how integrators step the system in time.

---

## Requirements

### R1: Euler Integrator
- **Goal**: Implement the **explicit Euler** method to advance a state `X` in time by step size `h`.  
- **Approach**:  
  1. Compute `f0 = f(X)`, the time derivative of the state.  
  2. Update state: `X_new = X + h * f0`.  
- **Outcome**: A straightforward but less stable integrator. Larger time steps can lead to rapidly diverging solutions.

---

### R2: Spring System
- **Goal**: Create a basic 2D/3D spring system with one **fixed** particle and one **free** particle attached by a spring.  
- **Approach**:  
  1. **reset()**: Initialize positions/velocities of two particles. One is fixed in place (no net force), the other is free.  
  2. **evalF()**: Accumulate forces on the free particle:
     - Gravity  
     - Spring force (between fixed & free particle)  
     - Drag (linear in velocity, if included)  
- **Outcome**: Observe a single bob-like motion as the free particle oscillates around the fixed anchor.

---

### R3: Trapezoid Integrator
- **Goal**: Implement the **trapezoidal rule** for numerical integration to reduce error and improve stability.  
- **Approach**:
  1. Calculate `f0 = f(X)` at the current state.  
  2. Estimate an Euler step: `X_euler = X + h * f0`.  
  3. Evaluate `f1 = f(X_euler)`.  
  4. Final update: `X_new = X + (h/2) * (f0 + f1)`.  
- **Outcome**: A more stable integrator than Euler, typically comparable in accuracy to midpoint integration.

---

### R4: Multi-Pendulum System
- **Goal**: Generalize the spring system to form a chain of pendulums (multiple segments).  
- **Approach**:  
  1. **reset()**: Create N particles, typically the topmost is fixed. Adjacent particles connect via springs.  
  2. **evalF()**: For each particle:
     - Add gravity.  
     - Add drag if applicable.  
     - Add spring forces from connections (both structural neighbors if you want a chain-like system).  
     - For the topmost (fixed) particle, zero its acceleration.  
- **Outcome**: A chain-like pendulum system that can be made quite long. Integrator choice strongly affects stability.

---

### R5: Cloth System
- **Goal**: Build a 2D grid of particles to simulate cloth, connecting neighbors with springs.  
- **Approach**:  
  1. **reset()**:  
     - Create a grid of particles (e.g., NxM).  
     - Connect:
       - Structural springs (horizontal & vertical neighbors).  
       - Shear springs (diagonal neighbors).  
       - Flexion springs (skip one particle in the row/column).  
  2. **evalF()**:  
     - Loop over all springs, accumulate forces on each connected particle.  
     - Add gravity, drag, fix certain corners if you want them pinned, etc.  
- **Outcome**: A mesh that sags or flaps under gravity. The integrator used and the spring constants heavily influence stability (high stiffness often requires smaller time steps or more robust integrators).

---

## Implementation Highlights
- **Particle Systems**:  
  - Each system (Simple, Spring, Pendulum, Cloth) tracks a state vector combining positions & velocities of all particles.  
  - Forces (gravity, spring, drag) are applied within `evalF()` to compute the derivative of the state.
- **Integrators**:  
  - **Euler** is straightforward but can explode (unstable) at moderate or large steps.  
  - **Trapezoid** uses an average slope (initial + guessed end) to improve stability.  
- **Data Structures**:  
  - Use arrays or vectors for spring info (pairs of particle indices).  
  - Helper accessors (e.g., `position(i)` / `velocity(i)`) minimize indexing mistakes.

---

## Controls & Features
- **System Selection** (`1` to `4` or via UI):
  1. **Simple**: Single-particle ODE (non-physical).  
  2. **Spring**: Two particles, one fixed.  
  3. **Pendulum**: Multi-segment chain.  
  4. **Cloth**: Grid-based spring mesh.  
- **Integrator Selection** (`F1` to `F4` or via UI):
  - Euler, Midpoint, Trapezoid, (optionally) RK4 if implemented.  
- **Parameters**:
  - **Spring constant**: Higher values stiffen the system but can cause instability if time step is large.  
  - **Drag coefficient**: Increases damping.  
  - **Step size (dt)**: Integration timestep.  
  - **Steps per update**: How many integration steps happen each frame.  
- **Reset System** (`R`): Restores initial positions.  
- **Phase Portrait** (for simple systems): Plots the state in a 2D plane for analysis.  

---

## Screenshots & Results

1. **Multi-Pendulum (3 segments)**  
   ![Screenshot: Multi-pendulum](Screenshot%202025-03-23%20133150.jpg)

2. **Cloth System**  
   ![Screenshot: Cloth with structural and diagonal springs](Screenshot%202025-03-23%20133214.jpg)

3. **Simple System**  
   ![Screenshot: Single rotating point in a circle-like ODE](Screenshot%202025-03-23%20133223.jpg)

4. **Spring System**  
   ![Screenshot: Basic spring system](Screenshot%202025-03-23%20133235.jpg)

In each system, the UI allows changing constants, integrators, and time steps. Cloth or multi-pendulum setups illustrate how integrators handle stiff springs at different timesteps.
