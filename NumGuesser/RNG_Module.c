#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RNG_Module.h"

// Function to seed the random number generator
void init_rng() {
    srand((unsigned int)time(NULL)); // Seed RNG with current time
}

// Function to generate a random number between 1 and 100
int generate_random_number() {
    return (rand() % 100) + 1; // Random number: (0-99) + 1 = 1-100
}