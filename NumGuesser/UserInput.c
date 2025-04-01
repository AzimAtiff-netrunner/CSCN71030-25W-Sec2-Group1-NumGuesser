#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "UserInput.h"
#include "RNG_Module.h"

#define USER_ATMPS 10

void GetUserInput(int* UserInput) {//prompts user for input
	printf("\nPlease type in your guess:\n");
	scanf("%d", UserInput);
	printf("YOUR guess was %d\n", *UserInput);
}

// checks to make sure user's input is within range
int CheckUserInput(int* UserInput, int RandNum) {
	int UserTries = 0;

	while (UserTries < USER_ATMPS) {//users will have 10 attempts to keep guessing if they keep inputting the wrong inputs
		GetUserInput(UserInput);
		if (!CheckRange(UserInput)) {
			UserTries++;//count attempts
			continue; //retry if invalid
		}

		int tries = ValidateUserGuess(UserInput, RandNum); // get number of attempts
		UserTries += tries;
		return UserTries;
	}
	printf("Too many attempts. Come back later\n");
	return USER_ATMPS;
}

// checks to make sure user's input is within range (hard mode)
int CheckUserInput_Hard(int* UserInput, int RandNum) {
	int UserTries = 0;

	while (UserTries < USER_ATMPS) {//users will have 10 attempts to keep guessing if they keep inputting the wrong inputs
		GetUserInput(UserInput);
		if (!CheckHardRange(UserInput)) {
			UserTries++;//count attempts
			continue; //retry if invalid
		}

		int tries = ValidateUserGuess(UserInput, RandNum); // get number of attempts
		UserTries += tries;
		return UserTries;
	}
	printf("Too many attempts. Come back later\n");
	return USER_ATMPS;
}

// keeps prompting user until they guess correctly; returns number of tries
int ValidateUserGuess(int* UserInput, int RandNum) {
	int UserTries = 0;

	while (*UserInput != RandNum) {  // Keep guessing until correct
		if (*UserInput < RandNum) {
			printf("Your guess is LOWER than the actual number\n");
		}
		else {
			printf("Your guess is HIGHER than the actual number\n");
		}

		UserTries++;  // add attempt count

		printf("Type in your next guess: ");
		scanf("%d", UserInput);  // Get new guess
	}
	UserTries++;  // add final correct attempt
	printf("It took you %d tries to guess the correct number\n", UserTries);

	return UserTries;
}

int CheckRange(int* UserInput) {//verify user's input in the specified range
	if (*UserInput < 1 || *UserInput > 100) {
		printf("Your guess is out of range. Must be between 1-100\n");
		return 0;
	}
	return 1;
}

int CheckHardRange(int* UserInput) {//verify user's input in the specified range
	if (*UserInput < 1 || *UserInput > 500) {
		printf("Your guess is out of range. Must be between 1-500\n");
		return 0;
	}
	return 1;
}
