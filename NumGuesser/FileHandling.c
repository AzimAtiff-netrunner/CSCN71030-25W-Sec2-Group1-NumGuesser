#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileHandling.h"

#define HIGH_SCORE_FILE "high_score.txt"
#define SCORE_HISTORY_FILE "score_history.txt"

// Save the lowest number of attempts (best score)
void save_high_score(int attempts) {
    FILE* file = fopen(HIGH_SCORE_FILE, "w");
    if (file) {
        fprintf(file, "%d", attempts);
        fclose(file);
    }
}

// Load the best score (lowest number of attempts)
int load_high_score() {
    int attempts = 999;
    FILE* file = fopen(HIGH_SCORE_FILE, "r");
    if (file) {
        fscanf(file, "%d", &attempts);
        fclose(file);
    }
    return attempts;
}

// Save the score history array to a file using a dynamically allocated buffer
void save_score_history(int* history, int size) {
    FILE* file = fopen(SCORE_HISTORY_FILE, "w");
    if (file) {
        // Estimate maximum buffer size: assume up to 16 characters per score (including newline)
        int buf_size = size * 16;
        char* buffer = (char*)malloc(buf_size);
        if (buffer == NULL) {
            // Fallback: if malloc fails, write directly to file
            for (int i = 0; i < size; i++) {
                fprintf(file, "%d\n", history[i]);
            }
        }
        else {
            buffer[0] = '\0'; // initialize buffer as an empty string
            for (int i = 0; i < size; i++) {
                char line[16];
                snprintf(line, sizeof(line), "%d\n", history[i]);
                strcat(buffer, line);
            }
            fputs(buffer, file);
            free(buffer);  // free the allocated memory
        }
        fclose(file);
    }
}

// Load the score history array from a file
void load_score_history(int* history, int size) {
    FILE* file = fopen(SCORE_HISTORY_FILE, "r");
    if (file) {
        for (int i = 0; i < size; i++) {
            fscanf(file, "%d", &history[i]);
        }
        fclose(file);
    }
    else {
        for (int i = 0; i < size; i++) {
            history[i] = -1; // initialize with -1 (empty)
        }
    }
}
