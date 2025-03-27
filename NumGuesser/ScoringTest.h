#ifndef SCORING_TEST_H
#define SCORING_TEST_H

#define MAX_PLAYERS 5
#define MAX_ROUNDS 3

#include <string.h>  // Required for strcpy

//Ensure Player is properly defined
typedef struct Player {
    char name[50];
    int scores[MAX_ROUNDS];
} Player;

//Ensure function declarations are correctly formatted
#ifdef __cplusplus
extern "C" {
#endif

    void updateScores(Player* player, int round, int score);
    int calculateTotalScore(Player player);
    Player findTopScorer(Player* players, int numPlayers);

#ifdef __cplusplus
}
#endif

#endif // SCORING_TEST_H
