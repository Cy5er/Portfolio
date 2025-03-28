# Deep Learning – Assignment 10: PixelCNN for Image Generation

## Table of Contents
- [Deep Learning – Assignment 10: PixelCNN for Image Generation](#deep-learning--assignment-10-pixelcnn-for-image-generation)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Objectives](#objectives)
  - [Methodology](#methodology)
    - [Data Preprocessing](#data-preprocessing)
    - [Model Architecture](#model-architecture)
    - [Training Procedure](#training-procedure)

---

## Overview
In Assignment 10, we implement a PixelCNN model for image generation. The project includes two variants:
1. A standard PixelCNN that models the joint distribution of pixel intensities.
2. A conditional PixelCNN that conditions the generation process on additional information (e.g., class labels or other attributes).

The goal is to learn the pixel distribution of images and generate new samples that resemble the training data.

---

## Objectives
- Develop a generative model based on PixelCNN architecture.
- Learn to model the dependencies among pixels using masked convolutions.
- Extend the model to condition on auxiliary information for controlled generation.
- Evaluate model performance by inspecting generated samples and loss convergence.

---

## Methodology

### Data Preprocessing
- **Data Loading**: Load an image dataset (e.g., CIFAR-10 or MNIST) and preprocess the images.
- **Normalization**: Scale pixel values to a range suitable for training (e.g., [0, 1] or [-1, 1]).
- **Formatting**: Ensure the images have the correct dimensions and are arranged in batches for model training.

### Model Architecture
- **PixelCNN Base Model**:
  - Utilizes masked convolutional layers to ensure that the prediction for each pixel only depends on previously generated pixels.
  - Consists of multiple layers of masked convolutions followed by non-linear activations.
- **Conditional PixelCNN**:
  - Extends the base model by incorporating conditioning variables (such as class labels) into the network.
  - Conditioning is achieved by embedding the auxiliary information and combining it with the convolutional feature maps.
- **Output**:
  - The model outputs a probability distribution over pixel values for each pixel location, enabling sampling during image generation.

### Training Procedure
- **Loss Function**: Train the model using a cross-entropy loss between the predicted pixel distributions and the true pixel values.
- **Optimization**: Use the Adam optimizer with an appropriate learning rate.
- **Training Loop**:
  - For each epoch, feed batches of images through the model and compute the loss.
  - Update model weights via backpropagation.
- **Conditional Training**:
  - For the conditional variant, ensure the conditioning information is properly fed into the network during both training and generation.