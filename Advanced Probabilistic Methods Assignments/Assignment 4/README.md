# Advanced Probabilistic Methods – Assignment 4

## Table of Contents
- [Advanced Probabilistic Methods – Assignment 4](#advanced-probabilistic-methods--assignment-4)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Subtasks](#requirements--subtasks)
    - [Part 1: Model Selection \& Regularization](#part-1-model-selection--regularization)
    - [Part 2: Bayesian Nonlinear Regression](#part-2-bayesian-nonlinear-regression)
    - [Part 3: Laplace Approximation \& Posterior Analysis](#part-3-laplace-approximation--posterior-analysis)
  - [Implementation Highlights](#implementation-highlights)
  - [Results \& Visualizations](#results--visualizations)

---

## Overview
In this fourth assignment for **Advanced Probabilistic Methods**, we focus on:
1. **Model complexity** and **regularization** strategies (e.g., controlling polynomial degrees or shrinkage parameters).  
2. **Bayesian nonlinear regression**, where the response function may be polynomial or involve non-linear transformations.  
3. **Laplace approximations** (or alternative) to approximate complex posteriors and facilitate parameter inference.

---

## Requirements & Subtasks

### Part 1: Model Selection & Regularization
- **Goal**: Avoid overfitting by introducing penalties or selecting simpler models.  
- **Approach**:
  1. Introduce a **regularization parameter** (e.g., \(\alpha\)) in a polynomial regression or advanced model.  
  2. Fit data under different \(\alpha\) (or polynomial degrees) using training/validation sets.  
  3. Evaluate performance metrics (e.g., **MSE**) to pick the best model.  
- **Outcome**: Balanced performance across training and testing sets, mitigating high-variance fits.

---

### Part 2: Bayesian Nonlinear Regression
- **Goal**: Place a **Bayesian** framework around the regression, with prior distributions on parameters (including \(\alpha\) and \(\beta\) for precision or scale).  
- **Approach**:
  1. Write down the likelihood for the polynomial or non-linear model: \(p(\mathbf{y} \mid \mathbf{x}, \theta)\).  
  2. Combine with priors to get \(p(\theta \mid \mathbf{y})\).  
  3. Summarize posterior with **MAP** or **Bayesian** point estimates and use it for predictions.  
- **Outcome**: A flexible regression curve that inherently captures uncertainty in parameters.

---

### Part 3: Laplace Approximation & Posterior Analysis
- **Goal**: Approximate the posterior of \(\theta\) when direct sampling or closed-form solutions are impractical.  
- **Approach**:
  1. Identify the mode of \(p(\theta \mid \mathbf{y})\) (the **MAP** estimate).  
  2. Approximate curvature at the mode, yielding a **Gaussian** approximation to the posterior.  
  3. Compare the approximate posterior to the “true” or more exact posterior if available.  
- **Outcome**: Quick approximate inference for complex models, with a measure of how well the Laplace approximation fits.

---

## Implementation Highlights
- **Regularization**:  
  - Could be **L2** (ridge) or controlled by a prior with heavier tails.  
  - Tuning via cross-validation or direct evidence maximization.  
- **Nonlinear Polynomials**:  
  - Possibly expansions like \( \phi(x) = [1, x, x^2, \dots, x^M] \).  
  - Observing the trade-off between polynomial degree and data fit.  
- **Laplace Approx.**:  
  - Numerically find the posterior mode (e.g., using gradient-based optimization).  
  - Estimate Hessian at the mode to form the Gaussian approximation.

---

## Results & Visualizations

1. **Learned Model (ML-II)**  
   ![Learned Model: ML-II](Screenshot%202025-03-23%20140322.jpg)  

2. **Validation Approach**  
   ![Validation Approach](Screenshot%202025-03-23%20140350.jpg)  

3. **Laplace Approximation vs. True Posterior**  
   ![Posterior Comparison](Screenshot%202025-03-23%20140415.jpg) 
