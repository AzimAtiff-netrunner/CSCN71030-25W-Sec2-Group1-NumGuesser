#include <stdio.h>
#include "Scoring.h"

// Updates the score history array by shifting left and adding new score at the end
void update_score_history(int* history, int newScore) {
    for (int i = 0; i < HISTORY_SIZE - 1; i++) {
        history[i] = history[i + 1];
    }
    history[HISTORY_SIZE - 1] = newScore;
}

// Prints all non-negative scores in the history
void print_score_history(int* history) {
    printf("\nScore history (most recent last):\n");
    for (int i = 0; i < HISTORY_SIZE; i++) {
        if (history[i] >= 0) {
            printf("Game %d: %d attempts\n", i + 1, history[i]);
        }
    }
}
