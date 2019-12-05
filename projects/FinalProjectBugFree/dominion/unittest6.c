#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{

int i, j, m;
  int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
  int seed = 1000;
  int numPlayers = 2;
  int player=0;
struct gameState state, test;
int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
initializeGame(numPlayers, k, seed, &state); //set up the game

printf("\n----------Testing feaset Card----------\n");

memcpy(&test, &state, sizeof(struct gameState));// clear memory
cardEffect(feast, choice1, choice2, choice3, &state, handpos, &bonus);
player = whoseTurn(&test);

	if(test.handCount[player] == state.handCount[player])
		printf("Passed hand count is correct\n");
	else
		printf("Failed hand count is not correct\n");


	if(state.hand[player][test.handCount[player]] != -1)
		printf("Passed where feast card was added to the players hand\n");
	else
		printf("Failed where feast card was not added to the players hand\n");


	if(test.playedCardCount+1 == state.playedCardCount)
		printf("Passed where player played feast card\n");
	else
		printf("Failed where player did not play feast card\n");


	if(test.discardCount[player] == state.discardCount[player])
		printf("Passed where the feast was discarded\n");
	else
	{
		printf("Failed where the feast was not discarded.\n");
	}

  if(test.coins+5 == state.coins)
		printf("Passed where the feast was add coins.\n");
	else
	{
		printf("Failed where the feast was not add coins.\n");
	}
