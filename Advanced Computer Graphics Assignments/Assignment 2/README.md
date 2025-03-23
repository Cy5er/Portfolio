# Advanced Computer Graphics – Assignment 2: Radiosity

## Table of Contents
- [Advanced Computer Graphics – Assignment 2: Radiosity](#advanced-computer-graphics--assignment-2-radiosity)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements](#requirements)
    - [R1: Integrate Your Ray Tracer](#r1-integrate-your-ray-tracer)
    - [R2: Area Light Source (Direct Irradiance)](#r2-area-light-source-direct-irradiance)
    - [R3: Radiosity (Indirect Illumination)](#r3-radiosity-indirect-illumination)
  - [Implementation Highlights](#implementation-highlights)
  - [Controls \& Features](#controls--features)
  - [Screenshots \& Results](#screenshots--results)

---

## Overview
In this assignment, we extend our existing **accelerated ray tracer** to handle **diffuse global illumination** via a simple **radiosity** method. The workflow involves:
1. Calculating **direct** lighting from an **area light source** for each vertex in the scene.  
2. Iteratively computing **indirect** bounces of light, accumulating them at vertices.  
3. Displaying final vertex-based radiosity in real time, resulting in **color bleeding** and other GI effects.

---

## Requirements

### R1: Integrate Your Ray Tracer
- **Goal**: Replace the provided binary ray tracer with your own from **Assignment 1**.  
- **Approach**:  
  1. Plug in your BVH-based ray intersection code where the starter code references the external library.  
  2. Ensure all relevant intersection details (barycentric coordinates, etc.) are available for shading.  
  3. Confirm that your code is reasonably stable and not significantly slower than the reference.  
- **Outcome**: The rest of the assignment will build on your custom ray tracer for visibility queries.

---

### R2: Area Light Source (Direct Irradiance)
- **Goal**: Compute *direct* lighting at each vertex from a **rectangular area light** in the scene.  
- **Approach**:
  1. Evaluate the **hemisphere integral** by **change of variables** to area integration on the light’s surface.  
  2. Monte Carlo sample `N` points on the light (uniform distribution).  
  3. For each sample `y`, compute:
     - The direction from vertex `x` to `y`, angles `θ`, `θ_l` on each surface, and distance `r`.  
     - **Visibility** by tracing a ray from `x` → `y`. If unoccluded, accumulate contribution.  
     - Weight by `1 / p(y)` (the PDF) and the cos factors.  
  4. Average contributions and store as **direct irradiance** at that vertex.  
- **Outcome**: Each vertex has a final color representing how much light arrives directly from the emitter.

---

### R3: Radiosity (Indirect Illumination)
- **Goal**: Compute **global diffuse illumination** by iteratively gathering indirect bounces.  
- **Approach**:
  1. After storing **direct** irradiance `E0` at all vertices, each vertex’s **bounce n** uses the *previous bounce’s* result `E(n-1)` as a light source.  
  2. For each vertex:
     - Shoot rays in a **cosine-weighted hemisphere** around the normal.  
     - Intersect with scene, find the barycentric coordinates of hit (triangle’s vertices), and **interpolate** the previous bounce’s irradiance.  
     - Convert that interpolated value to outgoing radiance via `L = (ρ * E_previous) / π`.  
     - Accumulate that result to form the new irradiance `E(n)`.  
  3. Add `E(n)` to a global result buffer to keep track of all bounces.  
- **Outcome**: After enough iterations, surfaces exhibit **indirect color bleeding**, giving a realistic diffuse GI effect.

---

## Implementation Highlights
- **Ray Tracing Integration**:  
  - Replaced external library calls with your own BVH-based intersection code.  
  - Must provide hit details (triangle ID, barycentrics, etc.) for subsequent shading steps.
- **Area Light Sampling**:  
  - Uniform sampling over the rectangular area.  
  - Compute PDF = `1 / (area_of_light)`.  
  - Ray tracer checks occlusion.  
- **Monte Carlo for Indirect**:  
  - Cosine distribution for hemisphere directions at each vertex.  
  - Retrieve the previously computed irradiance at the ray hit location, convert to radiance.  
  - Accumulate partial results, sum across multiple bounces.  
- **Vertex-Based Storage**:  
  - Each vertex keeps track of its current bounce’s irradiance plus an accumulated total.  
  - The real-time viewer updates vertex colors to reflect the progressively refined GI solution.

---

## Controls & Features
- **Camera**:  
  - **WASD** + Mouse: Navigate in the scene.  
  - Mouse wheel adjusts move speed.  
  - **Alt+Number**: Save camera & scene configuration; **Number**: Load saved config.  
- **Light Placement**:  
  - **Space**: Moves area light to current camera position & orientation.  
  - **Slider**: Adjusts area light size.  
- **Radiosity Computation**:  
  - **Enter**: Begins (or restarts) the radiosity solve.  
  - The solve runs asynchronously, updating vertex colors every half second.  
  - Separate sliders control **# of rays** for direct bounce and indirect bounces.  
- **Load/Save**:  
  - **M, O**: Load a new mesh scene or open a saved solution.  
  - **App** can also load and save the final radiosity solution to disk for reuse.  

---

## Screenshots & Results

1. **Cornell Box**  
   ![Direct Lighting Screenshot](Screenshot%202025-03-23%20134353.jpg)  

2. **Conference Scene**  
   ![One-Bounce Screenshot](Screenshot%202025-03-23%20134907.jpg)  

3. **Sponza**  
   ![Multiple Bounces Screenshot](Screenshot%202025-03-23%20135355.jpg)  
