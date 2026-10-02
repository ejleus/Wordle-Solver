// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include "search_util.h"

 void reset_vocabulary(char **vocabulary, char words[10][6]) {
    for (int i = 0; i < 10; i++) {
        if (vocabulary[i] != NULL) {
            free(vocabulary[i]);
        }
        vocabulary[i] = strdup(words[i]);
    }
}

int main(void) {
    char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif",
                         "tense", "ultra", "vital", "ether", "nadir"};

    char **vocabulary = calloc(10, sizeof(char *));
    size_t num_words = 10;

    reset_vocabulary(vocabulary, words);

    printf("Starting automated tests...\n\n");

    printf("Testing score_letter...\n");
    assert(score_letter('s', vocabulary, num_words) == 4);
    assert(score_letter('a', vocabulary, num_words) == 7);
    assert(score_letter('z', vocabulary, num_words) == 0);

    free(vocabulary[0]);
    vocabulary[0] = NULL;
    assert(score_letter('s', vocabulary, num_words) == 3);
    printf("-> score_letter passed!\n\n");

    printf("Testing score_word...\n");
    int mock_scores[26] = {0};
    mock_scores['t' - 'a'] = 5;
    mock_scores['e' - 'a'] = 2;
    mock_scores['n' - 'a'] = 3;
    mock_scores['s' - 'a'] = 4;

    assert(score_word("tense", mock_scores) == 14);
    printf("-> score_word passed!\n\n");

    printf("Testing filter_vocabulary_gray...\n");
    reset_vocabulary(vocabulary, words);
    size_t gray_filtered = filter_vocabulary_gray('m', vocabulary, num_words);
    assert(gray_filtered == 1);
    assert(vocabulary[4] == NULL);
    assert(vocabulary[0] != NULL);
    printf("-> filter_vocabulary_gray passed!\n\n");

    printf("Testing filter_vocabulary_yellow...\n");
    reset_vocabulary(vocabulary, words);
    size_t yellow_filtered = filter_vocabulary_yellow('s', 0, vocabulary, num_words);
    assert(yellow_filtered == 9);
    assert(vocabulary[5] != NULL);
    assert(strcmp(vocabulary[5], "tense") == 0);
    assert(vocabulary[0] == NULL);
    assert(vocabulary[3] == NULL);
    printf("-> filter_vocabulary_yellow passed!\n\n");

    printf("Testing filter_vocabulary_green...\n");
    reset_vocabulary(vocabulary, words);
    size_t green_filtered = filter_vocabulary_green('s', 0, vocabulary, num_words);
    assert(green_filtered == 7);
    assert(vocabulary[0] != NULL);
    assert(vocabulary[1] != NULL);
    assert(vocabulary[2] != NULL);
    assert(vocabulary[3] == NULL);
    assert(vocabulary[5] == NULL);
    printf("-> filter_vocabulary_green passed!\n\n");

    for (size_t i = 0; i < num_words; i++) {
        if (vocabulary[i] != NULL) {
            free(vocabulary[i]);
        }
    }
    free(vocabulary);

    printf("All tests passed completely and successfully!\n");
    return 0;
}


  
