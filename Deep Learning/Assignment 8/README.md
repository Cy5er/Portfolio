# Deep Learning – Assignment 8: Denoising Diffusion Probabilistic Models (DDPM)

## Table of Contents
- [Deep Learning – Assignment 8: Denoising Diffusion Probabilistic Models (DDPM)](#deep-learning--assignment-8-denoising-diffusion-probabilistic-models-ddpm)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Objectives](#objectives)
  - [Methodology](#methodology)
    - [Data Preprocessing](#data-preprocessing)
    - [Model Architecture](#model-architecture)
    - [Training Procedure](#training-procedure)
  - [Results \& Visualizations](#results--visualizations)
  - [Conclusion](#conclusion)

---

## Overview
In Assignment 8, we implement a Denoising Diffusion Probabilistic Model (DDPM) for generative modeling. This model learns to generate realistic images by reversing a forward diffusion process that gradually adds noise to the data. By training the model to denoise noisy inputs over multiple timesteps, we are able to synthesize high-quality images from random noise.

---

## Objectives
- Understand the forward diffusion process that incrementally corrupts images with noise.
- Implement the reverse diffusion process using a neural network (e.g., a U-Net architecture) that learns to denoise images.
- Train the DDPM using a noise prediction loss function.
- Generate and evaluate samples produced by the trained model.

---

## Methodology

### Data Preprocessing
- **Data Loading**: Load and normalize the image dataset.
- **Normalization**: Scale image pixel values to an appropriate range (e.g., [0, 1]).
- **Augmentation (Optional)**: Apply data augmentation techniques if necessary to improve model robustness.

### Model Architecture
- **Forward Diffusion Process**: Define a noise schedule that progressively adds Gaussian noise to the images over a fixed number of timesteps.
- **Reverse Diffusion Model**: Implement a neural network (commonly using a U-Net structure) to predict the noise component at each timestep.
  - The network takes as input the noisy image and a timestep indicator.
  - It outputs a prediction of the noise, which is used to iteratively denoise the image.
  
### Training Procedure
- **Loss Function**: Use a mean squared error (MSE) loss between the predicted noise and the actual noise added during the forward process.
- **Optimization**: Train the model using the Adam optimizer, tuning hyperparameters such as learning rate, batch size, and number of diffusion steps.
- **Training Loop**: Iterate over epochs, sampling timesteps and noisy images, and update model parameters based on the computed loss.

---

## Results & Visualizations
1. **Training Loss Curve**  
   *Plot showing the decrease in MSE loss over training epochs, indicating model convergence.*

2. **Diffusion Process Visualization**  
   *Examples of images at different noise levels during the reverse diffusion process, illustrating gradual denoising.*

3. **Generated Samples**  
   *Final generated images synthesized from random noise, demonstrating the quality and realism of the DDPM outputs.*

---

## Conclusion
The DDPM successfully learns to reverse the diffusion process, generating realistic images from random noise. The model’s performance, as evidenced by the loss curves and sample outputs, demonstrates the potential of diffusion models for generative tasks. Future work may focus on refining the noise schedule, scaling the architecture, and experimenting with alternative loss functions to further enhance sample quality.
