#pragma once

// Prompts user to enter a guess
void GetUserInput(int* UserInput);

// Easy mode: checks and validates user input (1-100), returns number of attempts
int CheckUserInput(int* UserInput, int RandNum);

// Hard mode: checks and validates user input (1-500), returns number of attempts
int CheckUserInput_Hard(int* UserInput, int RandNum);

// Validates user guesses against the random number until correct, returns number of tries
int ValidateUserGuess(int* UserInput, int RandNum);

// Verifies that the input is between 1 and 100
int CheckRange(int* UserInput);

// Verifies that the input is between 1 and 500
int CheckHardRange(int* UserInput);
