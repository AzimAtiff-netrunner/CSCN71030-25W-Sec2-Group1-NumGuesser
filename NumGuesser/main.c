//NumGuesser By: Azim Atif, Jaden Mardini, Mohamed .H 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "UserInput.h"
#include "RNG_Module.h"

int main(int argc, char* argv[]) {//REQ-SYS-020
	init_rng();
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
		printf("Guess the Random Number Generated(1-100)");
		CheckUserInput(&UserGuess, RandNum);
	}
	else if (UserChoice == 2) {//hard path
		int RandNum = generate_random_hard_number();
		
		// Display the generated number
		printf("Guess the Random Number Generated(1-500)");
		CheckUserInput_Hard(&UserGuess, RandNum);
	}
	else {
		printf("Get out\n");
		return 1;
	}
	

	return 0;
}




