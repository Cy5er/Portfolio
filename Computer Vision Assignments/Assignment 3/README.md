# Computer Vision – Assignment 3

## Table of Contents
- [Computer Vision – Assignment 3](#computer-vision--assignment-3)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Tasks](#requirements--tasks)
    - [Part 1: Image Noise \& Filtering](#part-1-image-noise--filtering)
    - [Part 2: Hybrid Images \& Frequency Analysis](#part-2-hybrid-images--frequency-analysis)
    - [Part 3: Image Blending \& Pyramids](#part-3-image-blending--pyramids)
  - [Implementation Highlights](#implementation-highlights)
  - [Results \& Visualizations](#results--visualizations)

---

## Overview
In **Assignment 3**, we focus on **image processing** workflows, covering:
1. **Noise injection** (salt-and-pepper, Gaussian) and **filtering** techniques to restore or smooth images.  
2. **Hybrid image** creation by combining low-frequency components of one image with high-frequency components of another.  
3. **Advanced blending** (e.g., Laplacian pyramids) to seamlessly merge image regions.

---

## Requirements & Tasks

### Part 1: Image Noise & Filtering
- **Goal**: Understand and compare different noise types and the filters that address them.  
- **Approach**:
  1. Inject *salt-and-pepper* noise and *Gaussian* noise into a base image.  
  2. Apply **Gaussian filtering**, **median filtering**, and **bilateral filtering** to remove or reduce the noise.  
  3. Compare outcomes qualitatively and quantitatively (e.g., PSNR or MSE).  
- **Outcome**: Familiarity with typical denoising filters and how they perform on distinct noise patterns.

---

### Part 2: Hybrid Images & Frequency Analysis
- **Goal**: Create a **hybrid image** by combining the low spatial frequency from one image with the high spatial frequency from another.  
- **Approach**:
  1. Fourier transform two input images (e.g., a face and an animal).  
  2. Extract low frequencies (via a low-pass filter) from the first image and high frequencies (via a high-pass filter) from the second.  
  3. Reconstruct the merged image so that it looks like one image up close and transitions to another image at a distance.  
- **Outcome**: A creative demonstration of frequency domain manipulation—revealing how different scales affect human perception.

---

### Part 3: Image Blending & Pyramids
- **Goal**: Perform advanced **image blending** for seamless transitions between two images.  
- **Approach**:
  1. Implement a **simple additive** blending approach (straight alpha blending).  
  2. Create a **Laplacian (or Gaussian) pyramid** for each image, merging them at various scales.  
  3. Compare the smoothness of transitions to the simple additive method.  
- **Outcome**: A final composite image with minimal artifacts or sharp boundaries, demonstrating multi-scale blending techniques.

---

## Implementation Highlights
- **Noise & Filters**:  
  - Implementing or using `cv2` (OpenCV) median filters, Gaussian filters, and possibly a custom bilateral filter.  
  - Observing how salt-and-pepper noise is better tackled by median filters, while Gaussian noise often benefits from Gaussian/bilateral filtering.
- **Fourier Domain**:  
  - Using `numpy.fft` to separate low/high frequency components.  
  - Careful alignment of images for hybrid image creation (identical shapes or well-chosen cutoff frequencies).
- **Image Pyramids**:  
  - Constructing Gaussian and Laplacian pyramids.  
  - Merging pyramids at each level for a smooth blended transition.  
  - Reconstructing final image from the merged pyramid.

---

## Results & Visualizations

1. **Filtering Comparisons**  
   ![Noise + Filters](Screenshot%202025-03-23%20151822.jpg)  
   *Top row: Original, “salt and pepper” noise, and “Gaussian” noise. Next columns: Gaussian/median/bilateral filtered results highlighting noise removal strengths/weaknesses.*

2. **Hybrid Image**  
   ![Hybrid Example](Screenshot%202025-03-23%20151943.jpg)  
   *Combines low-frequency details of a man’s portrait with high-frequency edges of a wolf. From far away, the image appears wolf-like; up close, it’s more like a man.*  

3. **Image Blending**  
   ![Blending Results](Screenshot%202025-03-23%20152009.jpg)  
   *A naive alpha blend vs. Laplacian pyramid. The pyramid blend yields smoother transitions with minimal seams. The difference image highlights the changes in overlapping regions.*

These steps strengthen your understanding of **spatial and frequency domain** methods in computer vision, crucial for advanced image manipulation, denoising, and blending tasks.
