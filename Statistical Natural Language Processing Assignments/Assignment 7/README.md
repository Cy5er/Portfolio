# Machine Translation Evaluation – Assignment 7: BLEU Score Calculation

## Table of Contents
- [Machine Translation Evaluation – Assignment 7: BLEU Score Calculation](#machine-translation-evaluation--assignment-7-bleu-score-calculation)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Requirements \& Tasks](#requirements--tasks)
    - [Part 1: Data Loading and Preprocessing](#part-1-data-loading-and-preprocessing)
    - [Part 2: Organizing Candidate and Reference Translations](#part-2-organizing-candidate-and-reference-translations)
    - [Part 3: BLEU Score Computation](#part-3-bleu-score-computation)
    - [Part 4: Analysis and Visualization](#part-4-analysis-and-visualization)
  - [Implementation Highlights](#implementation-highlights)

---

## Overview
In **Assignment 7**, we evaluate machine translation quality by implementing a BLEU (Bilingual Evaluation Understudy) score pipeline. The notebook focuses on:
1. Loading and preprocessing both candidate and reference translations.
2. Organizing the translations to facilitate pair-wise comparison.
3. Computing n-gram precision, applying the brevity penalty, and calculating the final BLEU score.
4. Analyzing the BLEU score results through visualizations.

---

## Requirements & Tasks

### Part 1: Data Loading and Preprocessing
- **Goal**: Load candidate and reference translations and prepare the text for evaluation.
- **Approach**:
  1. Read translation data from files or data sources.
  2. Normalize the text (e.g., lowercasing, punctuation removal, tokenization).
- **Outcome**: Preprocessed texts that are ready for BLEU evaluation.

---

### Part 2: Organizing Candidate and Reference Translations
- **Goal**: Structure the translations into candidate and reference sets.
- **Approach**:
  1. Ensure that candidate translations are correctly paired with one or more reference translations.
  2. Manage cases with multiple references per candidate.
- **Outcome**: A well-organized dataset for comparing candidate outputs against reference translations.

---

### Part 3: BLEU Score Computation
- **Goal**: Implement the BLEU score calculation to quantitatively assess translation quality.
- **Approach**:
  1. Compute n-gram overlaps (for n=1 to 4) between candidate and reference translations.
  2. Calculate precision scores for each n-gram level.
  3. Apply a brevity penalty to penalize overly short translations.
  4. Combine the precision scores (weighted geometric mean) to compute the final BLEU score.
- **Outcome**: A BLEU score that reflects how closely the candidate translations match the references.

---

### Part 4: Analysis and Visualization
- **Goal**: Analyze the computed BLEU scores and visualize the results.
- **Approach**:
  1. Generate visualizations (e.g., bar charts or line plots) for n-gram precision.
  2. Compare BLEU scores across different candidate translation outputs.
- **Outcome**: Insights into the performance of the machine translation system based on BLEU metrics.

---

## Implementation Highlights
- **Preprocessing**:  
  - Applied standard text normalization, tokenization, and cleaning to both candidate and reference texts.
- **BLEU Calculation**:  
  - Computed n-gram overlaps and precision scores.
  - Implemented the brevity penalty to account for translation length discrepancies.
  - Combined the scores to generate the final BLEU score.
- **Visualization**:  
  - Created plots to display n-gram precision and overall BLEU scores for detailed analysis.