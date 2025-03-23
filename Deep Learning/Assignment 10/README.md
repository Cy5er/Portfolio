# Deep Learning – Assignment 10: PixelNet for Image Generation

## Table of Contents
- [Deep Learning – Assignment 10: PixelNet for Image Generation](#deep-learning--assignment-10-pixelnet-for-image-generation)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Objectives](#objectives)
  - [Methodology](#methodology)
    - [Data Preprocessing](#data-preprocessing)
    - [Model Architecture](#model-architecture)
    - [Training Procedure](#training-procedure)

---

## Overview
In Assignment 10, we implement PixelNet, an autoregressive model for image generation. PixelNet learns to generate images by modeling the joint distribution of pixels sequentially. The model uses masked convolutional layers, residual connections, and normalization techniques to predict pixel values one by one, ensuring that each pixel is generated conditioned on previously generated pixels.

---

## Objectives
- Develop an autoregressive model (PixelNet) for image generation.
- Learn to model the joint distribution of pixel intensities using masked convolutions.
- Train the model to generate high-quality images from random noise.
- Evaluate the performance through visual inspection of generated samples and analysis of training loss.

---

## Methodology

### Data Preprocessing
- **Data Loading**: Load an image dataset (e.g., CIFAR-10 or MNIST).
- **Normalization**: Scale pixel values to a suitable range (e.g., [0, 1] or [-1, 1]).
- **Resizing**: Resize images if necessary to a fixed dimension.
- **Batching**: Organize the images into batches for efficient training.

### Model Architecture
- **Masked Convolutions**: Use masked convolutional layers to ensure that the prediction for each pixel depends only on previously generated pixels.
- **Residual Connections**: Incorporate residual connections to improve gradient flow and stabilize training.
- **Normalization**: Apply normalization (e.g., batch normalization) to facilitate convergence.
- **Output Layer**: Produce a probability distribution over pixel intensities for each pixel, enabling autoregressive sampling.

### Training Procedure
- **Loss Function**: Use cross-entropy loss between predicted pixel distributions and actual pixel values.
- **Optimizer**: Train using the Adam optimizer with a tuned learning rate.
- **Training Loop**: Iterate over epochs, update model weights via backpropagation, and monitor training loss.
- **Generation**: During evaluation, generate images by sequentially sampling pixel values from the predicted distributions.
