# Computer Graphics – Assignment 1

## Table of Contents
- [Computer Graphics – Assignment 1](#computer-graphics--assignment-1)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Assignment Breakdown](#assignment-breakdown)
    - [R1: Moving an Object](#r1-moving-an-object)
    - [R2: Generating a Simple Cone and Normals](#r2-generating-a-simple-cone-and-normals)
    - [R3: Converting Mesh Data for OpenGL](#r3-converting-mesh-data-for-opengl)
    - [R4: Loading a Mesh from File](#r4-loading-a-mesh-from-file)
  - [Implementation Highlights](#implementation-highlights)
  - [Controls \& Features](#controls--features)
  - [Screenshots \& Results](#screenshots--results)

---

## Overview
This project serves as an introduction to **3D graphics using OpenGL** and C++. The primary objectives include:
- Familiarizing ourselves with a functional build environment (CMake + Visual Studio).
- Implementing transformations to move and display 3D objects.
- Constructing a simple geometric shape (cone) in code and computing its normals.
- Converting *indexed* mesh data to a *per-vertex* format.
- Reading and displaying external 3D models (OBJ files).

---

## Assignment Breakdown

### R1: Moving an Object
- **Goal**: Add keyboard-based translation of a 3D object.  
- **Approach**:  
  1. Use a `Vector3f` to store the current translation.  
  2. Modify the model’s transformation matrix every frame based on arrow-key input.  
  3. Update the render loop to apply the translation matrix before drawing.  
- **Outcome**: Allows real-time shifting of the object in the scene along the X/Y plane (using arrow keys) and Z-axis (using PgUp/PgDn).

---

### R2: Generating a Simple Cone and Normals
- **Goal**: Generate a 3D cone (tip at origin, height = 1, base radius = 0.25) and compute flat face normals.  
- **Approach**:  
  1. Calculate positions of the cone’s triangular faces by stepping around a circle (e.g., 40 slices).  
  2. Construct triangles: (tip, base vertex i, base vertex i+1).  
  3. Compute each face’s normal using a cross product, assigning the same normal to all three vertices of that face.  
- **Outcome**: Produces a flat-shaded cone with an open base. The shape and lighting look correct under directional shading modes.

---

### R3: Converting Mesh Data for OpenGL
- **Goal**: Convert an *indexed* mesh representation (positions + normals stored separately, referenced by index) into a format where each vertex contains both position and normal directly.  
- **Approach**:  
  1. For each face (which typically references 3 vertices, each with position and normal indices), look up the corresponding data in the position/normal arrays.  
  2. Pack them into a single `std::vector<Vertex>` where each `Vertex` has `position` and `normal`.  
- **Outcome**: Allows simpler GPU rendering with each triangle specified by three consecutive vertices. Tested using a small tetrahedron example.

---

### R4: Loading a Mesh from File
- **Goal**: Import a Wavefront OBJ model and display it.  
- **Approach**:  
  1. Parse lines from the OBJ file, distinguishing vertex positions (`v`) and normals (`vn`).  
  2. Collect face information (`f` lines) that reference positions/normals by indices.  
  3. Adjust the indices (OBJ is 1-based, while C++ arrays are 0-based).  
  4. Call the function from R3 to unpack the indexed data to a final drawable vertex array.  
- **Outcome**: Successfully displays external models like `sphere.obj`, `torus.obj`, and others, with correct geometry and shading.

---

## Implementation Highlights
- **Matrix Transformations**  
  Handled within a simple transformation pipeline that composes translation with the default camera/view matrix.
- **Normals**  
  Demonstrates basic face normals (flat shading). Verified correctness using a directional light that visually indicates normal orientation.
- **OBJ Parsing**  
  Managed file I/O with `std::ifstream` and string parsing via `std::istringstream`. Replacing `/` characters with whitespace ensured that we could parse indices correctly.

---

## Controls & Features
- **Translation**  
  - **Arrow Keys**: Move the object in the XY-plane.  
  - **PgUp / PgDn**: Move the object along the Z-axis.  
- **Model Loading**  
  - **Buttons**: Load example models (e.g., a simple triangle, an indexed tetrahedron, generated cone) and optionally prompt for OBJ file loading.  
- **Shading Toggle** (`S`)  
  Switch between simple color shading and directional lighting to inspect normals.  
- **Auto Rotate** (`R`)  
  Continuously rotates the current model around the Y-axis.  
- **Trackball Mode** (`T`)  
  Enables an experimental camera rotation approach.

---

## Screenshots & Results

Below are some screenshots illustrating each main feature in action:

1. **Example Model, Basic Shading**  
   ![Screenshot 1: Example Model](Screenshot%202025-03-23%20131505.jpg)

2. **Indexed Model with Shading**  
   ![Screenshot 2: Indexed Model](Screenshot%202025-03-23%20131553.jpg)

3. **Auto Rotating**  
   ![Screenshot 3: Generated Cone](Screenshot%202025-03-23%20131603.jpg)

4. **OBJ Model (Sphere)**  
   ![Screenshot 5: Loaded Sphere OBJ](Screenshot%202025-03-23%20131645.jpg)

These illustrate the progression from a simple triangle, to an indexed tetrahedron, a generated cone, and finally a complex OBJ file (sphere).