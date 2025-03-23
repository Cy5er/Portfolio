# Predicting Used Car Prices with a Decision Tree and Polynomial Regression

## Table of Contents
- [Predicting Used Car Prices with a Decision Tree and Polynomial Regression](#predicting-used-car-prices-with-a-decision-tree-and-polynomial-regression)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Problem Formulation](#problem-formulation)
  - [Dataset Description](#dataset-description)
  - [Methods](#methods)
    - [Data Preprocessing](#data-preprocessing)
    - [Feature Engineering](#feature-engineering)
    - [Modeling Approaches](#modeling-approaches)
      - [Decision Tree Regression](#decision-tree-regression)
      - [Polynomial Regression](#polynomial-regression)
  - [Results](#results)
  - [Conclusion](#conclusion)

---

## Overview
This project aims to predict the selling price of a used car based on various car characteristics. Focusing on Ford trucks from Craigslist sales listings, two regression methods were implemented: Decision Tree Regression and Polynomial Regression. Our analysis shows that the decision tree model provides significantly better predictions than the polynomial approach.

---

## Problem Formulation
The goal is to accurately estimate the price of a used car using features related to its condition. The features include:
- The year of manufacture
- Odometer reading (miles driven)
- Fuel type
- Transmission type

This is treated as a regression problem where the output is a continuous price value.

---

## Dataset Description
- **Source**: Used car sales listings from Craigslist (Used Cars Dataset, 2021 on Kaggle).
- **Scope**: Data is filtered to include only Ford trucks.
- **Features**:
  - `price` (target)
  - `year`
  - `odometer`
  - `fuel` (converted to integer)
  - `transmission` (converted to integer)
- **Size**: The final dataset contains 9,564 rows and 5 columns.

---

## Methods

### Data Preprocessing
- Removed rows with a price of 0 or with null/empty values.
- Filtered data to include only listings where `manufacturer` is 'ford' and `type` is 'truck'.
- Converted categorical variables (fuel and transmission) into numerical values.
- Extracted the relevant columns and converted them into numpy arrays for further analysis.

### Feature Engineering
- Selected features include odometer, year, fuel type, and transmission type.
- The target variable is the car price.
- Data was further prepared by mapping string values to integers based on predefined conversion tables.

### Modeling Approaches

#### Decision Tree Regression
- Implemented using `DecisionTreeRegressor` with a squared error criterion.
- The model partitions the data into segments (nodes/leaves) based on feature splits.
- It demonstrated strong performance by effectively handling non-linear relationships and outliers.

#### Polynomial Regression
- Generated polynomial features up to degree 10 using `PolynomialFeatures`.
- A Linear Regression model was then fitted to these transformed features.
- This approach struggled to capture the complex relationships in the data, resulting in poor predictive performance.

---

## Results
- **Decision Tree Regression**:
  - Achieved approximately 92.76% accuracy on the validation set.
  - Training and validation errors were very low compared to the polynomial model.
- **Polynomial Regression**:
  - Produced 0% accuracy with extremely high mean squared errors.
  - The poor performance is likely due to the presence of outliers and the wide range of car prices in the dataset.
  
These results indicate that decision tree regression is far more suitable for this prediction task on used car prices.

---

## Conclusion
The analysis shows that predicting used car prices for Ford trucks is best accomplished using Decision Tree Regression. This method outperforms polynomial regression by effectively handling non-linearities and outlier values inherent in the dataset. While polynomial regression was hypothesized to capture non-linear trends, it failed due to the dataset’s complexity and variability. Future work may explore ensemble methods or additional feature engineering to further improve model accuracy.
