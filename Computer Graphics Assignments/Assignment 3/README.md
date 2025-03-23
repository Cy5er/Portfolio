# Computer Graphics – Assignment 3: Hierarchical Modeling and Animation

## Table of Contents
- [Computer Graphics – Assignment 3: Hierarchical Modeling and Animation](#computer-graphics--assignment-3-hierarchical-modeling-and-animation)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements](#requirements)
    - [R1: Joint-to-World Transformations](#r1-joint-to-world-transformations)
    - [R2: Rotating the Joints](#r2-rotating-the-joints)
    - [R3: Visualizing Joint Frames \& Bones](#r3-visualizing-joint-frames--bones)
    - [R4: Skeletal Subspace Deformation (SSD)](#r4-skeletal-subspace-deformation-ssd)
    - [R5: Skinning Normals](#r5-skinning-normals)
  - [Implementation Highlights](#implementation-highlights)
  - [Controls \& Features](#controls--features)
  - [Screenshots \& Results](#screenshots--results)

---

## Overview
This assignment explores **hierarchical modeling** and **skeletal animation**, culminating in:
1. Building a **joint-based skeleton** where each joint’s transform is defined relative to its parent.  
2. Implementing **skeletal subspace deformation (SSD)**, attaching a skinned mesh to the skeleton so it deforms as the skeleton moves.  

By the end, we can view and pose the skeleton in multiple modes (skeleton-only vs. full skinned mesh), animate its joints with Euler angles, and see the resulting deformations.

---

## Requirements

### R1: Joint-to-World Transformations
- **Goal**: Construct a hierarchical traversal that computes each joint’s world-space transform (`joint_to_world`), given:
  - A **root** joint (index 0) with no parent.
  - Child joints that inherit transformations from their parent.  
- **Approach**:
  1. Implement a recursive function that multiplies the **parent-to-world** matrix by the **joint-to-parent** matrix to produce the **joint-to-world** matrix.  
  2. For each child, repeat the process, thus building a full hierarchical chain of transforms.  
- **Outcome**: We can correctly locate every joint in world coordinates, enabling further drawing or usage in skinning.

---

### R2: Rotating the Joints
- **Goal**: Incorporate **Euler angles** from the BVH file into each joint’s local rotation, so the skeleton can be posed or animated.  
- **Approach**:
  1. For each joint, retrieve its stored Euler angles (`euler_angles`).  
  2. Determine the correct **rotation order** (`euler_order`) for applying rotations about the X, Y, or Z axes.  
  3. Build the rotation matrix (e.g., via Eigen’s `AngleAxis` or your own matrix code) and include it in the joint-to-parent matrix.  
- **Outcome**: Non-zero Euler angles cause each joint to rotate in its parent’s local coordinate system, producing a fully poseable skeleton.

---

### R3: Visualizing Joint Frames & Bones
- **Goal**: Clearly depict the skeleton’s structure by drawing:
  1. **Coordinate axes** at each joint (small X/Y/Z lines).
  2. **Bones** that connect each joint to its parent.  
- **Approach**:
  - Use an immediate-mode drawing library (e.g., Im3d).  
  - For each joint, draw lines for its local axes in red/green/blue, then draw a line from this joint to its parent.  
- **Outcome**: A well-visualized skeleton with local orientations visible, aiding debugging and confirming correct rotations.

---

### R4: Skeletal Subspace Deformation (SSD)
- **Goal**: Deform a skinned mesh according to the skeleton’s current pose.  
- **Approach**:
  1. Compute and store **bind-to-joint** transforms (`B^-1`) once the skeleton is in its bind pose.  
  2. Each frame, compute the **bind-to-current** transformations by combining the skeleton’s **joint-to-world** matrix with the inverse bind matrix.  
  3. For each vertex (with associated bone weights), blend its transformed positions using the appropriate joint transforms.  
- **Outcome**: The mesh deforms in real time to match the skeleton’s pose, reflecting every animated rotation or translation.

---

### R5: Skinning Normals
- **Goal**: Ensure the **vertex normals** also deform correctly, enabling realistic lighting.  
- **Approach**:
  1. Treat the normals as vectors (not points) and transform them by each joint’s **3×3 rotation** (or by the inverse transpose if you want more precision).  
  2. Blend the resulting normals with the same weights used for positions.  
  3. Normalize the final normals per vertex.  
- **Outcome**: The character’s surface lighting remains consistent as limbs move, preventing shading artifacts.

---

## Implementation Highlights
- **Joint Hierarchy & Recursion**: A single function that traverses each joint’s children.  
- **Euler Angles**: Proper handling of rotation order is critical, since BVH can define a different order per joint.  
- **Bone Weights**: Each vertex has multiple joint influences, aggregated via linear blend (SSD).  
- **Normals**: Skinning directions as well as positions is vital to preserve realistic shading.

---

## Controls & Features
- **Draw Mode**:  
  1. **Skeleton** — Renders a wireframe skeleton (joints + bones).  
  2. **CPU SSD** — Renders the skinned mesh deformed on the CPU.  
  3. **GPU SSD** — (Optional extra credit) Renders skinned mesh using vertex shaders.  
- **Draw Joint Frames**: Toggles rendering of local coordinate axes.  
- **Animate (SPACE)**: Toggles BVH-based animation playback.  
- **Playback Speed Slider**: Adjusts the animation playback factor (e.g., 1x speed, 0.5x slow motion, etc.).  
- **Bone Selection & Rotation**:  
  - **Q/W**: Switch selected bone.  
  - **Arrow keys / PgUp / PgDn**: Adjust the selected bone’s Euler angles.  
  - **R**: Reset selected bone’s angles to zero.  
- **Mouse**:  
  - **Left**: Rotate the camera.  
  - **Right**: Move camera forward/backward.  
  - **Middle**: Pan camera up/down.

---

## Screenshots & Results

1. **Skeleton Mode**  
   ![Screenshot 1: Skeleton Mode (BVH File)](Screenshot%202025-03-23%20132800.jpg)

2. **Posing the Skeleton**  
   ![Screenshot 2: Posed Skeleton](Screenshot%202025-03-23%20132818.jpg)

3. **Skinned Model**  
   ![Screenshot 3: Skinning in Action](Screenshot%202025-03-23%20132830.jpg)


In these images, you can see:
- **Joint axes** drawn in red, green, and blue.  
- **Posable limbs** with Euler-angle controls or animation.  
- **Skinned** and **colored** mesh morphing to match the skeleton’s joints.