# Deep Learning – Assignment 3: Recurrent Neural Network for Sequence Modeling

## Table of Contents
- [Deep Learning – Assignment 3: Recurrent Neural Network for Sequence Modeling](#deep-learning--assignment-3-recurrent-neural-network-for-sequence-modeling)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Objectives](#objectives)
  - [Implementation Details](#implementation-details)
    - [Data Loading and Preprocessing](#data-loading-and-preprocessing)
    - [Model Architecture](#model-architecture)
    - [Training Procedure](#training-procedure)
    - [Evaluation Metrics](#evaluation-metrics)
  - [Results](#results)
  - [Conclusion](#conclusion)

---

## Overview
This assignment focuses on building a Recurrent Neural Network (RNN) for sequence modeling tasks. The goal is to process sequential data (such as text or time series) and predict future tokens or sequence labels. Two main approaches were implemented:
1. An RNN model built from scratch using NumPy for educational purposes.
2. A more advanced RNN implementation using a deep learning framework (e.g., PyTorch) that leverages built-in modules and automatic differentiation.

---

## Objectives
- Understand and implement the core components of a Recurrent Neural Network.
- Learn how to perform sequence data preprocessing and tokenization.
- Compare a simple RNN built with NumPy to a more scalable implementation using PyTorch.
- Evaluate model performance using appropriate metrics such as loss and accuracy on validation data.

---

## Implementation Details

### Data Loading and Preprocessing
- The dataset was loaded from a text source (e.g., a CSV file or plain text).
- Text data was preprocessed by converting to lowercase, removing punctuation, and tokenizing into sequences.
- Sequences were padded to ensure uniform length across batches.
- A vocabulary was constructed from the dataset to map tokens to integer indices.

### Model Architecture
- **Simple RNN (NumPy)**:
  - Implemented the forward pass manually using recurrence relations.
  - Calculated hidden states for each time step.
  - Computed the output using a softmax function to obtain probabilities over the vocabulary.
  - Backpropagation through time (BPTT) was implemented to update the weights.
- **Advanced RNN (PyTorch)**:
  - Utilized PyTorch’s `nn.RNN` (or LSTM/GRU) modules for efficient sequence modeling.
  - The model includes an embedding layer, one or more recurrent layers, and a fully connected output layer.
  - Loss computed using cross-entropy loss, and optimized with Adam.

### Training Procedure
- The model was trained on the preprocessed sequence data.
- Training was conducted over multiple epochs with mini-batch gradient descent.
- Learning rate and batch size were tuned to optimize performance.
- The training loop included regular evaluation on a validation set to monitor loss and convergence.

### Evaluation Metrics
- Model performance was evaluated using the cross-entropy loss.
- Additional metrics (e.g., accuracy or perplexity) were computed to assess how well the model predicts the next token in the sequence.

---

## Results
- The NumPy-based RNN provided a clear understanding of the mechanics behind recurrence and backpropagation through time.
- The PyTorch RNN achieved better scalability and faster training times due to optimized computations.
- Loss curves and sample predictions indicate that the model learned meaningful sequence patterns.
- Generated sample sequences demonstrated the model's ability to capture temporal dependencies.

---

## Conclusion
This assignment successfully implemented two approaches to building an RNN for sequence modeling. The exercise enhanced understanding of RNN dynamics, sequence preprocessing, and model training techniques. The PyTorch-based model, in particular, proved to be effective and efficient, paving the way for more advanced sequence tasks such as language modeling and time-series forecasting.
