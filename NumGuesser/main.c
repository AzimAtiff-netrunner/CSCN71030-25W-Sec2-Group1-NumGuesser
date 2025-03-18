//NumGuesser By: Azim Atif, Jaden Mardini, Mohamed .H 

#include <stdio.h>
#include "UserInput.h"
#include "RNG_Module.h"

int main(int argc, char* argv) {//REQ-SYS-020
	init_rng();
	int UserGuess;
	// Generate random number
	int RandNum = generate_random_number();

	// Display the generated number
	printf("Guess the Random Number Generated");
	CheckUserInput(&UserGuess, RandNum);
	
	return 0;
}