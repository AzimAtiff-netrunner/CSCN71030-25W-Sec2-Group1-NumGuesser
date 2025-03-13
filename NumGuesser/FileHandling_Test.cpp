#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_PLAYERS 5
#define MAX_ROUNDS 3
#define FILENAME "scores.txt"

//Player structure
typedef struct 
{
    char name[50];
    int scores[MAX_ROUNDS];
} Player;

//Function prototypes
void saveScores(Player* players, int numPlayers, const char* filename);
void loadScores(Player* players, int* numPlayers, const char* filename);
int deleteScoreFile(const char* filename);

//Function Implementations
void saveScores(Player* players, int numPlayers, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (!file) 
    {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < numPlayers; i++)
    {
        fprintf(file, "%s ", players[i].name);
        for (int j = 0; j < MAX_ROUNDS; j++) 
        {
            fprintf(file, "%d ", players[i].scores[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void loadScores(Player* players, int* numPlayers, const char* filename) 
{
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    *numPlayers = 0;
    while (fscanf(file, "%s", players[*numPlayers].name) != EOF)
    {
        for (int j = 0; j < MAX_ROUNDS; j++) {
            fscanf(file, "%d", &players[*numPlayers].scores[j]);
        }
        (*numPlayers)++;
    }
    fclose(file);
}

int deleteScoreFile(const char* filename)
{
    return remove(filename);
}

//Unit Tests for File Handling Module
void testFileHandlingModule()
{
    Player players[MAX_PLAYERS] = { {"Alice", {85, 90, 78}}, {"Bob", {92, 88, 79}} };
    Player loadedPlayers[MAX_PLAYERS];
    int numLoadedPlayers = 0;

    //Test:Save Scores
    saveScores(players, 2, FILENAME);
    FILE* file = fopen(FILENAME, "r");
    assert(file != NULL);
    fclose(file);
    printf("Passed: saveScores()\n");

    //Test:Load Scores
    loadScores(loadedPlayers, &numLoadedPlayers, FILENAME);
    assert(numLoadedPlayers == 2);
    assert(strcmp(loadedPlayers[0].name, "Alice") == 0);
    assert(loadedPlayers[0].scores[0] == 85);
    assert(loadedPlayers[1].scores[2] == 79);
    printf("Passed: loadScores()\n");

    //Test:Delete Score File
    assert(deleteScoreFile(FILENAME) == 0);
    file = fopen(FILENAME, "r");
    assert(file == NULL);
    printf("Passed: deleteScoreFile()\n");
}

int main() 
{
    testFileHandlingModule();
    printf("All File Handling Module Tests Passed!\n");
    return 0;
}
