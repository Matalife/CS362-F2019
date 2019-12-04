#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

int main(){
struct gameState K,Z;
int k[3] = {minion, mine, baron};
int j = 0;
initializeGame(2, k, 1000, &K);

printf("\n ----------- start testing ambassador function -----------\n");
memcpy(&Z, &K, sizeof(struct gameState));
cardeffect(ambassador, 0, 0, 0, &K, 0);
int num_test = j;
if (num_test == &K->hadCount[currentPlayer]){
	printf("Test passed!\n");
}
else{
	printf("Test failed!\n");
}
printf("Test completed!\n");
return 0;
}
