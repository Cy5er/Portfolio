# Subword Tokenization – Assignment 6

## Table of Contents
- [Subword Tokenization – Assignment 6](#subword-tokenization--assignment-6)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Tasks](#requirements--tasks)
    - [Part 1: Data Preprocessing and Vocabulary Analysis](#part-1-data-preprocessing-and-vocabulary-analysis)
    - [Part 2: Implementation of Subword Tokenization](#part-2-implementation-of-subword-tokenization)
    - [Part 3: Evaluation and Comparison of Tokenization Methods](#part-3-evaluation-and-comparison-of-tokenization-methods)
  - [Implementation Highlights](#implementation-highlights)

---

## Overview
In **Assignment 6**, the focus is on improving text preprocessing by implementing subword tokenization methods. Traditional word-level tokenization often leads to overly large vocabularies and problems with out-of-vocabulary words. This assignment implements and evaluates subword tokenization techniques (e.g., Byte-Pair Encoding or similar) to reduce vocabulary size and improve model robustness in downstream NLP tasks.

---

## Requirements & Tasks

### Part 1: Data Preprocessing and Vocabulary Analysis
- **Goal**: Analyze the existing vocabulary generated through word-level tokenization.
- **Approach**:
  1. Load and preprocess raw text data.
  2. Tokenize the text using traditional word-level methods.
  3. Examine vocabulary size and frequency distribution.
  4. Identify issues such as excessive vocabulary size and token fragmentation due to misspellings or slang.
- **Outcome**: A clear understanding of the limitations of word-level tokenization on the dataset.

---

### Part 2: Implementation of Subword Tokenization
- **Goal**: Implement a subword tokenization method (e.g., Byte-Pair Encoding) to address the limitations identified.
- **Approach**:
  1. Develop a subword segmentation algorithm that iteratively merges frequent token pairs.
  2. Generate a subword vocabulary with a controlled size.
  3. Tokenize the text using the new subword vocabulary.
- **Outcome**: A refined tokenization scheme that produces a smaller, more manageable vocabulary while preserving meaningful subword units.

---

### Part 3: Evaluation and Comparison of Tokenization Methods
- **Goal**: Compare the performance of word-level and subword tokenization.
- **Approach**:
  1. Quantitatively evaluate vocabulary size reduction and out-of-vocabulary rate.
  2. Qualitatively assess the tokenization results by visualizing token frequency and sample tokenizations.
  3. Analyze the impact on downstream tasks (e.g., language modeling or classification) if applicable.
- **Outcome**: Demonstrated benefits of subword tokenization in reducing vocabulary size and improving model generalization.

---

## Implementation Highlights
- **Preprocessing Pipeline**: Standard text cleaning (lowercasing, punctuation removal, whitespace normalization) is applied before tokenization.
- **Subword Algorithm**: Implemented a Byte-Pair Encoding (BPE) style algorithm that:
  - Counts frequency of adjacent token pairs.
  - Merges the most frequent pair iteratively until reaching a predefined vocabulary size.
- **Evaluation Metrics**: Compared vocabulary sizes, token coverage, and out-of-vocabulary rates before and after subword segmentation.