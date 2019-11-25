/*
 * Zhongkai Huang
 * Unittest1.c
 * Test for Effect_baron
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "baron"

int Check_As(int x)
{
    if (!x)
    {
        return 0;
    }
    return 1;
};

int main()
{
    int num_player = 2;
    int seed = 30;
    int player = 0;
    int result = 0;
    int supply = 0;
    int k[10] = {adventurer,
        ambassador,
        embargo,
        village,
        minion,
        mine,
        cutpurse,
        baron,
        tribute,
        smithy};
    struct gameState G;
    printf("Unit Test for Baron Card\n");

    // Test 1: Check the numBuys is incresed by using baron.
    initializeGame(num_player, k, seed, &G);
    G.hand[player][0] = estate;
    G.hand[player][1] = minion;
    G.hand[player][2] = cutpurse;
    G.hand[player][3] = baron;
    G.hand[player][4] = mine;
    baronCardEffect(&G, 3, player);
    if ((result = Check_As(G.numBuys == 2)))
    {
        printf("\t Test 1 Success\n");
    }
    else
    {
        printf("\t Test 1 Fail\n");
    }

    // Test 2: Check the coin is incresed 4 by using baron.
    initializeGame(num_player, k, seed, &G);
    G.hand[player][0] = estate;
    G.hand[player][1] = minion;
    G.hand[player][2] = cutpurse;
    G.hand[player][3] = baron;
    G.hand[player][4] = mine;
    G.coins = 0;
    baronCardEffect(&G, 3, player);

    if ((result = Check_As(G.coins == 4)))
    {
        printf("\t- Test 2 Success\n");
    }
    else
    {
        printf("\t- Test 2 Fail\n");
    }

    // Test 3: Check if the player have a estate card when using baron card.
    initializeGame(num_player, k, seed, &G);
    G.hand[player][0] = estate;
    G.hand[player][1] = minion;
    G.hand[player][2] = cutpurse;
    G.hand[player][3] = baron;
    G.hand[player][4] = mine;
    baronCardEffect(&G, 3, player);

    if ((result = Check_As(G.handCount[player] == 4))) // Result should be 4 because the player has 5 cards
    {
        printf("\t- Test 3 Success\n");
    }
    else
    {
        printf("\t- Test 3 Fail\n");
    }

    printf("Ending Unit Test for Baron");
}
