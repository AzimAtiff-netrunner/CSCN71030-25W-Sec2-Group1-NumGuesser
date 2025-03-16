#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "UserInput.h"

#define USER_ATMPS	10

void GetUserInput(int* UserInput) {
	printf("Please type in your guess:\n");
	scanf("%d", UserInput);
	printf("YOUR guess was %d\n", *UserInput);
}

void CheckUserInput(int* UserInput) {
	int UserTries = 0; 

	while (UserTries < USER_ATMPS) {
		GetUserInput(UserInput);

		if (*UserInput <= 0) {
			printf("Sorry, your guess is lower than the given range\n");
		}
		else if (*UserInput > 100) {
			printf("Sorry, your guess is higher than the given range\n");
		} 
		else {
			printf("Guess is valid you may proceed\n");
			return; 
		}
		UserTries++;
	}
	printf("Too many attempts. Come back later\n"); 

}