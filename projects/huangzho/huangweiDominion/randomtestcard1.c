#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include<stdlib.h>
#include<time.h>
#include "rngs.h"

#define MAXITERATIONS 100

int num_random (int lower, int upper) {

    int randNum = (rand() % (upper - lower + 1)) + lower;
    return randNum;
    
}

void hand_print(struct gameState *state, int currentPlayer) {
    for (int i = 0; i < state->handCount[currentPlayer]; i++){
        printf("Hand Number: %d Type Number: %d\n", i, state->hand[currentPlayer][i]);

    }
}

enum CARD randCard() {

    enum CARD card;
    card = num_random(0, 26);
    return card;
}

int estateCardFound(struct gameState *state, int currentPlayer) {
    for (int i = 0; i < state->handCount[currentPlayer]; i++){
        if(state->hand[currentPlayer][i] == estate){
            return 1;
        }    
    }
    return 0;
}

int numberOfEstates(struct gameState *state, int currentPlayer) {

    int numEstates = 0;

    for (int i = 0; i < state->handCount[currentPlayer]; i++){
        if(state->hand[currentPlayer][i] == estate){
            numEstates++;
        }    
    }
    return numEstates;
}

int main () {
    printf("Testing the function baronCardEffect():\n\n");
    struct gameState game, testGame;
    int done = MAXITERATIONS;
    float interationNum = 0;
    float numTestsPassed, numTestsFailed = 0;
    float proportionFail, proportionPass;
    while (done !=0) {

        int seed = 1000;
        int numPlayers = num_random(2, 4);
        int choice1 = num_random(-5, 5);
        int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall };
        int currentPlayer = 0;
        int numCardsInHand, estatesBefore, estatesAfter, estateFlag = 0;
        int c = 0;
        enum CARD randoCard = 0;
        initializeGame(numPlayers, k, seed, &game);

        printf("ITERATION NUMBER: %.0f\n", interationNum + 1);
        printf("numPlayers = %d\n", numPlayers);

        for (int j = 0; j < 10; j++) {
            printf("Kingdom card %d = %d\n",j , k[j]);
        }

        // get the number of cards in hand
        numCardsInHand = game.handCount[currentPlayer];

        printf("Hand Count: %d\n", numCardsInHand);

        //set hand to random cards
        for (c = 0; c < numCardsInHand; c++) {
            randoCard = randCard();
            game.hand[currentPlayer][c] = randoCard;
        }

        // print hand
        printf("Hand Before: \n");
        hand_print(&game, currentPlayer);

        // copy gameState Game to a new test gameState testGame
        memcpy(&testGame, &game, sizeof(struct gameState));
    
        // call baronCardEffect with the test game
        baronCardEffect(choice1, &testGame, currentPlayer);

        // print hand
        printf("Hand After: \n");
        hand_print(&testGame, currentPlayer);

        // get the number of estate cards before an after
        estatesBefore = numberOfEstates(&game, currentPlayer);
        estatesAfter = numberOfEstates(&testGame, currentPlayer);

        // print out the expectations
        if (choice1 > 0) {
            printf("Choice = %d.\n", choice1);
            printf("** Expect: +4 Treasure if Estate card is in hand. **\n");

            // check if an estate card is the current player's hand
            estateFlag = estateCardFound(&game, currentPlayer);

            // check to see if 4 coins have been added to game and function returned proper value
            if (estateFlag == 1 && testGame.coins == game.coins + 4) {
                printf("PASSED: Treasure before: %d, Treasure after: %d\n", game.coins, testGame.coins);
                printf("PASSED: Choice > 0, Estate Card in hand, correctly increased treasure.\n");

                numTestsPassed++;
            }

            if (estateFlag == 1 && testGame.coins != game.coins + 4) {
                printf("FAILED: Treasure before: %d, Treasure after: %d\n", game.coins, testGame.coins);
                printf("FAILED: Choice1 > 0, Estate Card in hand, failed to increase treasure.\n");
                
                numTestsFailed++;
            }

            if (estateFlag == 0 && testGame.coins == game.coins + 4) {
                printf("FAILED: Treasure before: %d, Treasure after: %d\n", game.coins, testGame.coins);
                printf("FAILED: Choice1 > 0, Estate Card NOT in hand, erroneously increased treasure.\n");

                numTestsFailed++;
            }

            if (estateFlag == 0 && testGame.coins != game.coins + 4) {
                printf("PASSED: Treasure before: %d, Treasure after: %d\n", game.coins, testGame.coins);
                printf("PASSED: Choice > 0, Estate Card NOT in hand, correctly didn't increase treasure.\n");
                
                numTestsPassed++;
            }

        }
        if (choice1 <= 0){
            printf("Choice = %d\n", choice1);
            printf("** Expect: +1 Estate Card AND +0 Treasure. **\n");

            // check if an estate card is the current player's hand
            //estateFlag = estateCardFound(&game, currentPlayer);

            if(estatesAfter == estatesBefore + 1 && game.coins == testGame.coins) {

                printf("PASSED: Estate cards before: %d, Estate cards after: %d\n", estatesBefore, estatesAfter);
                printf("PASSED: Choice <= 0, Estate Card number increased, treasure stayed the same.\n");
                numTestsPassed++;
            }

            else {

                printf("FAILED: Estate cards before: %d, Estate cards after: %d\n", estatesBefore, estatesAfter);
                printf("FAILED: Treasure before: %d, Treasure after: %d\n", game.coins, testGame.coins);
                numTestsFailed++;
            }

        }

        printf("\n");
        
        done--;
        interationNum++;

    }

    proportionPass = (numTestsPassed / interationNum);
    proportionFail = (numTestsFailed / interationNum);

    printf("****************************** SUMMARY **********************************\n\n");


    printf("Test Pass Proportion: %.4f\n", proportionPass);
    printf("Test Fail Proportion: %.4f\n\n", proportionFail);

    printf("****************************** function baronCardEffect test end **********************************\n\n");


}
