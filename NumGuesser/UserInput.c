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

int ValidateUserGuess(int* UserInput, int RandNum) {
	int UserTries = 0;

	while (*UserInput != RandNum) {//users can keep guessing until they guess correctly
		if (*UserInput < RandNum) {//compare the guess with the number 
			printf("Your guess is LOWER than the actual number\n");//print hint
		}
		else {
			printf("Your guess is HIGHER than the actual number\n");//print hint
		}
		UserTries++;//add user attempt
		GetUserInput(UserInput);
	}
	printf("It took you %d tries to guess the correct number\n", UserTries + 1); //print their attempts at the end
}

int CheckRange(int* UserInput) {//verify user's input in the specified range
	if (*UserInput < 1 || *UserInput > 100) {
		printf("Your guess is out of range. Must be between 1-100\n");
		return 0;
	}
	return 1;

}