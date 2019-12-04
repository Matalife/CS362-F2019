#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void main ()
{
	struct gameState state;
	int i = 0;

 	printf("\n----------Start Testing Update Coins ----------\n");


	//COPPER
	printf("\nTesting copper\n");
	for (i = 0; i < 10; i++)
		state.hand[0][i] = copper;

	updateCoins(0,&state, 0);

	if(state.coins == 10)
		printf("\nPassed where copper is %d/10\n", state.coins);
	else
		printf("\nFailed where copper is %d/10\n", state.coins);


	//SILVER
	printf("\nTesting silver\n");
	for (i = 0; i < 10; i++)
		state.hand[0][i] = silver;

	updateCoins(0,&state, 0);

	if(state.coins == 20)
		printf("\nPassed where silver is %d/20\n", state.coins);
	else
		printf("\nFailed where silver is %d/20\n", state.coins);


	//GOLD
	printf("\nTesting gold\n");
	for (i = 0; i < 10; i++)
		state.hand[0][i] = gold;

	updateCoins(0,&state, 0);

	if(state.coins == 30)
		printf("\nPassed where gold is %d/30\n", state.coins);
	else
		printf("\nFailed where gold is %d/30\n", state.coins);


	//Bonus Copper
	printf("\nTesting copper + 1 bonus\n");
	for (i = 0; i < 10; i++)
		state.hand[0][i] = copper;

	updateCoins(0,&state, 1);

	if(state.coins == 11)
		printf("\nPassed where copper + 1 bonus is %d/11\n", state.coins);
	else
		printf("\nFailed where copper + 1 bonus is %d/11\n", state.coins);


 	printf("\n----------Start Testing Update Coins ----------\n");
}
