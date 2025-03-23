#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Scoring.h"

#define MAX_SCORE 100 // Define MAX_SCORE

// Function to calculate score and return ScoreData struct
ScoreData calculate_score_data(int attempts, int highScore) {
    ScoreData data;
    data.currentScore = (attempts > 0) ? MAX_SCORE / attempts : 0;
    data.highScore = highScore;
    return data;
}

// Function to generate a random bonus
int get_random_bonus() {
    srand(time(NULL)); // Seed RNG
    return rand() % 50; // Bonus between 0-49
}

// Function to calculate score using a pointer
void calculate_score_ptr(int attempts, int* score) {
    *score = (attempts > 0) ? MAX_SCORE / attempts : 0;
}
