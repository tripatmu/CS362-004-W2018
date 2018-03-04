#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){

    printf("Testing updateCoins\n");
    printf("Initialize Game\n");
    struct gameState *state = newGame();
    int numPlayers = 2;
    int randomSeed = 1;
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    int gameStart = initializeGame(numPlayers, kingdomCards, randomSeed, state);
    
    if(gameStart == 0){
        
        printf("Initialization Successful!\n");
    }
    else{
        
        printf("Initialization FAIL!\n");
    }
    
    int currPlayer = 0;
    int currCard = 0;
    int hPosition = 0;
    int i = 0;
    int bonus = 0;
    
    printf("\nInitial Values\n");
    //Set Dummy Card
    state->hand[currPlayer][hPosition]=adventurer;
    for(i=0; i<state->handCount[currPlayer];i++){
        
        
        currCard = state->hand[currPlayer][i];
        printf("Card Number: %d\n", currCard);
        
    }
    
    int currCoins = 0;
    updateCoins(currPlayer, state, bonus);
    currCoins = state->coins;
    
    //Testing
    int uErrors = 0;
    
    //Check Copper Added
    state->hand[currPlayer][hPosition]=copper;
    updateCoins(currPlayer, state, bonus);
    
    if((currCoins+1) != state->coins)
    {
        uErrors++;
        printf("Update Coin Count Checked: FAILED!\n");
        printf("Expected: Coins+1, Actual: %d\n", state->coins);
    }
    else{
        printf("Update Coin Count Checked: Okay!\n");
    }
    
    //Check Silver Added
    state->hand[currPlayer][hPosition]=silver;
    updateCoins(currPlayer, state, bonus);
    
    if((currCoins+2) != state->coins)
    {
        uErrors++;
        printf("Update Coin Count Checked: FAILED!\n");
        printf("Expected: Coins+2, Actual: %d\n", state->coins);
    }
    else{
        printf("Update Coin Count Checked: Okay!\n");
    }
    
    //Check Gold Added
    state->hand[currPlayer][hPosition]=gold;
    updateCoins(currPlayer, state, bonus);
    
    if((currCoins+3) != state->coins)
    {
        uErrors++;
        printf("Update Coin Count Checked: FAILED!\n");
        printf("Expected: Coins+4, Actual: %d\n", state->coins);
    }
    else{
        printf("Update Coin Count Checked: Okay!\n");
    }
    
    printf("Total Errors: %d\n", uErrors);

    
    return 0;

}
