/*
 * Zhongkai Huang
 * Unittest2.c
 * Test for Effect_minion
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "minion"

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
    printf("Unit Test for minion Card\n");
    // Test 1: Check either choice actions are incremented once for the player
    initializeGame(num_player, k, seed, &G);
    G.hand[player][3] = minion;
    Effect_minion(0, 0, 0, &G, 3, player); // play the card
    if ((result = Check_As(G.numActions > 1)))
    {
        printf("\tTest 1 Success\n");
    }
    else
    {
        printf("\tTest 1 Fail\n");
    }

    // Test 2: Check choice 1 that coins are incremented by 2
    initializeGame(num_player, k, seed, &G);
    G.hand[player][3] = minion;
    coins = G.coins;
    Effect_minion(0, 1, 0, &G, 3, player); // play the card for choice 1
    if ((result = Check_As(G.coins >= coins + 2)))
    {
        printf("\tTest 2 Success\n");
    }
    else
    {
        printf("\tTest 2 Fail\n");
    }

    // Test 3: Check for either choice minion card will discarded
    initializeGame(num_player, k, seed, &G);
    G.hand[player][3] = minion;
    Effect_minion(0, 1, 0, &G, 3, player); // play the card

    if ((result = Check_As(G.hand[player][4] == -1)))
    {
        printf("\tTest 3 Success\n"); 
    }
    else
    {
        printf("\tTest 3 Fail\n");
    }


    // Test 4: Check if player draws only 4 cards
    initializeGame(num_player, k, seed, &G);
    G.hand[1][0] = mine;
    G.hand[1][1] = mine;
    G.hand[1][2] = mine;
    G.hand[1][3] = mine;
    G.hand[1][4] = mine;
    G.handCount[1] = 5;
    G.hand[player][3] = minion; 
    int handCount = G.handCount[player];
    Effect_minion(0, 0, 1, &G, 3, player); 
    if ((result = Check_As(G.handCount[player] < handCount)))
    {
        printf("\tTest 4 Success\n");
    }
    else
    {
        printf("\tTest 4 Fail\n");
    }

    printf("Ending Unit Test for Minion");
}
