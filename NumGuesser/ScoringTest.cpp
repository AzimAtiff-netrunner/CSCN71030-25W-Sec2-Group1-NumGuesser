#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_PLAYERS 5
#define MAX_ROUNDS 3

// Player structure
typedef struct
{
    char name[50];
    int scores[MAX_ROUNDS];
} Player;

//Function prototypes
void updateScores(Player* player, int round, int score);
void displayScores(Player* players, int numPlayers);
int calculateTotalScore(Player player);
Player findTopScorer(Player* players, int numPlayers);

//Function Implementations
void updateScores(Player* player, int round, int score) 
{
    if (round >= 0 && round < MAX_ROUNDS)
    {
        player->scores[round] = score;
    }
}

int calculateTotalScore(Player player) 
{
    int total = 0;
    for (int i = 0; i < MAX_ROUNDS; i++) 
    {
        total += player.scores[i];
    }
    return total;
}

Player findTopScorer(Player* players, int numPlayers)
{
    Player topScorer = players[0];
    int maxScore = calculateTotalScore(players[0]);

    for (int i = 1; i < numPlayers; i++) 
    {
        int currentScore = calculateTotalScore(players[i]);
        if (currentScore > maxScore) 
        {
            maxScore = currentScore;
            topScorer = players[i];
        }
    }
    return topScorer;
}

//Unit Tests for Scoring Module
void testScoringModule() {
    Player players[MAX_PLAYERS] = { {"Alice", {0, 0, 0}}, {"Bob", {0, 0, 0}} };

    // Test:Update Scores
    updateScores(&players[0], 1, 85);
    assert(players[0].scores[1] == 85);
    printf("Passed: updateScores()\n");

    // Test:Calculate Total Score
    players[0].scores[0] = 90;
    players[0].scores[2] = 80;
    int total = calculateTotalScore(players[0]);
    assert(total == (90 + 85 + 80));
    printf("Passed: calculateTotalScore()\n");

    // Test:Find Top Scorer
    players[1].scores[0] = 88;
    players[1].scores[1] = 92;
    players[1].scores[2] = 79;
    Player topScorer = findTopScorer(players, 2);
    assert(strcmp(topScorer.name, "Bob") == 0);
    printf("Passed: findTopScorer()\n");
}

int main() 
{
    testScoringModule();
    printf("All Scoring Module Tests Passed!\n");
    return 0;
}
