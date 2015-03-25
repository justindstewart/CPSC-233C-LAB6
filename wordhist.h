/*
  wordhist.h

  CPSC 223C
  Spring 2015
  CSU Fullerton

  Lab 6: word frequencies in O(n log n) time

  Authors: Kevin Wortman (kwortman@csu.fullerton.edu)

  You should leave this file unchanged.

*/ 

#ifndef __WORDHIST_H
#define __WORDHIST_H

/* Structure for a single word-count entry. */
typedef struct WordEntry_t {
  char* word; /* word is a heap-allocated string */
  int count;
} WordEntry;

/* Structure for a histogram of many word-count entries, stored as a
   partially-filled array. */
typedef struct WordHist_t {
  WordEntry *entries; /* entries is a heap-allocated array */
  int entry_count;
} WordHist;

/* Open the text file with the given filename, read its
   whitespace-separated words, and construct the corresponding
   WordHist object. Return NULL on any kind of error (file not found
   or out of memory). */
WordHist* word_hist_parse(char* filename);

/* Free a WordHist object. */
void word_hist_free(WordHist* hist);

/* Print the contents of a WordHist object to stdout. */
void word_hist_print(WordHist* hist);

#endif
