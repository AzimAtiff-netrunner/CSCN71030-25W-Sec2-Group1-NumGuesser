//NumGuesser By: Azim Atif, Jaden Mardini, Mohamed .H 

#include <stdio.h>
#include "rng_module.h"
int main(int argc, char* argv) {//REQ-SYS-020
    init_rng();  // Initialize RNG (seed once)

    // Generate random number
    int random_num = generate_random_number();

    // Display the generated number
    printf("Random Number Generated: %d\n", random_num);

	return 0;
}




