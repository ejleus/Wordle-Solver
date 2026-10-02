# Word Search Solver — Design Document

- **Author:** Emmanuel Leus
- **Date:** May 2026

## Overview

This project implements a command-line word-search solver in C. The
solver uses vocabulary searching, string manipulation, pointers, and
heuristic scoring to narrow down possible solutions.

The solver can operate in two ways: it can solve for a known target
word for testing purposes, or it can interactively suggest guesses
while searching for a solution.

The project also includes automated tests for the solver's core
functions to verify correctness and handle different search cases.

## `score_letter()`

This function takes a letter, a vocabulary, and the number of words
in the vocabulary. It searches through the vocabulary and returns the
number of words containing the specified letter.

The result is used to determine how frequently a letter occurs within
the remaining vocabulary.

## `score_word()`

This function calculates a score for a word based on the letters it
contains. Each unique letter contributes to the score only once.

The score allows the solver to prioritize words containing letters
that occur frequently in the remaining vocabulary.

## `filter_vocabulary_gray()`

This function removes words from the vocabulary that contain a letter
known to be absent from the target word.

Words containing the specified letter are removed from consideration,
and the function returns the number of words that were filtered out.

## Testing

The solver includes automated test cases for its core functions.
Testing is used to verify that vocabulary filtering, letter scoring,
and word scoring behave correctly across different inputs.

## Design Goals

The main goals of the project are:

- Efficiently narrow the possible solution space
- Use letter frequency to select useful guesses
- Keep the solver organized into reusable functions
- Verify functionality through automated testing
- Practice string manipulation, pointers, arrays, and file handling in C

## function 1: score_letter

This function takes in a letter, vocabulary (word bank), and a number for the amount of words. The function loops over vocabulary and returns the number of words that include the specified letter.

## function 2: score_word

This function takes in a word and an array of each letter in the alphabet. The function returns a score based on which letters are in the secret word, but each letter can only count once. This is to eliminate which letters are not in the secret word.

## function 3: filter_vocabulary_gray

This function takes in a letter, the vocabulary, and the size of vocabulary. The function's job is to filter out words that contain the letter specified if the letter is not in the secret word. All of the words with the specified letter will be set to NULL, since the secret word does not have that letter. Return the number of words that have been removed/filtered.

## function 4: filter_vocabulary_yellow

This function takes in a letter, a position, the vocabulary, and the size of vocabulary. The function removes any words that do not have the specified letter or, if the letter is in the specified position. This leaves only the words that contain the letter, but have it in a different position. Return the number of words filtered out.

## function 5: filter_vocabulary_green

This function takes in a letter, position, the vocabulary, and the size of vocabulary. The function removes any words that do not contain the specified letter in the specified position. This leaves words that have a letter in the secret word also in the correct position. Returns the number of words filtered out.
