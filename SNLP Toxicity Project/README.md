# Toxicity Detection – Group 5

## Table of Contents
- [Toxicity Detection – Group 5](#toxicity-detection--group-5)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Methods](#methods)
    - [Data Preprocessing](#data-preprocessing)
    - [Model Architecture](#model-architecture)
    - [Training and Evaluation](#training-and-evaluation)
    - [Experiments](#experiments)
  - [Results](#results)
  - [Discussion](#discussion)
  - [Conclusion](#conclusion)
  - [Division of Labor](#division-of-labor)

---

## Overview
This project focuses on developing a toxicity classification model using natural language processing techniques. The aim is to detect toxic language from online text data. Our approach leverages a transformer-based encoder to generate fixed-size representations of input sentences and a multilayer perceptron (MLP) as a binary classifier. Additionally, we experimented with text generation to produce toxic and non-toxic sentences.

---

## Methods

### Data Preprocessing
- **Dataset**: The toxicity dataset is split into training (90,000 rows), validation (11,000 rows), and test sets (12,000 rows). Each record includes an ID, a text comment, and a binary toxicity label.
- **Preprocessing Steps**:
  - Normalization: Convert text to lowercase, trim whitespace, and perform Unicode normalization.
  - Tokenization: Split text into tokens and build a vocabulary mapping words to indices.
  - Cleaning: Remove special characters and stopwords; custom stopwords were also applied to eliminate uninformative tokens.
  - Padding: Equalize sentence lengths using padding and a binary mask to distinguish actual tokens from padded values.

### Model Architecture
- **Encoder**: A transformer-based encoder (inspired by "Attention is All You Need") processes input text. It consists of multiple encoder blocks, each with a self-attention mechanism and feed-forward layers. Positional embeddings are added to capture the order of tokens.
- **Classifier (MLP)**: The encoder output is summarized (either by taking the mean of token embeddings or using a [CLS] token). This representation is fed into an MLP with fully connected layers, ReLU activations, and dropout regularization. The final output is a scalar logit, which is converted to a probability via a sigmoid function for binary classification.

### Training and Evaluation
- **Loss Function**: BCEWithLogitsLoss is used for training, with class weighting to address class imbalance.
- **Optimizer**: The Adam optimizer is applied with varying learning rates (e.g., 0.01, 0.001, 0.0001) to determine the best convergence.
- **Metrics**: Accuracy, precision, recall, and F1 score are used to evaluate model performance on the validation set.

### Experiments
- **Baseline and Variations**: Several model variations were tested:
  - Baseline transformer-encoder model.
  - Learning rate (LR) variations: 0.01, 0.001, and 0.0001.
  - MLP tuning: Varying the number of hidden layers and hidden layer sizes proportional to the embedding size.
- **Extra Experiments**:
  - An attempt to implement a CNN-based classifier for toxicity detection.
  - Experiments with text generation using a finetuned GPT-2 model to generate toxic and non-toxic sentences.
  - Efforts to incorporate detoxification techniques, though these remained experimental due to time constraints.

---

## Results
- **Classification Performance**:
  - The best performance was achieved with an LR variation at a learning rate of 0.001, reaching 92% accuracy and an F1 score of 0.89.
  - Some model variants showed identical accuracy (64%) but failed to capture toxicity, resulting in an F1 score of 0.00.
- **Text Generation**:
  - The toxic text generation outputs and non-toxic outputs indicate that the model can generate coherent sentences.
  - However, the model’s loss values (evaluation loss ≈ 3.33 and training loss ≈ 2.8) suggest there is significant room for improvement.

---

## Discussion
- **Training Data**: The relatively small training dataset (23 MB) limits model performance compared to large pretrained models.
- **Overfitting**: High training accuracy (97–99%) contrasted with lower test performance indicates potential overfitting.
- **Vocabulary Issues**: An overly large vocabulary (around 50k tokens) resulted from insufficient tokenization; implementing subword tokenization (e.g., Byte-Pair Encoding) could improve performance.
- **Future Work**: Incorporating transfer learning and data augmentation techniques would likely improve the model's robustness and accuracy.

---

## Conclusion
We developed a toxicity detection model from scratch, implementing a transformer-based encoder and an MLP classifier. Despite some challenges with overfitting and vocabulary size, the model achieved promising classification performance and produced coherent toxic and non-toxic text generation outputs. Future iterations will focus on leveraging pretrained models and enhanced preprocessing to further improve results.

---

## Division of Labor
- **Mikael Hokkanen**: Researched and implemented the encoder and overall model pipeline, tuned hyperparameters, and managed the training loop.
- **Marjaana Lahti**: Developed custom data loading, vocabulary construction, preprocessing steps, and implemented the dataloader and associated tests.
- **Syed Ashraf**: Debugged code, ensured deployment on the Aalto Triton cluster, optimized model performance, and conducted hyperparameter optimization.

---

Github link: [https://github.com/smaikkeli/snlp-toxicity](https://github.com/smaikkeli/snlp_toxicity)
