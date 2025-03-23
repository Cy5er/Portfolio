# Machine Learning for Diffusion Energy Prediction

## Table of Contents
- [Machine Learning for Diffusion Energy Prediction](#machine-learning-for-diffusion-energy-prediction)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Dataset](#dataset)
  - [Objectives](#objectives)
  - [Workflow](#workflow)
    - [1. Data Preprocessing](#1-data-preprocessing)
    - [2. Principal Component Analysis (PCA)](#2-principal-component-analysis-pca)
    - [3. Regression Modeling](#3-regression-modeling)
      - [Linear Regression](#linear-regression)
      - [Random Forest Regressor](#random-forest-regressor)
      - [Support Vector Regressor (SVR)](#support-vector-regressor-svr)
    - [4. Feature Importance](#4-feature-importance)
  - [Results](#results)
  - [Conclusion](#conclusion)

---

## Overview
This notebook applies **machine learning** techniques to predict **diffusion activation energies (E_raw)** for dilute solute systems in materials. It explores dimensionality reduction using **Principal Component Analysis (PCA)** and evaluates multiple regression models to understand structure–property relationships.

---

## Dataset
The dataset used is `Dilute_Solute_Diffusion_with_features.csv`, which includes:
- Material-specific features
- Two categorical composition features
- Target variables: `E_raw (eV)` and `Enorm (eV)`

---

## Objectives
- Preprocess the dataset and encode categorical variables
- Explore variance and dimensionality reduction using PCA
- Train multiple regression models to predict `E_raw (eV)`
- Analyze most influential features using PCA loadings

---

## Workflow

### 1. Data Preprocessing
- Categorical variables `Material compositions 1` and `2` were one-hot encoded.
- Target variable: `E_raw (eV)`
- The feature matrix was cleaned and extracted.
- A heatmap was plotted to visualize the sorted energy values.

### 2. Principal Component Analysis (PCA)
- PCA was performed to reduce dimensionality and understand variance in the dataset.
- A **scree plot** was used to identify the **elbow point** to determine the optimal number of components.
- Biplots and component scatter plots were visualized to explore patterns and relationships.

### 3. Regression Modeling

#### Linear Regression
- PCA-transformed data was used as input.
- Model was evaluated using **Mean Squared Error (MSE)** and **R-squared (R²)** metrics.

#### Random Forest Regressor
- A Random Forest model with 100 estimators was trained.
- Evaluated on the test split using MSE and R².

#### Support Vector Regressor (SVR)
- SVR was trained on the same PCA-reduced data.
- Final evaluation was done using the same metrics.

### 4. Feature Importance
- PCA loadings were analyzed to identify the most **significant features** across all principal components.
- A sorted importance ranking was printed to highlight dominant material features contributing to diffusion energy.

---

## Results

| Model               | Mean Squared Error | R-squared (R²) |
|--------------------|--------------------|----------------|
| Linear Regression  | *Displayed in output* | *Displayed in output* |
| Random Forest      | *Displayed in output* | *Displayed in output* |
| Support Vector Regressor | *Displayed in output* | *Displayed in output* |

- PCA explained a large proportion of variance with a small number of components.
- Random Forest achieved the best predictive performance (in most cases).
- Key features (after PCA loading analysis) contribute significantly to variation in `E_raw`.

---

## Conclusion
This notebook demonstrates how dimensionality reduction with PCA and regression modeling can be used to analyze and predict material diffusion properties. Insights into feature importance and model performance help guide future studies in materials informatics and alloy design.
