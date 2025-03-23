# My Portfolio

Hi, I'm Syed, a MACADAMIA student at Aalto University, and welcome to my portfolio! This is a showcase of the diverse collection of projects and assignments I have worked on. For each project, I provide an overview of the objectives, my approach, and key outcomes. **Please note that, to maintain academic integrity, full assignment code is omitted here.** Instead, you will find high-level descriptions, selected code snippets, performance summaries, or supporting documentation. If any assignments are missing, it is either because they involve derivations by hand, were considered uninteresting, or – maybe – I just forgot. :D

---

## Table of Contents

- [My Portfolio](#my-portfolio)
  - [Table of Contents](#table-of-contents)
  - [Advanced Computer Graphics Assignments](#advanced-computer-graphics-assignments)
  - [Advanced Probabilistic Methods Assignments](#advanced-probabilistic-methods-assignments)
  - [C++ Tower Defense Project](#c-tower-defense-project)
  - [Computer Graphics Assignments](#computer-graphics-assignments)
  - [Computer Vision Assignments](#computer-vision-assignments)
  - [Deep Learning Assignments](#deep-learning-assignments)
  - [Digital Health Activity Monitoring Project](#digital-health-activity-monitoring-project)
  - [Dilute Solute Diffusion Ev Prediction Project](#dilute-solute-diffusion-ev-prediction-project)
  - [Reinforcement Learning Assignments](#reinforcement-learning-assignments)
  - [Reinforcement Learning Project](#reinforcement-learning-project)
  - [SNLP Toxicity Project](#snlp-toxicity-project)
  - [Evaluating Language Models for Generating and Judging Programming Feedback](#evaluating-language-models-for-generating-and-judging-programming-feedback)
  - [Neuromorphic Multisensory Numerosity Perception Enhanced by a Tactile Glove](#neuromorphic-multisensory-numerosity-perception-enhanced-by-a-tactile-glove)
  - [SQL Dairy Farm Project](#sql-dairy-farm-project)
  - [Statistical Natural Language Processing Assignments](#statistical-natural-language-processing-assignments)
  - [Used Car Price Prediction Project](#used-car-price-prediction-project)
  - [Disclaimer](#disclaimer)

---

## Advanced Computer Graphics Assignments
- **Focus Areas**: Shader programming, physically based rendering, and GPU optimization.
- **What I Did**: I implemented shader code for realistic lighting, built acceleration structures such as Bounding Volume Hierarchies (BVHs) for efficient ray tracing, and integrated multithreading to significantly speed up rendering. My work demonstrates the use of modern graphics APIs to produce high-quality visuals while managing complex rendering pipelines.

---

## Advanced Probabilistic Methods Assignments
- **Focus Areas**: Bayesian inference, Markov Chain Monte Carlo (MCMC) techniques, and hierarchical models.
- **What I Did**: I developed probabilistic models using advanced statistical methods. The assignments combined theoretical analysis with practical Python implementations, yielding robust uncertainty estimates and showcasing the power of modern probabilistic tools in real-world applications.

---

## C++ Tower Defense Project
- **Project Structure**:  
  - **`src/`**: Contains the main source files where the core game logic is implemented.  
  - **`libs/`**: External libraries for graphics rendering, audio management, and other dependencies.  
  - **`tests/`**: Unit tests that validate individual modules and ensure the game logic functions correctly.  
  - **`plan/`**: Design documents and initial planning notes outlining the game’s architecture and feature roadmap.  
  - **`doc/`**: Auto-generated documentation and reference materials.
- **What I Did**:  
  I designed and implemented the game using object-oriented programming principles and a CMake-based build system. Key contributions include:
  - **Game Logic**: Developing core gameplay mechanics such as enemy pathfinding, tower targeting, projectile collision detection, and resource management.
  - **Modular Architecture**: Structuring the code into distinct classes for Towers, Enemies, Projectiles, and the Game Manager to ensure scalability and maintainability.
  - **Robust Testing**: Writing comprehensive unit tests to validate critical components and guarantee reliable performance across different scenarios.
  - **Performance & Scalability**: Achieving smooth gameplay through efficient resource management and low-latency rendering.

---

## Computer Graphics Assignments
- **Focus Areas**: 2D/3D transformations, rasterization, basic lighting, and texture mapping.
- **What I Did**: I implemented essential transformation matrices, built lighting models, and applied texture mapping techniques. These projects provided a solid foundation for understanding advanced rendering, setting the stage for more complex GPU-based optimizations later on.

---

## Computer Vision Assignments
- **Focus Areas**: Image processing, feature extraction, object recognition, and deep learning-based vision techniques.
- **What I Did**: I developed algorithms for filtering, edge detection, and segmentation. Later assignments incorporated deep neural networks for object recognition and feature extraction, combining classical methods with modern deep learning approaches to achieve competitive performance.

---

## Deep Learning Assignments
- **Focus Areas**: Neural network architectures (MLPs, CNNs, RNNs, Transformers), optimization, and regularization.
- **What I Did**: I built models from scratch using both NumPy and PyTorch. These assignments involved designing network architectures, training with various optimization strategies, and implementing dropout and batch normalization. The projects highlight my ability to combine theoretical knowledge with practical deep learning implementations.

---

## Digital Health Activity Monitoring Project
- **Notebooks & Data**:  
  - `Activity.ipynb`: Exploratory data analysis and basic machine learning on human activity data.
  - `dailyActivity_merged.csv`: Consolidated dataset of daily activity metrics.
- **What I Did**: I performed extensive exploratory data analysis on wearable sensor data, built predictive models to assess activity levels, and extracted insights for personalized healthcare applications.

---

## Dilute Solute Diffusion Ev Prediction Project
- **Notebooks & Files**:  
  - Detailed notebooks covering data preprocessing, feature engineering, and predictive modeling.
- **What I Did**: I engineered features from experimental data and applied regression techniques to predict diffusion metrics. The decision tree model outperformed polynomial regression, underscoring the importance of proper model selection and data preprocessing.

---

## Reinforcement Learning Assignments
- **Focus Areas**: Value-based methods, policy-based methods, and deep RL.
- **What I Did**: I developed and trained RL agents using techniques such as Q-learning and policy gradients. These assignments provided hands-on experience with exploration–exploitation trade-offs and reward maximization in simulated environments.

---

## Reinforcement Learning Project
- **Task Description**: Optimize the behavior of a sanding robot to selectively sand designated areas while avoiding painted zones.
- **What I Did**:  
  - Built and customized a 2D sanding environment (using `sanding.py`).
  - Implemented a base DDPG algorithm and extended it with LNSS to boost performance.
  - Developed training loops, logging, and visualization utilities to monitor performance across multiple difficulty levels.
- **Performance**: The enhanced algorithm showed robust improvements in cumulative reward, especially in moderate and difficult environments, as demonstrated through systematic evaluations.

---

## SNLP Toxicity Project
- **File**: `Group5SNLP_Final_Report.pdf`
- **What I Did**:  
  I collaborated on a project focused on detecting toxicity in social media posts. The project involved:
  - Extensive data preprocessing (cleaning, normalization, tokenization) on large-scale textual datasets.
  - Designing and training transformer-based encoder models paired with a multilayer perceptron classifier to differentiate toxic from non-toxic language.
  - Conducting rigorous evaluations using metrics such as accuracy, precision, recall, and F1 score.
  - Comparative experiments to assess both open-source and proprietary language models for automated content moderation.
- **Outcome**: The findings provided valuable insights into model biases and demonstrated that open-source LLMs are viable alternatives for achieving high-quality automated toxicity detection.

---

## Evaluating Language Models for Generating and Judging Programming Feedback
- **File**: `ELMfGaJPF.pdf`
- **What I Did**:  
  I helped to evaluate various language models for their ability to generate and assess programming feedback. This involved:
  - Implementing an evaluation protocol using human-annotated grading criteria (e.g., explanation accuracy, clarity, and fix selectivity).
  - Comparing outputs from both open-source and proprietary models to identify strengths and weaknesses.
- **Outcome**: The study demonstrated that top open-source models can rival proprietary ones in generating high-quality feedback, supporting their adoption in educational settings.

---

## Neuromorphic Multisensory Numerosity Perception Enhanced by a Tactile Glove
- **Files**: `IEEE.docx`
- **What I Did**:  
  I contributed to a research project developing a tactile glove equipped with MXene-based pressure sensors to enhance neuromorphic numerosity perception. Key contributions include:
  - Designing the tactile glove and integrating 10 flexible pressure sensors on the finger joints for gesture recognition.
  - Capturing tactile response patterns corresponding to American Sign Language numbers.
  - Training an artificial neural network (ANN) to classify tactile patterns, achieving high accuracy even under varying noise levels.
  - Integrating tactile data with visual and auditory inputs to simulate multisensory integration, which significantly improved overall numerosity perception accuracy.
- **Outcome**: This work demonstrates that multisensory integration can markedly enhance performance over unisensory approaches, paving the way for advanced applications in robotics and human–machine interaction.

---

## SQL Dairy Farm Project
- **Project Structure**:  
  - **`code/`**: Scripts for interacting with the database.
  - **`data/`**: Raw data files for populating the database.
  - **`database/`**: Schema definitions, SQL queries, and stored procedures.
- **What I Did**:  
  I designed a relational database to simulate dairy farm management. This involved:
  - Creating a robust database schema.
  - Implementing data import procedures.
  - Developing complex queries to analyze production metrics, resource usage, and operational efficiency.
- **Outcome**: The project demonstrates effective database design and query optimization strategies in a real-world simulation.

---

## Statistical Natural Language Processing Assignments
- **Focus Areas**: Text preprocessing, n-gram and neural language modeling, named entity recognition, and topic modeling.
- **What I Did**: I implemented comprehensive NLP pipelines that include tokenization, normalization, and clustering. These assignments blend classical statistical methods with modern NLP techniques to achieve robust text analysis.

---

## Used Car Price Prediction Project
- **Notebooks & Data**:  
  - `Cars.ipynb`: Data cleaning, exploratory analysis, and initial regression modeling.
  - Additional notebooks document advanced model building and feature engineering.
- **What I Did**:  
  I conducted iterative feature selection, hyperparameter tuning, and model comparisons to predict used car prices. The decision tree regression model provided superior performance over polynomial regression, underscoring the importance of model selection and robust data preprocessing.
- **Outcome**: The project highlights the value of systematic experimentation and careful model tuning in achieving accurate price predictions.

---

## Disclaimer
In order to adhere to academic integrity standards, **full assignment code is intentionally omitted** from this repository. The materials provided here serve only as a high-level reference to my work, outlining my approaches, methodologies, and key outcomes. If you have any questions regarding specific implementations or wish to see particular code snippets, please feel free to reach out.

---

Thank you for visiting my portfolio! If you have any questions, suggestions, or would like to collaborate, please contact me at smashraf2020@gmail.com.
