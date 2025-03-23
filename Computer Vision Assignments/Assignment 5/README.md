# Computer Vision – Assignment 5

## Table of Contents
- [Computer Vision – Assignment 5](#computer-vision--assignment-5)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Tasks](#requirements--tasks)
    - [Part 1: Edge Detection \& Canny Operator](#part-1-edge-detection--canny-operator)
    - [Part 2: Line Fitting with RANSAC](#part-2-line-fitting-with-ransac)
    - [Part 3: Hough Transform for Lines](#part-3-hough-transform-for-lines)
  - [Implementation Highlights](#implementation-highlights)
  - [Results \& Visualizations](#results--visualizations)

---

## Overview
In **Assignment 5**, we dive deeper into **edge-based methods** in computer vision. We cover:
1. **Edge Detection** with the Canny operator or others.  
2. **RANSAC** for robust line fitting when data contains outliers.  
3. **Hough Transform** to detect multiple lines in complex scenes.

---

## Requirements & Tasks

### Part 1: Edge Detection & Canny Operator
- **Goal**: Locate significant edges in an image.  
- **Approach**:
  1. Convert to grayscale if needed, apply Gaussian smoothing to reduce noise.  
  2. Use **Canny** edge detection (or other methods) to highlight sharp intensity transitions.  
  3. Adjust thresholds (low/high) for controlling edge sensitivity.  
- **Outcome**: A binary edge map capturing the main contours of objects or structures.

---

### Part 2: Line Fitting with RANSAC
- **Goal**: Fit a line (or lines) to 2D data with outliers.  
- **Approach**:
  1. Implement **RANSAC**: random sampling of minimal points to estimate line parameters.  
  2. Check how many points lie within a threshold distance to form an inlier set.  
  3. Refine the model with inliers and iterate to find best line.  
- **Outcome**: A robust line fit unaffected by outliers or noise points.

---

### Part 3: Hough Transform for Lines
- **Goal**: Detect multiple prominent lines in an image using the Hough transform.  
- **Approach**:
  1. Use an **edge map** (e.g., from Canny) as input to the Hough transform.  
  2. Accumulate votes in \((\rho, \theta)\) space, identifying peaks that correspond to lines.  
  3. Draw the detected lines on the original image in distinct colors.  
- **Outcome**: Visualization of all strong lines in the scene, spanning vertical, horizontal, or diagonal orientations.

---

## Implementation Highlights
- **Canny Edge Tuning**:  
  - Balancing low/high thresholds to avoid either missing edges or adding too many spurious edges.  
- **RANSAC**:  
  - Iteration count, inlier distance threshold, and stopping criteria (e.g., fraction of inliers).  
  - Calculation of line parameters in slope-intercept form, or normal form \((\rho, \theta)\).
- **Hough Transform**:  
  - Generating the accumulator array.  
  - Peak detection to find lines above a certain threshold in votes.  
  - Handling parameter discretization for \(\rho\) and \(\theta\).

---

## Results & Visualizations

1. **RANSAC Line Fitting**  
   ![RANSAC Line Plot](Screenshot%202025-03-23%20193716.jpg)  
   *Black crosses represent data points, some with outliers. The red line is the best-fit from RANSAC, robustly ignoring outliers.*

2. **Canny Edge Detection**  
   ![Canny Edges](Screenshot%202025-03-23%20193738.jpg)  
   *Original image (top) vs. binary edge map (bottom). Edges highlight the keyboard’s outlines and keys.*

3. **Hough Transform Lines**  
   ![Hough Transform Lines](Screenshot%202025-03-23%20193748.jpg)  
   - *Hough space image (top) with bright peaks indicating strong lines.*  
   - *Detected lines drawn in multiple colors (bottom) overlaying the original keyboard image.*

Through these tasks, you will develop a practical grasp of **edge-based** feature extraction and **robust** line detection, essential for image analysis and geometric reasoning in computer vision.  
