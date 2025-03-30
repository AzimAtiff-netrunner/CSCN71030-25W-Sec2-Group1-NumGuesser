#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "FileHandling.h"

#define HIGH_SCORE_FILE "high_score.txt"

void save_high_score(int score)
{
    FILE* file = fopen(HIGH_SCORE_FILE, "w");
    if (file)
    {
        fprintf(file, "%d", score);
        fclose(file);
    }
}

int load_high_score()
{
    int score = 0;
    FILE* file = fopen(HIGH_SCORE_FILE, "r");
    if (file)
    {
        fscanf(file, "%d", &score);
        fclose(file);
    }
    return score;
}