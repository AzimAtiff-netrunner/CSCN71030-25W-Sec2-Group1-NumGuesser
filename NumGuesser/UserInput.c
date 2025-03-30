#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "UserInput.h"
#include "RNG_Module.h"

#define USER_ATMPS	10

void GetUserInput(int* UserInput) {//prompts user for input
	printf("\nPlease type in your guess:\n");
	scanf("%d", UserInput);
	printf("YOUR guess was %d\n", *UserInput);
}

void CheckUserInput(int* UserInput, int RandNum) {//checks to make sure users input is within range
	int UserTries = 0;

	while (UserTries < USER_ATMPS) {//users will have 10 attempts to keep guessing if they keep inputting the wrong inputs
		GetUserInput(UserInput);
		if (!CheckRange(UserInput)) {
			UserTries++;//count attempts
			continue; //retry if invalid
		}

		ValidateUserGuess(UserInput, RandNum);
		return;
	}
	printf("Too many attempts. Come back later\n");

}

char* ValidateUserGuess(int* UserInput, int RandNum) {
	int UserTries = 0;
	char* result = "";
	while (*UserInput != RandNum) {  // Keep guessing until correct
		if (*UserInput < RandNum) {
			result = "Your guess is LOWER than the actual number";
		}
		else {
			result = "Your guess is HIGHER than the actual number";
		}

		UserTries++;  // add attempt count

		printf("%s\n", result);  // Display hint
		printf("Type in your next guess: ");
		scanf("%d", UserInput);  // Get new guess
	}
	UserTries++;  //add final attempt
	printf("It took you %d tries to guess the correct number\n", UserTries);

	return result;
}

int CheckRange(int* UserInput) {//verify user's input in the specified range
	if (*UserInput < 1 || *UserInput > 100) {
		printf("Your guess is out of range. Must be between 1-100\n");
		return 0;
	}
	return 1;

}