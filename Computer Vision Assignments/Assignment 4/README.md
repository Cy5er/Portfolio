# Computer Vision – Assignment 4

## Table of Contents
- [Computer Vision – Assignment 4](#computer-vision--assignment-4)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Tasks](#requirements--tasks)
    - [Part 1: Feature Detection \& Description](#part-1-feature-detection--description)
    - [Part 2: Feature Matching \& Homography Estimation](#part-2-feature-matching--homography-estimation)
    - [Part 3: Image Stitching \& Panorama Creation](#part-3-image-stitching--panorama-creation)
  - [Implementation Highlights](#implementation-highlights)
  - [Results \& Visualizations](#results--visualizations)

---

## Overview
In **Assignment 4**, we explore **feature-based** methods in computer vision. We focus on:
1. **Detecting and describing local features** (corners, blobs) in images.  
2. **Matching** these features across multiple images to estimate a **homography**.  
3. **Building** a **panorama** or mosaic by stitching aligned images together.

---

## Requirements & Tasks

### Part 1: Feature Detection & Description
- **Goal**: Identify robust, distinctive points in images and describe them for matching.  
- **Approach**:
  1. Implement or apply detectors such as **Harris corner**, **FAST**, or **SIFT**.  
  2. Extract feature descriptors (e.g., SIFT or ORB).  
  3. Visualize detected keypoints superimposed on the images.  
- **Outcome**: A set of keypoints with descriptors enabling reliable matching between overlapping images.

---

### Part 2: Feature Matching & Homography Estimation
- **Goal**: Match features between two or more images and find a transformation (homography) to align them.  
- **Approach**:
  1. Compute pairwise distances between descriptors.  
  2. Use a **nearest-neighbor** ratio test (Lowe’s ratio) or a robust method like **RANSAC** to eliminate outliers.  
  3. Solve for the **homography matrix** \(H\) that maps points from one image coordinate system to the other.  
- **Outcome**: A robust estimate of the alignment parameters so that corresponding image planes match accurately.

---

### Part 3: Image Stitching & Panorama Creation
- **Goal**: Warp and blend multiple images into a single seamless panorama.  
- **Approach**:
  1. Use the estimated homography to **warp** the second image into the first image’s coordinate frame.  
  2. Apply a **blending** technique (feathering, multi-band blending) to reduce seams.  
  3. Output a larger mosaic or panorama.  
- **Outcome**: A wide-field composite image that appears continuous, with minimal visible transitions between the stitched images.

---

## Implementation Highlights
- **Feature Detectors/Descriptors**:  
  - Possibly from `OpenCV` (ORB, SIFT) or custom implementations (Harris).  
  - Good coverage of corner-like or blob-like structures for robust alignment.
- **Homography via RANSAC**:  
  - Iteratively fit \(H\) using minimal sets of matches; discard inliers with large reprojection error.  
  - Once stable, refine \(H\) with all inliers.
- **Warping & Blending**:  
  - `cv2.warpPerspective` (if using OpenCV) for the transformation.  
  - Feather or multi-band pyramid to smoothly merge overlapping regions.

---

## Results & Visualizations

1. **Detected Keypoints**  
   ![Keypoints Detected](Screenshot%202025-03-23%20152304.jpg)  

2. **Matched Features with RANSAC**  
   ![Matched Features](Screenshot%202025-03-23%20152317.jpg)  

3. **Best Matches**  
   ![Panorama Stitching](Screenshot%202025-03-23%20152329.jpg)  

4. **Transformed Images and Inliers**  
   ![Panorama Stitching](Screenshot%202025-03-23%20152401.jpg)

5. **NN SURF Features**  
   ![Panorama Stitching](Screenshot%202025-03-23%20152413.jpg)

6. **Matching points**  
   ![Panorama Stitching](Screenshot%202025-03-23%20152436.jpg)

7. **Detected Blobs**  
![Panorama Stitching](Screenshot%202025-03-23%20152450.jpg)

1. **Blob Detection and Matching**  
   ![Panorama Stitching](Screenshot%202025-03-23%20152436.jpg)
