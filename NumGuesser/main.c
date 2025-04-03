#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "UserInput.h"
#include "RNG_Module.h"
#include "FileHandling.h"
#include "Scoring.h"

#define MAX_FILE    256

int main(int argc, char* argv[]) {
    init_rng(); // Seed the random number generator

    int UserGuess;
    int UserChoice;
    int history[HISTORY_SIZE];

    // Check for command-line argument
    if (argc != 2) {
        printf("Usage: %s <savefile>\n", argv[0]);
        return 1;
    }
  
    // get the save file name from the command-line argument
    char saveFile[MAX_FILE];
    strncpy(saveFile, argv[1], MAX_FILE - 1);

    // Load previous score history from file
    load_score_history(history, HISTORY_SIZE);

    FILE* file = fopen(saveFile, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", saveFile);
        exit (1);
    }

    fclose(file);

    printf("What difficulty would you like to play? \n");
    printf("Type 1 for easy\n");
    printf("Type 2 for hard\n");
    scanf("%d", &UserChoice);

    int attempts = 0;

    if (UserChoice == 1) {
        int RandNum = generate_random_number();
        printf("Guess the Random Number Generated (1-100)\n");

        attempts = CheckUserInput(&UserGuess, RandNum);
    }
    else if (UserChoice == 2) {
        int RandNum = generate_random_hard_number();
        printf("Guess the Random Number Generated (1-500)\n");

        attempts = CheckUserInput_Hard(&UserGuess, RandNum);
    }
    else {
        printf("Invalid choice. Exiting program.\n");
        return 1;
    }

    // Check and update best score
    int bestAttempts = load_high_score();
    if (attempts < bestAttempts) {
        save_high_score(attempts);
        printf("New best score! You guessed the number in %d attempts.\n", attempts);
    }
    else {
        printf("You took %d attempts. Best score so far is %d attempts.\n", attempts, bestAttempts);
    }

    // Update and display score history
    update_score_history(history, attempts);
    save_score_history(history, HISTORY_SIZE);
    print_score_history(history);

    return 0;
}
