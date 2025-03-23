# Computer Vision – Assignment 6

## Table of Contents
- [Computer Vision – Assignment 6](#computer-vision--assignment-6)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Tasks](#requirements--tasks)
    - [Part 1: Advanced Feature Matching](#part-1-advanced-feature-matching)
    - [Part 2: Multi-Image Stitching \& Alignment](#part-2-multi-image-stitching--alignment)
    - [Part 3: Blending \& Final Panorama](#part-3-blending--final-panorama)
  - [Implementation Highlights](#implementation-highlights)
  - [Results \& Visualizations](#results--visualizations)

---

## Overview
In **Assignment 6**, we push further into **panoramic stitching** techniques. Building on previous feature-based methods, we now:
1. Handle **multiple images** beyond a single pair, ensuring a continuous stitching pipeline.  
2. Explore **enhanced feature matching** to accommodate viewpoint changes.  
3. Perform final **blending** to create a cohesive panorama.

---

## Requirements & Tasks

### Part 1: Advanced Feature Matching
- **Goal**: Reliably match features across multiple overlapping images.  
- **Approach**:
  1. Detect keypoints (e.g., SIFT, ORB) for each image.  
  2. Match descriptors pairwise (image 1 ↔ 2, image 2 ↔ 3, etc.) using mutual nearest neighbors or Lowe’s ratio test.  
  3. Filter out spurious matches using a robust approach (RANSAC) to ensure geometric consistency.  
- **Outcome**: A set of accurate correspondences connecting consecutive images to unify them in a common frame.

---

### Part 2: Multi-Image Stitching & Alignment
- **Goal**: Estimate transformations (homographies) that map each image into a shared coordinate system.  
- **Approach**:
  1. For each adjacent pair (and possibly a “central” reference), compute a homography \(H_{i\to ref}\).  
  2. Warp images into the reference image’s plane or a chosen global coordinate system.  
  3. Compose or mosaic these warped images together, ensuring minimal overlap mismatch.  
- **Outcome**: A wider field-of-view composite spanning multiple images.

---

### Part 3: Blending & Final Panorama
- **Goal**: Create a visually seamless panorama from all aligned images.  
- **Approach**:
  1. Crop or rectangularly bound each warped image to remove black regions if desired.  
  2. Use a blending approach (linear feathering or multi-band blending) on overlapping regions.  
  3. Output a final panorama that transitions smoothly between images.  
- **Outcome**: A final mosaic that captures the entire scene without noticeable stitching boundaries.

---

## Implementation Highlights
- **Feature Matching**:  
  - Possibly improved methods for wide-baseline or large viewpoint changes (e.g., rootSIFT or more robust matching thresholds).  
  - Ensuring each consecutive image obtains enough matches for stable alignment.
- **Global Alignment**:  
  - A “central” or first image acts as anchor; subsequent images transform relative to it.  
  - Minimizing cumulative errors by carefully verifying matches.
- **Blending**:
  - Handling more than two images with overlapping transitions.  
  - Possibly employing a seam-finding algorithm or a multi-step fade to reduce edge artifacts.

---

## Results & Visualizations

1. **Input Images**  
   ![Input images](Screenshot%202025-03-23%20194115.jpg)  
   *Three distinct shots with overlapping fields of view to be stitched into a single panorama.*

2. **Feature Matches**  
   ![Feature matches between pairs](Screenshot%202025-03-23%20194152.jpg)
     ![Final Multi-Image Panorama](Screenshot%202025-03-23%20194205.jpg)    
   *Colored lines represent consistent matches across pairs (img1↔img2, img2↔img3). Outliers removed by RANSAC for geometry consistency.*

3. **Warped & Stitched Result**  
   ![Final Multi-Image Panorama](Screenshot%202025-03-23%20194218.jpg)  
   *Images are transformed into a common coordinate system, then blended. The final panorama shows an extended scene coverage with minimal seams.*