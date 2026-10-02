# Homework 6: Design Document

  * author: Emmanuel Leus
  * date: May 2026

## introduction

In this homework, I will implement a solver for a fun game to amuse and amaze my
friends and loved ones, and I will meditate on the nature of games and whether
it is more fun to play a game, more fun to have an automated system play games
on my behalf -- or more fun to write software to do that second thing for me.

TODO(you): create a solver for the game we made last homework, write my own tests for each of the functions

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
