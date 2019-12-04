#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

int main(){
struct gameState K,Z;
int k[3] = {minion, mine, baron};
initializeGame(2, k, 1000, &K);
printf("\n ----------- start testing tribute function -----------\n");
memcpy(&Z, &K, sizeof(struct gameState));
cardeffect(tribute, 0, 0, 0, &K, 0);
int num_test = ributeRevealedCard[1];
if (num_test == 1){
	printf("Test passed!\n");
}
else{
	printf("Test failed!\n");
}
printf("Test completed!\n");
return 0;
}
