# Advanced Probabilistic Methods – Assignment 9

## Table of Contents
- [Advanced Probabilistic Methods – Assignment 9](#advanced-probabilistic-methods--assignment-9)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Subtasks](#requirements--subtasks)
    - [Part 1: Simulator-Based Inference](#part-1-simulator-based-inference)
    - [Part 2: Uncertainty Quantification](#part-2-uncertainty-quantification)
  - [Implementation Highlights](#implementation-highlights)
  - [Results \& Visualizations](#results--visualizations)

---

## Overview
In **Assignment 9**, we shift our focus to **simulator-based methods** and the ways in which we capture and represent **uncertainty** in our predictions. Our key themes include:
1. **Simulating** data from a known underlying process to test inference approaches.  
2. Constructing **prediction intervals** or **credibility intervals** to reflect model uncertainty.  
3. Comparing **simulation outputs** with real or synthetic data to assess model fidelity.

---

## Requirements & Subtasks

### Part 1: Simulator-Based Inference
- **Goal**: Develop or utilize a simulator that, given parameters, produces synthetic datasets resembling the real-world scenario.  
- **Approach**:
  1. Define a functional form or generative process (e.g., polynomial + noise, or a specialized domain simulator).  
  2. Draw parameter samples, run the simulator, collect synthetic data.  
  3. Perform inference (likelihood-based or approximate) to see if we can recover the true parameters from the synthetic data.  
- **Outcome**: A controlled environment where ground-truth parameters are known, enabling precise validation of the inference procedure.

---

### Part 2: Uncertainty Quantification
- **Goal**: Provide **prediction intervals** or credible bounds for new data points, capturing model uncertainty (parameters, noise, etc.).  
- **Approach**:
  1. Use posterior samples of the model’s parameters.  
  2. For each new input \( x_* \), compute the predictive distribution \( p(y_* \mid x_*, \text{data}) \).  
  3. Derive intervals (e.g., 95% credible intervals) from the distribution’s quantiles.  
- **Outcome**: Visualization of how wide or narrow the model’s predictions are, highlighting regions of higher/lower confidence.

---

## Implementation Highlights
- **Simulator**:
  - Possibly a polynomial + sine wave + Gaussian noise scenario, or any parametric function that’s flexible enough to produce interesting data shapes.  
  - Crisp separation between “true” function and “observed” noise to measure inference performance.
- **Prediction Intervals**:
  - Aggregating posterior draws to form predictive means and intervals.  
  - Plotting intervals around the predicted curve to reflect uncertainty in model and noise parameters.

---

## Results & Visualizations

1. **Simulated Data vs. Underlying Function**  
   ![Simulated Data vs. Simulator](Screenshot%202025-03-23%20141051.jpg) 
2. **Uncertainty Bounds**  
   ![Uncertainty Intervals](Screenshot%202025-03-23%20141152.jpg)  
