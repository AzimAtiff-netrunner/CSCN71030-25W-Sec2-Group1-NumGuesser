//NumGuesser By: Azim Atif, Jaden Mardini, Mohamed .H 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "UserInput.h"
#include "RNG_Module.h"
#include "Scoring.h"
#include "FileHandling.h"

int main(int argc, char* argv[]) {//REQ-SYS-020
	init_rng(); // Seed the random number generator

	int UserGuess;
	int UserChoice;

	printf("What difficulty would you like to play? \n");
	printf("Type 1 for easy\n");
	printf("Type 2 for hard\n");
	scanf("%d", &UserChoice);

	if (UserChoice == 1) {//easy path
		// Generate random number
		int RandNum = generate_random_number();

		// Display the generated number
		printf("Guess the Random Number Generated(1-100)\n");

		// Check input and get number of attempts
		int attempts = CheckUserInput(&UserGuess, RandNum);

		// Load current high score and calculate new score
		int oldHighScore = load_high_score();
		ScoreData data = calculate_score_data(attempts, oldHighScore);

		// Display score and update high score if needed
		if (data.currentScore > oldHighScore) {
			save_high_score(data.currentScore);
			printf("?? New high score: %d!\n", data.currentScore);
		}
		else {
			printf("Your score: %d. Current high score: %d\n", data.currentScore, oldHighScore);
		}
	}
	else if (UserChoice == 2) {//hard path
		int RandNum = generate_random_hard_number();

		// Display the generated number
		printf("Guess the Random Number Generated(1-500)\n");

		// Check input and get number of attempts
		int attempts = CheckUserInput_Hard(&UserGuess, RandNum);

		// Load current high score and calculate new score
		int oldHighScore = load_high_score();
		ScoreData data = calculate_score_data(attempts, oldHighScore);

		// Display score and update high score if needed
		if (data.currentScore > oldHighScore) {
			save_high_score(data.currentScore);
			printf("?? New high score: %d!\n", data.currentScore);
		}
		else {
			printf("Your score: %d. Current high score: %d\n", data.currentScore, oldHighScore);
		}
	}
	else {
		printf("Get out\n");
		return 1;
	}

	return 0;
}
