# Deep Learning – Assignment 6: Graph Neural Networks for Node Classification

## Table of Contents
- [Deep Learning – Assignment 6: Graph Neural Networks for Node Classification](#deep-learning--assignment-6-graph-neural-networks-for-node-classification)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Objectives](#objectives)
  - [Dataset](#dataset)
  - [Methodology](#methodology)
    - [Data Preparation](#data-preparation)
    - [Model Architecture](#model-architecture)
    - [Training Procedure](#training-procedure)
    - [Evaluation Metrics](#evaluation-metrics)
  - [Results \& Visualizations](#results--visualizations)
  - [Conclusion](#conclusion)

---

## Overview
In Assignment 6, a Graph Neural Network (GNN) is implemented to perform node classification on a graph-structured dataset. The model leverages both node features and graph connectivity to predict the class labels of nodes. This assignment covers the complete pipeline from data preparation and graph construction, through model design and training, to the evaluation of the model's performance.

---

## Objectives
- Represent data as a graph with nodes and edges.
- Build a GNN model that learns node representations using graph convolutional layers.
- Train the GNN for a node classification task.
- Evaluate the model using accuracy and other relevant metrics.

---

## Dataset
- **Content**: The dataset includes node features and an edge list representing the graph structure.
- **Task**: Each node is associated with a class label for classification.
- **Preprocessing**: Node features are normalized, and the graph is constructed using the provided edge information. The dataset is split into training, validation, and test sets.

---

## Methodology

### Data Preparation
- Load node features and edge lists from the dataset.
- Normalize node features to ensure consistent scaling.
- Construct the graph using a framework such as PyTorch Geometric or NetworkX.
- Split the nodes into training, validation, and testing subsets.

### Model Architecture
- **Graph Convolutional Layers**: The GNN uses graph convolutional (GCN) layers to aggregate features from neighboring nodes.
- **Activation and Dropout**: ReLU activations and dropout layers are incorporated to introduce non-linearity and mitigate overfitting.
- **Final Classification Layer**: A fully connected layer outputs logits for each node, which are then used to predict class labels via softmax.

### Training Procedure
- Train the model using cross-entropy loss for the node classification task.
- Use the Adam optimizer with tuned learning rates and batch sizes.
- Monitor performance on the validation set to prevent overfitting and adjust hyperparameters.
- Evaluate the model on the test set after training.

### Evaluation Metrics
- **Accuracy**: The primary metric to measure the classification performance.
- Additional metrics such as F1 score, precision, and recall may also be used to assess model performance, especially if the classes are imbalanced.

---

## Results & Visualizations
1. **Training Loss and Accuracy Curves**  
   *Plots demonstrating the convergence of the model during training, showing decreasing loss and increasing accuracy on the validation set.*

2. **Node Classification Performance**  
   *Confusion matrices and accuracy scores on the test set to quantify model performance.*

3. **Embedding Visualization**  
   *Optional: t-SNE or PCA plots of the learned node embeddings, illustrating clustering of nodes according to their classes.*

---

## Conclusion
The GNN model successfully learns to classify nodes by leveraging both node features and graph structure. The training process shows good convergence, and the evaluation metrics indicate effective performance on the node classification task. Future work could involve exploring deeper architectures, alternative graph convolution methods, or additional regularization techniques to further improve model performance.
