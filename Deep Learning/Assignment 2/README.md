# Deep Learning – Assignment 2: Convolutional Neural Network Architectures

## Table of Contents
- [Deep Learning – Assignment 2: Convolutional Neural Network Architectures](#deep-learning--assignment-2-convolutional-neural-network-architectures)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Objectives](#objectives)
  - [Implemented Architectures](#implemented-architectures)
    - [LeNet](#lenet)
    - [VGG](#vgg)
    - [ResNet](#resnet)
  - [Implementation Highlights](#implementation-highlights)
  - [Results \& Analysis](#results--analysis)
  - [Conclusion](#conclusion)

---

## Overview
In **Assignment 2**, we explore and implement various Convolutional Neural Network (CNN) architectures for image classification. The assignment is divided into three parts, each corresponding to a different network architecture:
- **LeNet**: A simple and classical CNN model.
- **VGG**: A deeper architecture with small convolutional filters.
- **ResNet**: A modern architecture employing residual connections to facilitate training of very deep networks.

---

## Objectives
- Compare the performance and complexity of three CNN architectures.
- Understand the key design principles behind each network (e.g., feature extraction in LeNet, depth in VGG, residual learning in ResNet).
- Evaluate and analyze the models based on training loss, accuracy, and convergence behavior.

---

## Implemented Architectures

### LeNet
- **Description**: A classical CNN with a relatively shallow architecture, originally designed for digit recognition.
- **Implementation**:
  - Consists of a couple of convolutional layers followed by pooling and fully connected layers.
  - Provides a baseline for understanding CNNs with a simple architecture.
- **Notebook**: `1_lenet.ipynb`

---

### VGG
- **Description**: A deeper network that uses small (3x3) convolutional filters and a uniform architecture.
- **Implementation**:
  - Implements multiple convolutional layers stacked sequentially, with max pooling layers interleaved.
  - The network depth allows learning more complex features compared to LeNet.
- **Notebook**: `2_vgg.ipynb`

---

### ResNet
- **Description**: A state-of-the-art CNN that incorporates residual connections to enable the training of very deep networks.
- **Implementation**:
  - Uses residual blocks that include shortcut connections to help gradients flow during backpropagation.
  - Demonstrates improved performance and faster convergence on deeper models.
- **Notebook**: `3_resnet.ipynb`

---

## Implementation Highlights
- **Data Preparation**: Standard image preprocessing steps (normalization, resizing) were applied to the dataset.
- **Model Building**: Each architecture was implemented using a deep learning framework (e.g., PyTorch or TensorFlow), following their respective design principles.
- **Training**: Models were trained using appropriate loss functions and optimizers. Training parameters such as learning rate and batch size were tuned for optimal performance.
- **Evaluation**: Performance metrics including training/validation loss and accuracy were recorded and compared across models.

---

## Results & Analysis
- **LeNet**: Served as a baseline with fast training but lower accuracy due to its shallow architecture.
- **VGG**: Showed improved accuracy over LeNet, benefiting from a deeper network with more complex feature extraction.
- **ResNet**: Achieved the best performance among the three models, demonstrating the effectiveness of residual connections in training deeper networks.
- Visualizations such as loss curves and accuracy plots were generated to compare the convergence and performance of each model.

---

## Conclusion
This assignment provided a comprehensive comparison of three CNN architectures:
- **LeNet** offers a simple, fast baseline for CNN-based image classification.
- **VGG** improves performance through depth and uniform architecture.
- **ResNet** further enhances accuracy and training stability using residual learning.
Overall, the experiments underscore the importance of network depth and architectural innovations in achieving high performance in image classification tasks.
