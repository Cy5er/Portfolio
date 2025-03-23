# Computer Vision – Assignment 12

## Table of Contents
- [Computer Vision – Assignment 12](#computer-vision--assignment-12)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Tasks](#requirements--tasks)
    - [Part 1: Stereo Image Rectification](#part-1-stereo-image-rectification)
    - [Part 2: Feature Correspondence](#part-2-feature-correspondence)
    - [Part 3: Disparity Map Estimation](#part-3-disparity-map-estimation)
  - [Implementation Highlights](#implementation-highlights)
  - [Results \& Visualizations](#results--visualizations)

---

## Overview
In **Assignment 12**, we explore **stereo vision** techniques that estimate scene depth from stereo image pairs. The tasks focus on:
1. Aligning stereo image pairs for correspondence search.  
2. Extracting reliable matches using geometric constraints.  
3. Generating a **disparity map**, which inversely encodes depth.

---

## Requirements & Tasks

### Part 1: Stereo Image Rectification
- **Goal**: Warp both input images such that corresponding epipolar lines are aligned horizontally.  
- **Approach**:
  1. Manually annotate corresponding points across the stereo pair.  
  2. Estimate the fundamental matrix \(F\).  
  3. Compute rectifying homographies to warp both views into a rectified space.  
- **Outcome**: Rectified image pair with horizontally aligned correspondences.

---

### Part 2: Feature Correspondence
- **Goal**: Match points across rectified stereo images along scanlines.  
- **Approach**:
  1. Use annotated correspondences or extract dense matches via a sliding window SSD/NCC approach.  
  2. Ensure all matches lie on horizontal epipolar lines.  
  3. Store disparities (pixel differences between matched points).  
- **Outcome**: A reliable map of point correspondences usable for disparity.

---

### Part 3: Disparity Map Estimation
- **Goal**: Produce a **disparity map** representing relative scene depth.  
- **Approach**:
  1. For each pixel in the left image, search for the best matching patch along the same scanline in the right image.  
  2. Use similarity measures like SSD or NCC.  
  3. Normalize and visualize the disparity values as grayscale depth.  
- **Outcome**: A disparity image where closer objects appear lighter and farther objects appear darker.

---

## Implementation Highlights
- **Manual Correspondences**:  
  - Used manually labeled corners for robust fundamental matrix estimation.
- **Fundamental Matrix Estimation**:  
  - Utilized normalized 8-point algorithm and RANSAC filtering.
- **Dense Matching**:  
  - Performed using a local sliding window approach (block matching) over rectified scanlines.
- **Visualization**:  
  - Disparity values normalized for visual clarity in grayscale rendering.

---

## Results & Visualizations

1. **Input Stereo Pair**  
   ![Stereo Images](Screenshot%202025-03-23%20194944.jpg)  
   *Left and right views of the same scene. Minor perspective difference due to stereo setup.*

2. **Disparity Map Output**  
   ![Disparity Map](Screenshot%202025-03-23%20195011.jpg)  
   *Brighter regions are closer to the camera (e.g., the piano and bench). Darker regions are further away.*
