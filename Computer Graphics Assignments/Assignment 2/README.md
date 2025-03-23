# Computer Graphics – Assignment 2: Splines and Subdivision

## Table of Contents
- [Computer Graphics – Assignment 2: Splines and Subdivision](#computer-graphics--assignment-2-splines-and-subdivision)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements](#requirements)
    - [R1: Bézier Curves](#r1-bézier-curves)
    - [R2: B-spline Curves](#r2-b-spline-curves)
    - [R3: Subdividing a Mesh into Smaller Triangles](#r3-subdividing-a-mesh-into-smaller-triangles)
    - [R4: New Vertex Positions (Odd Vertices)](#r4-new-vertex-positions-odd-vertices)
    - [R5: Repositioning Old (Even) Vertices](#r5-repositioning-old-even-vertices)
  - [Implementation Details](#implementation-details)
  - [Controls \& Features](#controls--features)
  - [Screenshots \& Results](#screenshots--results)

---

## Overview
In **Assignment 2**, we explore two key topics:
1. **Spline Curves** (Bézier and B-splines)  
2. **Loop Subdivision** for triangle meshes  

By the end of this assignment, we generate and visualize smooth curves (2D) and then subdivide 3D meshes (e.g., the Stanford Bunny) to achieve smoother 3D surfaces.

---

## Requirements

### R1: Bézier Curves
- **Goal**: Implement piecewise cubic Bézier curves.
- **Approach**:  
  1. Write a function to tessellate a single cubic Bézier segment given four control points.  
  2. Subdivide the parameter range `[0, 1]` into intervals, evaluating `(x(t), y(t), z(t))` at each sample.  
  3. Connect consecutive segments so that the end of one segment is the start of the next.  
- **Outcome**: A chain of multiple Bézier segments yields a smooth piecewise cubic curve (shown in the UI as white lines).

---

### R2: B-spline Curves
- **Goal**: Evaluate **cubic B-splines** in a similar manner, using the B-spline basis matrix and a sliding window of control points.  
- **Approach**:  
  1. Replace the Bézier matrix with the B-spline matrix.  
  2. For each new segment, use four consecutive control points, shifting by one point at a time.  
  3. Reuse the same tessellation logic from R1—only the matrix and control point selection differ.  
- **Outcome**: A chain of B-spline segments, each smoothly joined, forming a piecewise uniform B-spline curve.

---

### R3: Subdividing a Mesh into Smaller Triangles
- **Goal**: Implement the initial stage of **Loop Subdivision** to convert each original triangle into four smaller ones.  
- **Approach**:  
  1. Identify midpoints of every edge in the mesh.  
  2. Create new vertices for these midpoints and store them in the vertex array.  
  3. Replace each old triangle with four new triangles using the old vertices and the newly created midpoints.  
- **Outcome**: Wireframe visuals show the original faces subdivided into a finer mesh. Initially, no actual smoothing has occurred (the shape remains the same until we reposition vertices).

---

### R4: New Vertex Positions (Odd Vertices)
- **Goal**: Correctly position the newly created (odd) vertices for a smoother surface.  
- **Approach**:  
  1. For each edge, gather the two endpoints (`v0`, `v1`) plus the two opposite vertices in the neighboring triangles.  
  2. Compute the new vertex position with Loop’s weighting formula.  
  3. Also compute new normals or colors (if used) using the same weights.  
- **Outcome**: Mid-edge vertices no longer lie strictly at midpoints; they shift to produce smoother subdivided surfaces.

---

### R5: Repositioning Old (Even) Vertices
- **Goal**: Smoothly reposition the *original* vertices to complete the Loop Subdivision step.  
- **Approach**:  
  1. For each original vertex, collect its neighbors (the “one-ring”).  
  2. Compute a weighted average of these neighbors plus the old vertex’s position using Loop’s formula.  
  3. If ignoring boundary conditions, skip them or handle them separately.  
- **Outcome**: Old vertices move to new positions, removing sharp corners. Repeated subdivisions converge to a smooth limit surface.

---

## Implementation Details
- **Spline Curves**  
  - Both Bézier and B-splines rely on evaluating a parametric function with four control points.  
  - Bézier moves in segments of four points (3n + 1), while B-splines shift by one control point for consecutive segments.  
  - Implementation is matrix-based (basis matrix × control vector).

- **Loop Subdivision**  
  - Maintain connectivity (edges, neighbors) so we can locate midpoints and “one-ring” neighbors.  
  - Use a map/dictionary to store new mid-edge vertices, ensuring each edge is only processed once.  
  - Create four new triangles per old triangle and apply the Loop weighting for vertex repositioning.

---

## Controls & Features
- **Curve Mode (1)**  
  - Load `.swp` files that describe Bézier/B-spline curves (control points + info).  
  - Adjust tessellation with a slider (e.g., “Tessellation steps”).  
  - View the control points (yellow/green) and final curves (white).  
- **Subdivision Mode (2)**  
  - Load an `.obj` mesh.  
  - **Increase subdivision (KP+) / Decrease subdivision (KP-)**: Step through subdivision levels.  
  - **Render wireframe (W)**: Toggle color-coded wireframe for debugging.  
  - Observe the incremental smoothing effect on the mesh (like the Stanford Bunny).

---

## Screenshots & Results

1. **Stanford Bunny - Wireframe at Initial Subdivision**  
   ![Screenshot: Bunny Wireframe](Screenshot%202025-03-23%20132341.jpg)

2. **Stanford Bunny - Higher Subdivision**  
   ![Screenshot: Bunny with More Faces](Screenshot%202025-03-23%20132403.jpg)

3. **Curve Mode - SWP File with B-spline / Bézier Curves**  
   ![Screenshot: Curve Mode](Screenshot%202025-03-23%20132419.jpg)

In these images, you can see:
- How the mesh density increases on the bunny as we press “Increase subdivision.”  
- The colored edges and faces in wireframe mode.  
- A cubic spline interface where control points (green or yellow) connect to form smooth curves (white lines).
