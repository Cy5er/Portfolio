# Neural Network Language Model – Assignment 5

## Table of Contents
- [Neural Network Language Model – Assignment 5](#neural-network-language-model--assignment-5)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Tasks](#requirements--tasks)
    - [Part 1: Data Preprocessing and Vocabulary Construction](#part-1-data-preprocessing-and-vocabulary-construction)
    - [Part 2: Model Architecture](#part-2-model-architecture)
    - [Part 3: Training the Language Model](#part-3-training-the-language-model)
    - [Part 4: Evaluation and Text Generation](#part-4-evaluation-and-text-generation)
  - [Implementation Highlights](#implementation-highlights)

---

## Overview
In **Assignment 5**, a Neural Network Language Model (NN-LM) is developed to learn the probability distribution of sequences of words. The project focuses on constructing a language model that can predict the next word given a sequence of previous words. The model is trained on a text corpus, and its performance is evaluated using metrics such as perplexity. Additionally, the model is used to generate sample text based on learned patterns.

---

## Requirements & Tasks

### Part 1: Data Preprocessing and Vocabulary Construction
- **Goal**: Prepare the text corpus for training.
- **Approach**:
  1. Load raw text data from a source file.
  2. Clean and normalize the text (e.g., convert to lowercase, remove punctuation).
  3. Tokenize the text into words and build a vocabulary.
  4. Encode the text as sequences of integers based on the vocabulary.
- **Outcome**: A preprocessed dataset and a vocabulary mapping that will be used for model training.

---

### Part 2: Model Architecture
- **Goal**: Define and implement the neural network architecture for the language model.
- **Approach**:
  1. Construct an embedding layer to transform input tokens into dense vectors.
  2. Use one or more hidden layers (e.g., a feed-forward neural network or an RNN variant) to learn contextual relationships.
  3. Add an output layer with a softmax function to predict the probability distribution over the vocabulary for the next word.
- **Outcome**: A neural network model that maps a sequence of word indices to a probability distribution for the subsequent word.

---

### Part 3: Training the Language Model
- **Goal**: Train the neural network language model on the preprocessed data.
- **Approach**:
  1. Split the dataset into training, validation, and test sets.
  2. Define an appropriate loss function (e.g., cross-entropy loss) and an optimizer (e.g., Adam).
  3. Train the model over multiple epochs while monitoring loss and perplexity.
- **Outcome**: A trained language model capable of capturing the statistical properties of the text corpus.

---

### Part 4: Evaluation and Text Generation
- **Goal**: Evaluate the model’s performance and generate sample text.
- **Approach**:
  1. Calculate evaluation metrics such as perplexity on the validation/test set.
  2. Generate text by providing a seed sequence and sampling from the model’s output distribution.
  3. Optionally, experiment with different sampling techniques (e.g., temperature scaling) to control randomness.
- **Outcome**: Quantitative evaluation of the model and qualitative assessment through generated text examples.

---

## Implementation Highlights
- **Preprocessing Pipeline**: The notebook includes routines for text normalization, tokenization, and vocabulary construction.
- **Neural Network Design**: The model leverages an embedding layer and one or more hidden layers to capture contextual dependencies. The output is produced using a softmax layer to form a probability distribution.
- **Training Setup**: The training loop uses cross-entropy loss and the Adam optimizer. Model performance is tracked via perplexity.
- **Text Generation**: The trained model is used to generate text samples by iteratively predicting the next word based on a given seed.
