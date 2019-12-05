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
for(int i = 0; i < 25; i++){
K.supplyCount [i] = 1;
}
K.supplyCount[24] = 0;
K.supplyCount[25] = 0;
K.supplyCount[26] = 0;
printf("\n ----------- start testing isGameOver function -----------\n");
memcpy(&Z, &K, sizeof(struct gameState));
int num_test = isGameOver(&K);
if (num_test == 1){
	printf("Test passed!\n");
}
else{
	printf("Test failed!\n");
}
printf("Test completed!\n");
return 0;
}
