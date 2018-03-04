#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    
    printf("Testing Outpost\n");
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
    
    int numPlayed=0;
    numPlayed = state->playedCardCount;
    printf("Number of Played Before Card Effect: %d\n", numPlayed);
    
    int numOut=0;
    numOut = state->outpostPlayed;
    printf("Number of Outpost Played Before Card Effect: %d\n", numOut);
    
    
    for(i=0; i<state->handCount[currPlayer];i++){
        
        
        currCard = state->hand[currPlayer][i];
        printf("Card Number: %d\n", currCard);
        
    }
    
    //Testing Outpost
    state->hand[currPlayer][hPosition]=outpost;
    
    printf("\nSet Outpost as First Hand Position\n");
    for(i=0; i<state->handCount[currPlayer];i++){
        
        
        currCard = state->hand[currPlayer][i];
        printf("Card Number After Card Set: %d\n", currCard);
    }
    
    cardEffect(outpost,c1,c2,c3,state,hPosition,&bonus);
    
    
    //After Values
    printf("\nAfter Values\n");
    printf("Hand Count After Card Effect: %d\n", state->handCount[currPlayer]);
    
    
    printf("Number of Actions After Card Effect: %d\n", state->numActions);
    
    for(i=0; i<state->handCount[currPlayer];i++){
        
        
        currCard = state->hand[currPlayer][i];
        printf("Card Number After Card Effect: %d\n", currCard);
    }
    
    printf("Number of Cards Played After Card Effect: %d\n", state->playedCardCount);
    
    printf("Number of Outpost Played After Card Effect: %d\n", state->outpostPlayed);
    
    //Checking and Comparing Values Before vs. After Card Effect
    int cError = 0;
    
    //Check Hand Count: -1
    if(currHand-1 != (state->handCount[currPlayer]))
    {
        cError++;
        printf("Hand Count Checked: FAILED!\n");
        printf("Expected: 4, Actual: %d\n", state->handCount[currPlayer]);
        
    }
    else{
        printf("Hand Count Checked: Okay!\n");
    }
    
    //Check Number of Actions: No Change
    if(state->numActions != numAct)
    {
        cError++;
        printf("Number of Actions Checked: FAILED!\n");
        printf("Expected: 1, Actual: %d\n", state->numActions);
    }
    else{
        printf("Number of Actions Checked: Okay!\n");
    }

    //Check Play Count: +1
    if(state->playedCardCount != (numPlayed+1))
    {
        cError++;
        printf("Played Card Count Checked: FAILED!\n");
        printf("Expected: 1, Actual: %d\n", state->playedCardCount);
    }
    else{
        printf("Played Card Count Checked: Okay!\n");
    }
    
    //Check Outpost Played Count: +1
    if(state->outpostPlayed != numOut+1)
    {
        cError++;
        printf("Outpost Played Card Count Checked: FAILED!\n");
        printf("Expected: 1, Actual: %d\n", state->outpostPlayed);
    }
    else{
        printf("Played Card Count Checked: Okay!\n");
    }
    printf("Total Errors: %d\n", cError);
    return 0;
    
}
