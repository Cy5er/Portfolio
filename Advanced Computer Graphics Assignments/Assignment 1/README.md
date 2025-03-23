# Advanced Computer Graphics – Assignment 1: Accelerated Ray Tracing

## Table of Contents
- [Advanced Computer Graphics – Assignment 1: Accelerated Ray Tracing](#advanced-computer-graphics--assignment-1-accelerated-ray-tracing)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements](#requirements)
    - [R1: BVH Construction \& Traversal](#r1-bvh-construction--traversal)
    - [R2: BVH Saving \& Loading](#r2-bvh-saving--loading)
    - [R3: Simple Texturing](#r3-simple-texturing)
    - [R4: Ambient Occlusion (AO)](#r4-ambient-occlusion-ao)
    - [R5: Simple Multithreading](#r5-simple-multithreading)
  - [Implementation Highlights](#implementation-highlights)
  - [Controls \& Features](#controls--features)
  - [Screenshots \& Results](#screenshots--results)

---

## Overview
In this assignment, we transform a **naive ray tracer** into a much more efficient renderer by:
1. **Accelerating** triangle intersection with a **Bounding Volume Hierarchy (BVH)**.  
2. **Caching** the BVH to disk for quick loading.  
3. Adding **texturing** to give materials more variety.  
4. Implementing **ambient occlusion (AO)** for a subtle global illumination effect.  
5. **Multithreading** the rendering loop for faster performance on multi-core CPUs.

With these features, the ray tracer can handle significantly more complex scenes and produce richer shading.

---

## Requirements

### R1: BVH Construction & Traversal
- **Goal**: Construct a **bounding volume hierarchy** over the scene’s triangles to reduce per-ray intersection time.  
- **Approach**:
  1. **Build** a tree by splitting the triangle set recursively—either by *object median*, *spatial median*, or a more advanced partition strategy like SAH.  
  2. Each **leaf node** references a small subset of triangles; each **interior node** stores an AABB, with pointers to left/right children.  
  3. **Traverse** the BVH during ray intersection (instead of brute-forcing all triangles). Clip rays against node AABBs and only intersect leaf triangles.  
- **Outcome**: Drastically improved ray-tracing speed in scenes with large triangle counts.

---

### R2: BVH Saving & Loading
- **Goal**: Persist the BVH to disk so we only rebuild once per scene.  
- **Approach**:
  1. Write a **binary file** containing all node data (AABBs, child pointers as indexes, triangle ranges, etc.).  
  2. **Load** this file to reconstruct the tree if it already exists, skipping the expensive build step.  
  3. Ensure no **raw pointers** are stored in the file—use indices or offsets.  
- **Outcome**: Avoid repeated BVH construction for the same mesh across runs, saving significant startup time.

---

### R3: Simple Texturing
- **Goal**: Apply basic texture lookup for each triangle intersection, modulating its material color.  
- **Approach**:
  1. Interpolate texture coordinates using the **barycentric** coordinates of the intersection.  
  2. Fetch the correct **texel** from the mesh’s material/texture.  
  3. Combine this sampled color with your shading model (e.g., multiply or replace diffuse color).  
- **Outcome**: More visually interesting images without changing the geometry.

---

### R4: Ambient Occlusion (AO)
- **Goal**: Approximate global illumination by sampling how “open” each surface point is to its surroundings.  
- **Approach**:
  1. For the surface intersection point, generate random **hemisphere** directions oriented around the surface normal.  
  2. Trace a short “occlusion” ray for each direction. If it **hits** geometry, that direction is occluded; if not, it’s unoccluded.  
  3. The AO factor is the fraction of unoccluded rays.  
  4. Optionally scale final color by this factor, producing a soft shading effect that emphasizes crevices and corners.  
- **Outcome**: Creates a diffuse, softly lit appearance that hints at global lighting.

---

### R5: Simple Multithreading
- **Goal**: Accelerate per-pixel ray tracing on multi-core CPUs.  
- **Approach**:
  1. Enable OpenMP (or another threading library) in your rendering loop.  
  2. Ensure thread safety—each thread uses its own random number generator or shared data carefully.  
  3. Parallelize the scanline rendering, so each thread processes different rows of the output image.  
- **Outcome**: Substantially reduced render time on modern multi-core systems.

---

## Implementation Highlights
- **BVH Node Structure**: Each node stores an **AABB**, plus either:
  - **Leaf**: A small range of triangle indices (start/end).
  - **Interior**: Pointers to left/right child nodes.  
- **Serialization**: 
  - Write node data in a **pre-order** or **post-order** traversal. 
  - On load, reconstruct children using read node info and any stored offsets.  
- **Texture Mapping**:
  - The code base already passes barycentric coordinates from intersection routines. 
  - Convert these to *u,v* for each triangle and fetch color from a `Texture` object.  
- **Ambient Occlusion**:
  - Build a local basis from the intersection normal to direct random rays in the local hemisphere. 
  - Tally hits vs. misses to compute occlusion factor.  
- **Multithreading**: 
  - A single `#pragma omp parallel for` can yield big speedups. 
  - Each thread handles a chunk of scanlines, ensuring minimal shared-state conflicts.  

---

## Controls & Features
- **Scene/Camera**:  
  - Press **1, 2, 3** to load default sample scenes (Cornell Box, Conference Room, etc.).  
  - **WASD + Mouse**: Fly camera.  
  - **Alt + [Number]**: Save camera state. **[Number]**: Load camera state.  
- **Rendering**:  
  - **Trace Rays** (Enter): Renders the scene with current settings.  
  - **Space** / “Show Ray Tracer result”: Toggles between real-time OpenGL view and ray-traced result.  
- **Shading Modes**:  
  - **F1**: Simple “headlight” shading.  
  - **F2**: Ambient occlusion shading (uses user-defined ray count, AO radius).  
- **BVH**:  
  - Check “Try Load Hierarchy” to skip BVH rebuild if a cached file is present.  
- **Parameters**:
  - **AO rays** slider: Number of AO samples per hit.  
  - **AO ray length** slider: Max distance for occlusion rays.

---

## Screenshots & Results

1. **BVH Scene**  
   ![BVH Scene](Screenshot%202025-03-23%20133605.jpg)  

2. **Conference Scene**  
   ![Textured Sponza](Screenshot%202025-03-23%20133635.jpg)

3. **Mat Scene**  
   ![AO Example](Screenshot%202025-03-23%20133738.jpg)  

4. **Ambient Occlusion**  
   ![Multi-Core Speedup](Screenshot%202025-03-23%20133904.jpg)  
   *Soft shadows highlight corners and crevices.*

5. **Sponza Scene**  
   ![Multi-Core Speedup](Screenshot%202025-03-23%20133802.jpg)  