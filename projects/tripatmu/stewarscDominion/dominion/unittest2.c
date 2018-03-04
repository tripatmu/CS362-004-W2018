#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){

    printf("Testing buyCard\n");
    printf("\nInitialize Game\n");
    struct gameState *state = newGame();
    int numPlayers = 2;
    int randomSeed = 1;
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    //Initialize game
    int gameStart = initializeGame(numPlayers, kingdomCards, randomSeed, state);
    
    if(gameStart == 0){
        
        printf("Initialization Successful!\n");
    }
    else{
        
        printf("Initialization FAIL!\n");
    }
    
    int returnVal = 0;
    state->numBuys = 1;
    state->coins = 9;
    
    printf("\nInitial Values\n");
    printf("Number of Buys: %d\n", state->numBuys);
    printf("Number of Gold: %d\n", state->coins);
    
    //Testing
    int uErrors = 0;
    
    //Buy Adventurer
    returnVal = buyCard(adventurer, state);
    
    if(returnVal != 0)
    {
        uErrors++;
        printf("Buy Card Checked: FAILED!\n");
        printf("Expected: 0, Actual: %d\n", returnVal);
    }
    else{
        printf("Buy Card Checked: Okay!\n");
    }
    
    printf("Remaining Number of Buys: %d\n", state->numBuys);
    printf("Remaining Number of Gold: %d\n", state->coins);
    
    //Check Number of Buys
    if(state->numBuys != 0)
    {
        uErrors++;
        printf("Number of Buys Checked: FAILED!\n");
        printf("Expected: 0, Actual: %d\n", returnVal);
    }
    else{
        printf("Number of Buys Checked: Okay!\n");
    }
    
    //Buy Card
    returnVal = buyCard(silver, state);
    
    printf("Remaining Number of Buys: %d\n", state->numBuys);
    
    if(returnVal != -1)
    {
        uErrors++;
        printf("Buy Card Checked: FAILED!\n");
        printf("Expected: 0, Actual: %d\n", returnVal);
    }
    else{
        printf("Buy Card Checked: Okay!\n");
    }
    
    
    //Buy Silver
    state->numBuys = 2;
    printf("Remaining Number of Buys: %d\n", state->numBuys);
    printf("Remaining Number of Gold: %d\n", state->coins);
    returnVal = buyCard(silver, state);
    if(returnVal != 0)
    {
        uErrors++;
        printf("Buy Card Checked: FAILED!\n");
        printf("Expected: 0, Actual: %d\n", returnVal);
    }
    else{
        printf("Buy Card Checked: Okay!\n");
    }
    
    
    //Check Coins
    printf("Remaining Number of Buys: %d\n", state->numBuys);
    printf("Remaining Number of Gold: %d\n", state->coins);
    if(state->coins != 0)
    {
        uErrors++;
        printf("Number of Coins Checked: FAILED!\n");
        printf("Expected: 0, Actual: %d\n", returnVal);
    }
    else{
        printf("Number of Coins Checked: Okay!\n");
    }
    
   
    //Buy Coins
    returnVal = buyCard(silver, state);
    if(returnVal != -1)
    {
        uErrors++;
        printf("No Coins Buy Card Checked: FAILED!\n");
        printf("Expected: 0, Actual: %d\n", returnVal);
    }
    else{
        printf("No Coins Buy Card Checked: Okay!\n");
    }

    
    printf("Total Errors: %d\n", uErrors);


    return 0;

}
