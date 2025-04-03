#pragma once

#define HISTORY_SIZE 5

// Struct to hold the score history array
typedef struct {
    int scores[HISTORY_SIZE];
} ScoreHistory;

// Updates the score history by shifting scores left and adding a new score at the end
void update_score_history(ScoreHistory* history, int newScore);

// Displays the score history
void print_score_history(const ScoreHistory* history);
