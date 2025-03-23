# Computer Vision – Assignment 11

## Table of Contents
- [Computer Vision – Assignment 11](#computer-vision--assignment-11)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Tasks](#requirements--tasks)
    - [Part 1: Manual Correspondence Annotation](#part-1-manual-correspondence-annotation)
    - [Part 2: Camera Projection Matrix Estimation](#part-2-camera-projection-matrix-estimation)
    - [Part 3: Triangulation \& Distance Estimation](#part-3-triangulation--distance-estimation)
  - [Implementation Highlights](#implementation-highlights)
  - [Results \& Visualizations](#results--visualizations)

---

## Overview
In **Assignment 11**, we focus on **camera calibration** and **3D reconstruction** from multiple views of a known scene. By selecting corresponding points in two images, we estimate projection matrices, triangulate 3D points, and use these reconstructions for metric evaluation. This is foundational for tasks in multi-view geometry, photogrammetry, and structure-from-motion.

---

## Requirements & Tasks

### Part 1: Manual Correspondence Annotation
- **Goal**: Select and label 2D image points that correspond to the same 3D point across both views.  
- **Approach**:
  1. Use two images of a bookshelf scene.
  2. Select key feature points (e.g., book corners, checkerboard corners).
  3. Label points consistently across both images (e.g., `a`, `b`, ..., `h`).  
- **Outcome**: A set of annotated correspondences forming the basis for later calibration.

---

### Part 2: Camera Projection Matrix Estimation
- **Goal**: Estimate the camera projection matrices using point correspondences.  
- **Approach**:
  1. Use Direct Linear Transform (DLT) or a normalized method to compute projection matrices \( P_1 \), \( P_2 \).
  2. Optionally visualize errors between true and reprojected points.
- **Outcome**: Accurate camera projection matrices for both views.

---

### Part 3: Triangulation & Distance Estimation
- **Goal**: Recover 3D structure and evaluate real-world measurements.  
- **Approach**:
  1. Use triangulation from projection matrices and 2D point correspondences.
  2. Compute Euclidean distances between 3D points to estimate physical measurements (e.g., book dimensions).
- **Outcome**: A 3D point cloud and rough metric estimations demonstrating reconstruction quality.

---

## Implementation Highlights
- **Projection Estimation**:
  - Manual point annotation avoids the need for feature detectors, giving ground-truth precision.
  - The projection matrix recovers camera geometry up to scale.
- **Triangulation**:
  - Utilized linear triangulation methods.
  - Handled noisy measurements by reprojecting and visualizing error.
- **Distance Evaluation**:
  - Selected pairs of points with known real-world distances.
  - Evaluated consistency between images and triangulated coordinates.

---

## Results & Visualizations

1. **Annotated Input Images**  
   ![Input Images](Screenshot%202025-03-23%20194756.jpg)  
   *Images 1 and 2 with selected keypoints labeled (a–h). These corners serve as reliable correspondences.*

2. **Projection Error Visualization**  
   ![Projection Errors](Screenshot%202025-03-23%20194826.jpg)  
   *Reprojected point errors are shown using red crosses, comparing original vs. reprojected locations.*

3. **Book Measurement Points**  
   ![Book Corner Annotations](Screenshot%202025-03-23%20194837.jpg)  
   *Corners of the book (l–m, h–m) are used to estimate 3D distances and validate triangulated points.*
