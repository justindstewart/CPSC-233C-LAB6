/*
  wordhist.c

  CPSC 223C
  Spring 2015
  CSU Fullerton

  Lab 6: word frequencies in O(n log n) time

  Authors: Justin Stewart (scubastew@csu.fullerton.edu)
*/ 

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordhist.h"

/* You can assume every word has at most MAX_WORD_LENGTH
   characters.

   This is defined in the .c file, not the .h file, since this is an
   implementation detail that should be hidden from users. */
#define MAX_WORD_LENGTH 200

WordHist* word_hist_parse(char* filename) {
  WordHist *hist; /* object to create and return */
  FILE *f;
  char **tokens;  /* array of strings corresponding to all the tokens in f */
  int n;          /* number of tokens */
  char str[MAX_WORD_LENGTH];
  int count = 0;

  /* TODO: You will probably need more local variables. */

  assert(filename != NULL);

  /* Try to open the file. */
  f = fopen(filename, "r");
  if (f == NULL) {
    return NULL; /* file not found */
  }

  /* TODO: Initialize n with a loop that reads one word, increments n,
     and continues until EOF is reached. Essentially you need to count
     the words one by one. Hint: see how word tokens are read with
     fscanf in the Lab 5 solution code. */
  n = 0;
  while(fscanf(f, "%s", str) != EOF) {
    n++;
  }

  /* TODO: Now that you know how many tokens there are, initialize the
     tokens array by allocating an array of n char* pointers. Hint:
     use calloc. Remeber that, if the allocation fails, you have to
     close f and return NULL. */
  if(!(tokens = calloc(n, sizeof(char*)))) {
    fprintf(stderr, "\nError: failed allocation of tokens");
    fclose(f);
    return NULL;
  }
  
  /* TODO: Now go back and load the contents of each token into
     memory. Rewind f back to the beginning. Then use a loop that
     reads one word into a stack-allocated string, copies that string
     into a new heap-allocated string, and stores that pointer in the
     tokens array. Hint: use rewind() and strdup(). Remember that,
     again, if any allocation fails you need to close f, free
     everything, and return NULL. */
  rewind(f);

  while(fscanf(f, "%s", str) != EOF) {
    char  *heapString;
    
    heapString = malloc(sizeof(str));

    if(heapString == NULL) {
      return NULL;
    }

    heapString = strdup(str);

    tokens[count] = heapString;
    count++;
  }
  
  /* We are done with f. */
  fclose(f);

  /* TODO: sort tokens with qsort(). */

  qsort(
  /* TODO: Initialize hist by allocating memory for it with
     malloc(). If this fails you need to free all the words and return
     NULL. */

  /* TODO: Initialize hist->entries by allocating memory for it with
     calloc(). As usual if this fails you need to free memory and
     return NULL. */

  /* TODO: Now initialize hist->entry_count, and the contents of
     hist->entries, by scanning through tokens and identifying the
     distinct words and the number of times that they occur. Since
     tokens is now in sorted alphabetical order, all the occurrences
     of a given word such as "the" will be next to each other. So you
     need a loop that counts how many adjacent token strings are equal
     to each other, and initializes one WordEntry with that word
     string and count value. */

  /* TODO: Free each tokens[i] and then tokens itself. */

  return hist;  
}

void word_hist_free(WordHist* hist) {
  int i;

  assert(hist != NULL);

  /* free the word strings in each entry */
  for (i = 0; i < hist->entry_count; i++) {
    free(hist->entries[i].word);
  }

  /* free the entry array */
  free(hist->entries);

  /* free the WordHist struct */
  free(hist);
}

void word_hist_print(WordHist* hist) {
  int i;

  assert(hist != NULL);

  for (i = 0; i < hist->entry_count; i++) {
    printf("%s %i\n", hist->entries[i].word, hist->entries[i].count);
  }
}
