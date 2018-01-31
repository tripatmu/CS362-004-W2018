#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    
    printf("Testing Village\n");
    //Set up intial game state
    printf("Initialize Game\n");
    struct gameState *state = newGame();
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int bonus = 0;
    int i = 0;
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
    
    
    int currHand = 0;
    int currCard = 0;
    int currPlayer = 0;
    int hPosition = 0;
    
    //Initial Values
    printf("\nInitial Values\n");
    currHand = state->handCount[currPlayer];
    printf("Hand Count Before Card Effect: %d\n", currHand);
    
    int numAct=0;
    numAct = state->numActions;
    printf("Number of Actions Before Card Effect: %d\n", numAct);
    
    int numCoins=0;
    updateCoins(currPlayer, state, bonus);
    numCoins = state->coins;
    printf("Number of Coins Before Card Effect: %d\n", numCoins);
    
    int numPlayed=0;
    numPlayed = state->playedCardCount;
    printf("Number of Played Before Card Effect: %d\n", numPlayed);
    
    for(i=0; i<state->handCount[currPlayer];i++){
        
        
        currCard = state->hand[currPlayer][i];
        printf("Card Number: %d\n", currCard);
        
    }
    
    //Testing Village
    state->hand[currPlayer][hPosition]=village;
    
    printf("\nSet Village as First Hand Position\n");
    for(i=0; i<state->handCount[currPlayer];i++){
        
        
        currCard = state->hand[currPlayer][i];
        printf("Card Number After Card Set: %d\n", currCard);
    }
    
    cardEffect(village,c1,c2,c3,state,hPosition,&bonus);
    
    
    //After Values
    printf("\nAfter Values\n");
    printf("Hand Count After Card Effect: %d\n", state->handCount[currPlayer]);
    
    
    printf("Number of Actions After Card Effect: %d\n", state->numActions);
    
    for(i=0; i<state->handCount[currPlayer];i++){
        
        
        currCard = state->hand[currPlayer][i];
        printf("Card Number After Card Effect: %d\n", currCard);
    }
    
    updateCoins(currPlayer, state, bonus);
    printf("Number of Coins After Card Effect: %d\n", state->coins);
    
    printf("Number of Cards Played After Card Effect: %d\n", state->playedCardCount);
    
    
    //Checking and Comparing Values Before vs. After Card Effect
    int cError = 0;
    
    //Check Hand Count: +1 -1
    if(currHand != (state->handCount[currPlayer]))
    {
        cError++;
        printf("Hand Count Checked: FAILED!\n");
        printf("Expected: 7, Actual: %d\n", state->handCount[currPlayer]);
        
    }
    else{
        printf("Hand Count Checked: Okay!\n");
    }
    //Check Number of Actions: +2
    if(state->numActions != numAct+2)
    {
        cError++;
        printf("Number of Actions Checked: FAILED!\n");
        printf("Expected: 3, Actual: %d\n", state->numActions);
    }
    else{
        printf("Number of Actions Checked: Okay!\n");
    }

    //Check Play Count +1
    if(state->playedCardCount != numPlayed+1)
    {
        cError++;
        printf("Played Card Count Checked: FAILED!\n");
        printf("Expected: 0, Actual: %d\n", state->playedCardCount);
    }
    else{
        printf("Played Card Count Checked: Okay!\n");
    }
    printf("Total Errors: %d\n", cError);
    return 0;
    
}
