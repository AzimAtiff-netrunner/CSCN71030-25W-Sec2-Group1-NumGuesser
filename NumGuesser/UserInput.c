#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "UserInput.h"
#include "RNG_Module.h"

#define USER_ATMPS 10

void GetUserInput(int* UserInput) {
    // Prompts user for input
    printf("\nPlease type in your guess:\n");
    scanf("%d", UserInput);
    printf("YOUR guess was %d\n", *UserInput);
}

// Easy mode input checker
int CheckUserInput(int* UserInput, int RandNum) {
    int UserTries = 0;

    while (UserTries < USER_ATMPS) {
        GetUserInput(UserInput);
        if (!CheckRange(UserInput)) {
            UserTries++;
            continue;
        }

        int tries = ValidateUserGuess(UserInput, RandNum);
        UserTries += tries;
        return UserTries;
    }

    printf("Too many attempts. Come back later\n");
    return USER_ATMPS;
}

// Hard mode input checker
int CheckUserInput_Hard(int* UserInput, int RandNum) {
    int UserTries = 0;

    while (UserTries < USER_ATMPS) {
        GetUserInput(UserInput);
        if (!CheckHardRange(UserInput)) {
            UserTries++;
            continue;
        }

        int tries = ValidateUserGuess(UserInput, RandNum);
        UserTries += tries;
        return UserTries;
    }

    printf("Too many attempts. Come back later\n");
    return USER_ATMPS;
}

// Repeatedly checks user guess until it's correct
int ValidateUserGuess(int* UserInput, int RandNum) {
    int UserTries = 0;

    while (*UserInput != RandNum) {
        if (*UserInput < RandNum) {
            printf("Your guess is LOWER than the actual number\n");
        }
        else {
            printf("Your guess is HIGHER than the actual number\n");
        }

        UserTries++;
        printf("Type in your next guess: ");
        scanf("%d", UserInput);
    }

    UserTries++;
    printf("It took you %d tries to guess the correct number\n", UserTries);

    return UserTries;
}

// Range check for easy mode (1-100)
int CheckRange(int* UserInput) {
    if (*UserInput < 1 || *UserInput > 100) {
        printf("Your guess is out of range. Must be between 1 and 100\n");
        return 0;
    }
    return 1;
}

// Range check for hard mode (1-500)
int CheckHardRange(int* UserInput) {
    if (*UserInput < 1 || *UserInput > 500) {
        printf("Your guess is out of range. Must be between 1 and 500\n");
        return 0;
    }
    return 1;
}
