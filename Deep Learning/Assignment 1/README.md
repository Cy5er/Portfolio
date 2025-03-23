# Deep Learning – Assignment 1: Multi-Layer Perceptron Implementation

## Table of Contents
- [Deep Learning – Assignment 1: Multi-Layer Perceptron Implementation](#deep-learning--assignment-1-multi-layer-perceptron-implementation)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Objectives](#objectives)
  - [Implementation Details](#implementation-details)
    - [MLP using NumPy](#mlp-using-numpy)
    - [MLP using PyTorch](#mlp-using-pytorch)
  - [Results](#results)
  - [Conclusion](#conclusion)

---

## Overview
This assignment focuses on implementing a Multi-Layer Perceptron (MLP) for a deep learning task. Two notebooks are provided:
- **`1_mlp_numpy.ipynb`**: An implementation of an MLP from scratch using NumPy, where the forward pass, loss computation, and backpropagation are manually coded.
- **`2_mlp_pytorch.ipynb`**: An implementation of an MLP using PyTorch, leveraging its built-in modules and automatic differentiation capabilities.

---

## Objectives
- Understand and implement the core components of an MLP (forward propagation, loss calculation, and backpropagation) using NumPy.
- Utilize PyTorch to build and train an MLP with a more efficient and scalable approach.
- Compare both implementations in terms of code complexity, training efficiency, and model performance.

---

## Implementation Details

### MLP using NumPy
- **Architecture**: A multi-layer network with one or more hidden layers.
- **Forward Propagation**: Manually implemented matrix multiplications, activation functions, and output layer computations.
- **Backpropagation**: Calculation of gradients and manual weight updates using gradient descent.
- **Training**: The network is trained iteratively on a dataset, with loss computed using a suitable loss function (e.g., mean squared error or cross-entropy).
- **Evaluation**: Performance metrics (accuracy or loss curves) are plotted to monitor convergence.

### MLP using PyTorch
- **Architecture**: Mirrors the NumPy implementation using PyTorch’s `nn.Module` classes.
- **Automatic Differentiation**: Utilizes PyTorch's autograd for gradient computation, simplifying backpropagation.
- **Optimization**: Employs PyTorch optimizers (e.g., Adam) for training the model.
- **Training**: The model is trained using a standard training loop, with validation metrics computed during training.
- **Advantages**: More concise code, easier debugging, and potential for GPU acceleration.

---

## Results
- The NumPy implementation provides a detailed understanding of the underlying mathematics of MLPs.
- The PyTorch implementation achieves similar or improved performance with less code and faster training times.
- Both models’ performance (e.g., training loss, validation accuracy) is visualized through plots, demonstrating successful convergence.

---

## Conclusion
This assignment demonstrates two approaches to building an MLP:
- The **NumPy-based model** is educational for learning the fundamentals of neural network training.
- The **PyTorch-based model** is more practical and scalable for real-world applications.
Overall, the exercise illustrates the trade-offs between manual implementations and modern deep learning frameworks, paving the way for further experimentation with more complex architectures.