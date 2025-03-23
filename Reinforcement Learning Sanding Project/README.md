# Reinforcement Learning – Project: Optimizing a Sanding Robot

## Table of Contents
- [Reinforcement Learning – Project: Optimizing a Sanding Robot](#reinforcement-learning--project-optimizing-a-sanding-robot)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Learning Objectives](#learning-objectives)
  - [Project Description](#project-description)
  - [Implementation Details](#implementation-details)
    - [Environment and Task Setup](#environment-and-task-setup)
    - [Algorithm Selection and Base Implementation](#algorithm-selection-and-base-implementation)
    - [Algorithm Extension](#algorithm-extension)
    - [Training, Testing, and Logging](#training-testing-and-logging)
  - [Performance and Results](#performance-and-results)
  - [Conclusion](#conclusion)

---

## Overview
In this project, I optimized the behavior of a sanding robot using reinforcement learning. The robot must learn to navigate a 2D plane where it is rewarded for sanding designated “sanding areas” (green zones) and penalized for contacting “painted areas” (red zones). I implemented a deep reinforcement learning agent using either PPO or DDPG (in this case, I opted for DDPG and then extended it with additional enhancements). The notebook integrates the full pipeline: environment setup, agent implementation, training, evaluation, and performance visualization.

---

## Learning Objectives
- Transition to an independent, project-based approach by designing and implementing an RL agent for a novel task.
- Choose an appropriate RL method (DDPG) based on previous exercises and extend it for improved performance.
- Understand and implement key components of the RL pipeline: environment construction, agent training, and evaluation using standardized logging and plotting utilities.
- Compare baseline and enhanced versions of the algorithm through rigorous testing in multiple difficulty environments.

---

## Project Description
The sanding task requires the robot to:
- Operate on a 2D plane with a defined state space that includes its own position, positions of sanding areas, and positions of painted areas.
- Execute continuous actions represented by target coordinates \((a_x, a_y)\) to which a PD-controller attempts to move the robot.
- Receive rewards based on its performance: positive rewards for sanding unsanded areas and negative rewards for touching painted areas.
- Adapt to varying task difficulties (easy, moderate, difficult) that change the number and positions of sanding and painted areas.

---

## Implementation Details

### Environment and Task Setup
- **Environment Construction**: I used the provided `sanding.py` file to instantiate a custom environment. The state is represented as a vector containing the robot’s coordinates along with lists of sanding and no-sanding area coordinates.
- **Visualization**: The notebook includes code to render the environment (with colored circles for sanding and painted areas) and display the robot’s movement. This helped in debugging the PD-controller behavior (noticing overshoots and gradual movement).

### Algorithm Selection and Base Implementation
- **Base Algorithm**: I chose to implement DDPG as the base algorithm for continuous action spaces. The code in the notebook shows:
  - Initialization of the DDPG agent using configurations loaded from the `cfg` directory.
  - Definition of the actor and critic networks, along with the Gaussian exploration noise (with a standard deviation of 0.3).
  - Integration of experience replay, target networks, and soft updates.
- **Training Code**: The training loop in the notebook iterates over episodes, collects transitions, and updates the networks using gradient descent. It logs episode lengths and cumulative rewards into a CSV file.

### Algorithm Extension
- **Extension Implementation**: To improve performance, I extended the base DDPG algorithm by implementing LNSS (a variant that uses N-step bootstrapping to reduce Q-value variance). This extension is contained in `algo/ddpg_extension.py`.
  - I modified the reward estimation to compute a surrogate reward over N steps.
  - Additional code ensures that the extension integrates seamlessly with the base training loop.
  - I also answered a set of multiple-choice questions regarding the extension methodology.
- **Performance Improvements**: The extended DDPG (DDPGExtension) demonstrated improved performance, particularly in the more challenging ‘middle’ and ‘difficult’ environments.

### Training, Testing, and Logging
- **Training Execution**: The notebook contains code blocks that:
  - Set the `skip_training` flag (set to False during experimentation and True for final submission).
  - Train the agent across three difficulty levels (easy, middle, difficult) using different random seeds ([0, 1, 2]).
  - Save model weights, logs, and training videos into predefined directory structures (e.g., `results/SandingEnvDifficult/ddpg_extension/model/model_parameters_X.pt`).
- **Testing and Evaluation**: After training, the agent is evaluated using a standardized `test` function that computes average episode rewards. Comparison plots are generated using utility functions from `utils/common_utils.py`.

---

## Performance and Results
- **Training Performance**: The extended DDPG algorithm (DDPGExtension) was trained in the difficult environment and achieved steadily increasing average episode rewards over 5000+ episodes. Loss curves indicated that the training was stable, and the agent’s performance improved over time.
- **Testing Metrics**: Average test rewards and episode lengths were computed, and the performance of the extended algorithm was compared with baseline metrics. The performance differences were evaluated using statistical tests (t-tests) to ensure no significant difference or to confirm improvements.
- **Visualizations**: 
  - Training curves were plotted for each environment and random seed, showing convergence trends.
  - Comparison plots were generated to illustrate the performance gap between the original and extended DDPG algorithms.
  - Training logs and model weights were saved for further analysis and evaluation.

---

## Conclusion
This reinforcement learning project successfully optimizes the behavior of a sanding robot using an extended DDPG algorithm. The project demonstrates:
- A complete RL pipeline from environment setup to agent training and evaluation.
- The effectiveness of the LNSS extension in improving performance over the base DDPG algorithm.
- Robust performance across multiple difficulty levels, verified by statistical tests and visualized training curves.