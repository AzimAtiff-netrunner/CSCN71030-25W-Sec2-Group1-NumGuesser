#pragma once

// Define struct only if not already defined elsewhere
#ifndef SCORE_DATA_DEFINED
#define SCORE_DATA_DEFINED
typedef struct {
    int currentScore;
    int highScore;
} ScoreData;
#endif

// Function prototypes
ScoreData calculate_score_data(int attempts, int highScore);
int get_random_bonus();
void calculate_score_ptr(int attempts, int* score);
