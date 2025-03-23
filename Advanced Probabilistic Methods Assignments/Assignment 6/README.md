# Advanced Probabilistic Methods – Assignment 6

## Table of Contents
- [Advanced Probabilistic Methods – Assignment 6](#advanced-probabilistic-methods--assignment-6)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Subtasks](#requirements--subtasks)
    - [Part 1: Mixture Models \& Clustering](#part-1-mixture-models--clustering)
    - [Part 2: Variational Inference for Mixtures](#part-2-variational-inference-for-mixtures)
    - [Part 3: Parameter Visualization \& Convergence](#part-3-parameter-visualization--convergence)
  - [Implementation Highlights](#implementation-highlights)
  - [Results \& Visualizations](#results--visualizations)

---

## Overview
In this sixth assignment, we tackle **mixture modeling** and **variational inference** methods. Our primary objectives include:
1. Constructing a **finite mixture model** for data clustering or density estimation.  
2. Applying **variational methods** to approximate posterior distributions over mixture components.  
3. Observing how these approximations evolve and converge, comparing results to the true data distribution.

---

## Requirements & Subtasks

### Part 1: Mixture Models & Clustering
- **Goal**: Represent data \(x\) as coming from a mixture of different components (e.g., Gaussians).  
- **Approach**:
  1. Specify mixture components, each with parameters (means, variances, etc.).  
  2. Assign mixing weights \(\tau\) summing to 1.  
  3. Fit or estimate parameters via maximum likelihood or Bayesian updates.  
- **Outcome**: A flexible approach allowing multiple “peaks” in the data distribution, capturing multi-modality or clustering.

---

### Part 2: Variational Inference for Mixtures
- **Goal**: Use **variational** techniques (e.g., **mean-field**) to approximate the intractable posterior of mixture parameters.  
- **Approach**:
  1. Factorize the joint distribution into \(q(\tau)\) and \(q(\theta)\), or as needed for each mixture component.  
  2. Iteratively update each factor by minimizing the **Kullback–Leibler (KL)** divergence to the true posterior (coordinate ascent).  
  3. Track improvements in **ELBO** (Evidence Lower BOund) or watch changes in each factor’s distribution.  
- **Outcome**: Posterior approximations for the mixing weights (\(\tau\)) and component parameters (\(\theta\)) that converge over iterations.

---

### Part 3: Parameter Visualization & Convergence
- **Goal**: Demonstrate how the approximate mixture distribution evolves, comparing early vs. final iteration results.  
- **Approach**:
  1. After each iteration, compute the updated mixture PDF and plot against the true data histogram.  
  2. Visualize factor distributions \(q(\tau)\) and \(q(\theta)\) to see how they peak or spread.  
  3. Check final estimates of expected \(\tau\) and \(\theta\) (means or MAP) after convergence.  
- **Outcome**: Confidence in the mixture model’s performance, plus insights into how quickly (and accurately) variational inference converges.

---

## Implementation Highlights
- **Mixture of Gaussians** (or other distributions):  
  - Possibly employing a **Gaussian** mixture with unknown means, variances, and mixing proportions.  
  - Could handle advanced distributions if the scenario requires it.  
- **Coordinate Ascent Updates**:  
  - Iteratively refine the variational distributions for each parameter group.  
  - Evaluate the ELBO to confirm improvements.  
- **Plots**:  
  - Overlaid **estimated** vs. **true** PDF against a **data histogram**.  
  - Factor distributions for \(\tau\) and \(\theta\) that show focusing around the true values.

---

## Results & Visualizations

1. **Variational Iterations**  
   ![Variational Mixture Updates](Screenshot%202025-03-23%20140648.jpg)  
   *Three snapshots (iteration 1, 3, 15) show how the mixture model’s PDF (red) aligns more closely with the true PDF (black) and data histogram (blue).*

   - **Top row**: Data histogram vs. true PDF vs. the currently estimated PDF.  
   - **Middle row**: The variational distribution \(q(\tau)\) for the mixing weight(s).  
   - **Bottom row**: The variational distribution \(q(\theta)\) for component parameters (e.g., means).

2. **Convergence Trends**  
   - Mean estimates (\(\mathbb{E}[\tau], \mathbb{E}[\theta]\)) shift closer to the true values over iterations.  
   - Mixture components become sharper or narrower as inference pinpoints each mode.

Through these steps, we gain practical insights into **finite mixture** modeling and how **variational inference** can iteratively refine our posterior approximations toward multi-modal data distributions.
