# Advanced Probabilistic Methods – Assignment 7

## Table of Contents
- [Advanced Probabilistic Methods – Assignment 7](#advanced-probabilistic-methods--assignment-7)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Subtasks](#requirements--subtasks)
    - [Part 1: Evidence Lower BOund (ELBO) Tracking](#part-1-evidence-lower-bound-elbo-tracking)
    - [Part 2: Mixture Model Classification](#part-2-mixture-model-classification)
    - [Part 3: Model Selection \& Cross-Validation](#part-3-model-selection--cross-validation)
  - [Implementation Highlights](#implementation-highlights)
  - [Results \& Visualizations](#results--visualizations)

---

## Overview
In **Assignment 7**, we continue refining our approach to **mixture modeling** and inference. We place particular emphasis on:
1. **Monitoring the ELBO** (Evidence Lower BOund) to ensure stable variational optimization.  
2. Employing mixture components for **clustering** or **classification** in multi-cluster datasets.  
3. Using **cross-validation** to select the optimal number of mixture components, balancing model fit and complexity.

---

## Requirements & Subtasks

### Part 1: Evidence Lower BOund (ELBO) Tracking
- **Goal**: Confirm that our variational inference or other approximate method converges.  
- **Approach**:
  1. Compute and record the ELBO at each iteration of the inference algorithm.  
  2. Plot how the ELBO evolves, verifying it does not diverge or stall prematurely.  
- **Outcome**: A stable or monotonically increasing ELBO suggests we are successfully minimizing KL divergence and improving our approximate posterior.

---

### Part 2: Mixture Model Classification
- **Goal**: Use a fitted mixture model to **classify** new observations (e.g., test data) by assigning them to the most likely cluster.  
- **Approach**:
  1. Train a finite mixture model (e.g., with 2–5 components).  
  2. For each data point, compute posterior probabilities over clusters and choose the highest.  
  3. Evaluate the clustering on withheld (test) data, possibly by visual inspection or log-likelihood.  
- **Outcome**: Distinct clusters that align well with multi-class or multi-modal patterns in the data.

---

### Part 3: Model Selection & Cross-Validation
- **Goal**: Determine the **best** number of mixture components (or complexity) using cross-validation or a hold-out set.  
- **Approach**:
  1. Fit multiple mixture models with K = 1, 2, 3, …  
  2. Evaluate each with cross-validation scores or test log-likelihood.  
  3. Pick the model that best balances fit and overfitting risk.  
- **Outcome**: A justifiable choice of mixture component count that yields strong performance on test data without excessive complexity.

---

## Implementation Highlights
- **ELBO Computation**:  
  - Summation over data points and clusters, plus latent variable distributions.  
  - Tracking over iterations to ensure stable improvement in approximate inference.
- **Mixture Classification**:  
  - Posterior cluster assignment: \( z = \arg \max_k \, p(z=k \mid x_i) \).  
  - Plotting data color-coded by cluster membership.
- **Cross-Validation**:  
  - Potentially a simple hold-out set approach or K-fold.  
  - Summarizing model performance vs. number of components in a bar chart or line plot.

---

## Results & Visualizations

1. **ELBO Progression**  
   ![ELBO Plot](Screenshot%202025-03-23%20140819.jpg)   

2. **Training/Test Data Clusters**  
   ![Training vs. Test Data](Screenshot%202025-03-23%20140845.jpg)  

3. **Model Selection & Cross-Validation**  
   ![Model Selection](Screenshot%202025-03-23%20140855.jpg)  