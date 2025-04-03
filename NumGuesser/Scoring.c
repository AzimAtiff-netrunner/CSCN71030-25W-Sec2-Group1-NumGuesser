#include <stdio.h>
#include "Scoring.h"

// Updates the score history struct by shifting left and adding the new score at the end
void update_score_history(ScoreHistory* history, int newScore) {
    for (int i = 0; i < HISTORY_SIZE - 1; i++) {
        history->scores[i] = history->scores[i + 1];
    }
    history->scores[HISTORY_SIZE - 1] = newScore;
}

// Prints all non-negative scores in the history
void print_score_history(const ScoreHistory* history) {
    printf("\nScore history (most recent last):\n");
    for (int i = 0; i < HISTORY_SIZE; i++) {
        if (history->scores[i] >= 0) {
            printf("Game %d: %d attempts\n", i + 1, history->scores[i]);
        }
    }
}
