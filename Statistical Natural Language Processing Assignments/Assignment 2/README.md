# N-grams Analysis Notebook – Assignment 2

## Table of Contents
- [N-grams Analysis Notebook – Assignment 2](#n-grams-analysis-notebook--assignment-2)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Objectives](#objectives)
  - [Data Loading](#data-loading)
  - [N-gram Generation](#n-gram-generation)
  - [Frequency Analysis](#frequency-analysis)
  - [Visualization](#visualization)

---

## Overview
This notebook demonstrates the extraction and analysis of n-grams from a text corpus. The workflow covers loading and preprocessing raw text data, generating various n-grams (such as bigrams and trigrams), analyzing their frequency distributions, and visualizing the most common n-grams. The analysis helps to uncover recurring word patterns and contextual relationships within the text.

---

## Objectives
- Load and preprocess raw text data.
- Generate n-grams from tokenized text.
- Compute frequency counts for different n-gram sizes.
- Visualize the distribution of common n-grams.
- Derive insights about language patterns and contextual word relationships.

---

## Data Loading
- The notebook loads text data from a source file.
- Text preprocessing includes:
  - Converting text to lowercase.
  - Removing punctuation and extraneous whitespace.
  - Tokenizing the text into individual words.

---

## N-gram Generation
- N-grams (e.g., bigrams and trigrams) are generated using a sliding window approach over the tokenized text.
- Custom functions or libraries are used to extract sequences of n consecutive tokens.
- The process allows analysis of common word pairs and triplets in the corpus.

---

## Frequency Analysis
- Frequency counts for each n-gram are computed.
- The most frequent n-grams are identified and ranked.
- This analysis quantifies how often particular word combinations occur, indicating prevalent collocations.

---

## Visualization
- Bar charts and word clouds are generated to visually represent the frequency distribution of n-grams.
- Visualizations help in easily spotting common phrases and understanding overall language patterns within the text.
