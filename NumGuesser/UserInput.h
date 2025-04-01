#pragma once

// Prompts the user to enter a guess
void GetUserInput(int* UserInput);

// Easy mode input validation (1–100), returns number of attempts
int CheckUserInput(int* UserInput, int RandNum);

// Hard mode input validation (1–500), returns number of attempts
int CheckUserInput_Hard(int* UserInput, int RandNum);

// Validates guess until correct, returns number of tries taken
int ValidateUserGuess(int* UserInput, int RandNum);

// Checks if the guess is within easy mode range
int CheckRange(int* UserInput);

// Checks if the guess is within hard mode range
int CheckHardRange(int* UserInput);
