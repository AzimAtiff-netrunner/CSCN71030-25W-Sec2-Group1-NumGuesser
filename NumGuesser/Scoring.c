#include "Scoring.h"

#define MAX_SCORE 1000

int calculate_score(int attempts) 
{
    return (attempts > 0) ? MAX_SCORE / attempts : 0;
}
