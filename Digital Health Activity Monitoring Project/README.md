# Behavioural Patterns in Fitbit Users

## Table of Contents
- [Behavioural Patterns in Fitbit Users](#behavioural-patterns-in-fitbit-users)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Dataset](#dataset)
  - [Methodology](#methodology)
    - [Data Preprocessing](#data-preprocessing)
    - [Feature Engineering](#feature-engineering)
    - [Exploratory Data Analysis](#exploratory-data-analysis)
    - [Clustering](#clustering)
    - [Activity Adherence Analysis](#activity-adherence-analysis)
  - [Key Findings](#key-findings)
  - [Conclusion \& Recommendations](#conclusion--recommendations)

---

## Overview

This project explores behavioral patterns in Fitbit users by analyzing activity, calorie, and sleep data collected from 30 participants over a 31-day period. The primary focus is on understanding how users’ step counts relate to calorie expenditure and identifying user clusters based on activity levels, while also comparing user behavior with WHO-recommended activity guidelines.

---

## Dataset

The dataset was collected via Amazon Mechanical Turk between March 12 and May 12, 2016. It consists of minute-level physical activity data from 30 users and includes variables such as:

- Step count
- Calorie expenditure
- Sleep patterns
- Activity duration (Sedentary, Light, Moderate, Very Active)

Key dataset transformations and additions:
- Filtered out rows with all zero values and capped outliers at the 95th percentile
- Created new aggregated and categorical features
- Final dataset includes engineered features like `TotalActiveMins`, `ActivityPreference`, and `Cluster`

---

## Methodology

### Data Preprocessing

- Loaded and cleaned raw Fitbit data from `dailyActivity_merged.csv`
- Removed invalid and zero-activity entries
- Capped outliers beyond the 95th percentile

### Feature Engineering

Introduced multiple new features for enhanced analysis:
- `TotalMins`, `TotalHours`: Total duration tracked
- `TotalActiveMins`, `TotalActiveHours`: Sum of active minutes
- `ActivityPreference`: Categorized as Light, Moderate, or High based on the proportion of VeryActiveMinutes

### Exploratory Data Analysis

- Generated box plots and histograms to understand distributions
- Applied `StandardScaler` to normalize feature values
- Analyzed weekday trends in `TotalSteps`, `Calories`, and `SedentaryMinutes`
- Created correlation heatmaps to determine strong predictors of calorie expenditure

### Clustering

- Used **K-Means** to group users into 4 distinct activity-based clusters
- Clusters represented a spectrum of activity levels from light to highly active
- Used the **Elbow Method** to determine the optimal number of clusters

### Activity Adherence Analysis

- Created a binary feature: `Meets Daily Requirements`
- Assessed whether users met WHO guidelines of 20+ active minutes per day
- Found most users missed this target occasionally, though they typically met the weekly 150-minute goal

---

## Key Findings

- Activity levels are higher on Mondays, Tuesdays, and Saturdays; lower on Sundays
- `TotalDistance` and `VeryActiveMinutes` were the strongest predictors of calorie expenditure
- Users were clustered into 4 groups with different activity intensity preferences
- 26 out of 30 users missed WHO’s daily recommendation at least once, but all met the weekly average

---

## Conclusion & Recommendations

- Fitness tracking data provides valuable insight into individual and group activity trends
- Fitness tracker companies can use this analysis to personalize notifications and interventions
- Governments and organizations can strategically plan events or health initiatives based on user behavior patterns
- Future research should include larger, more diverse samples and explore longer-term patterns

---

