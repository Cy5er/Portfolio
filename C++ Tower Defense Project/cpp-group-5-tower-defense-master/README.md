# C++ Tower Defense Game – Detailed README
---

## Project Overview

This C++ Tower Defense game is an interactive application built using object-oriented programming principles and managed with a CMake-based build system. The project demonstrates scalable design, robust testing, and maintainability, serving as a practical example of applied C++ programming in game development. The game simulates a tower defense scenario where the player places towers to defend against waves of enemies following predefined paths.

---

## Project Structure

- **`src/`**  
  Contains the main source files that implement the game logic. Key components include:
  - **Game Manager**: Oversees the game loop, state updates, and rendering. It coordinates interactions between various game objects.
  - **Entity Classes**: Classes for the main game entities:
    - **Tower**: Handles targeting, shooting, and upgrading mechanisms.
    - **Enemy**: Manages enemy movement, health, and pathfinding.
    - **Projectile**: Represents bullets or other projectiles fired by towers, including collision detection.
  - **Utility Functions**: Common helper functions for mathematical operations (e.g., vector calculations) and game state management.

- **`libs/`**  
  Contains external libraries and dependencies required for the project, such as:
  - Graphics libraries for rendering.
  - Audio libraries for sound effects.
  - Other third-party libraries used for additional functionalities.

- **`tests/`**  
  Includes unit tests for validating the behavior of individual modules. These tests cover:
  - **Enemy Pathfinding**: Ensuring enemies follow the correct routes.
  - **Collision Detection**: Verifying that projectiles correctly detect collisions with enemies.
  - **Tower Targeting Logic**: Confirming that towers select and engage the appropriate targets.
  - **Game Loop Stability**: Testing that the game state updates correctly over time.

- **`plan/`**  
  Contains design documents, flowcharts, and initial planning notes that outline:
  - The overall game architecture.
  - Class diagrams and relationships.
  - Feature roadmaps and potential future enhancements.

- **`doc/`**  
  Hosts auto-generated documentation (e.g., Doxygen output) and reference materials that explain:
  - The interfaces and functions of core classes.
  - Usage guidelines and examples for extending the codebase.

- **`CMakeLists.txt`**  
  The main CMake configuration file that manages the build process. It:
  - Defines the project settings.
  - Specifies source file lists and include directories.
  - Links external libraries and sets up build targets for debugging and release configurations.

---

## Core Functionality

### Game Loop and State Management
- **Main Game Loop**:  
  The game loop is implemented in the Game Manager class. It repeatedly:
  - Processes user input (e.g., tower placements).
  - Updates the state of all game objects (e.g., enemy movements, projectile trajectories).
  - Renders the updated state to the screen.
  - Checks for win/lose conditions and handles level progression.

- **State Updates**:  
  Each frame, the game updates:
  - **Enemy Positions**: Enemies move along predefined paths. Pathfinding algorithms ensure they follow the correct route even if obstacles are present.
  - **Tower Behavior**: Towers scan for enemies within range, calculate targeting priorities, and fire projectiles.
  - **Projectile Mechanics**: Projectiles are instantiated when towers fire and are updated each frame to detect collisions with enemies.

### Object-Oriented Design
- **Modular Classes**:  
  Each game component is encapsulated in its own class:
  - **Tower Class**:  
    - Maintains properties such as firing rate, range, damage, and upgrade level.
    - Implements methods to detect enemies, compute targeting priorities, and manage shooting cooldowns.
  - **Enemy Class**:  
    - Stores health, speed, and position.
    - Implements pathfinding logic to follow waypoints.
    - Includes methods for taking damage and triggering death animations.
  - **Projectile Class**:  
    - Contains properties like velocity, damage, and trajectory.
    - Implements collision detection with enemies and triggers impact effects.
  - **Game Manager**:  
    - Coordinates updates and interactions between all entities.
    - Handles global game state, such as score and level management.

### CMake-based Build System
- **CMake Configuration**:  
  The project uses CMake to:
  - Organize source files and headers.
  - Link required external libraries.
  - Configure build types (Debug and Release) for optimal performance.
  - Facilitate cross-platform compatibility and easy integration with IDEs.

### Testing and Validation
- **Unit Testing**:  
  The `tests/` directory contains unit tests for critical functions:
  - Tests ensure that enemy pathfinding works as expected under various scenarios.
  - Collision detection tests verify that projectile-enemy interactions are handled correctly.
  - Tower targeting tests confirm that towers correctly identify and engage the highest priority targets.
- **Continuous Integration**:  
  The testing framework is integrated with the build system to run automated tests during development, ensuring code changes do not introduce regressions.

---

## Performance and Optimization

- **Smooth Gameplay**:  
  The game is designed to run smoothly with efficient resource management. Optimizations include:
  - **Efficient Collision Detection**: Using spatial partitioning techniques to reduce the number of collision checks per frame.
  - **Optimized Rendering**: Leveraging hardware acceleration through linked graphics libraries for real-time rendering.
  
- **Scalability**:  
  The modular design allows for easy addition of new features (e.g., new tower types, enemy behaviors) without affecting core functionality.
  
- **Robustness**:  
  Extensive unit tests and error handling ensure that the game maintains stable performance even under complex game scenarios.

---

## Conclusion

This project is a comprehensive demonstration of applied C++ programming in an interactive game environment. It illustrates:
- A robust and modular design using object-oriented principles.
- The use of a CMake-based build system to manage complex project dependencies.
- Thorough testing practices to ensure code reliability and maintainability.
- Practical optimizations that yield smooth gameplay and scalable performance.