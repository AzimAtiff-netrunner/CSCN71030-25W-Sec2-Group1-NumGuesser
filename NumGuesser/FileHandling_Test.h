
#ifndef FILE_HANDLING_TEST_H
#define FILE_HANDLING_TEST_H
#include <stdio.h>
#include "ScoringTest.h"  //Ensure Player struct is included

// Function prototypes
void saveScores(struct Player* players, int numPlayers, const char* filename);
void loadScores(struct Player* players, int* numPlayers, const char* filename);
int deleteScoreFile(const char* filename);

#endif // FILE_HANDLING_TEST_H
