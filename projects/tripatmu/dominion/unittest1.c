#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){

    printf("Testing numHandCount\n");
    printf("Initialize Game\n");
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
    
    int currHand = 0;
    int currPlayer = 0;
    
    printf("\nInitial Values\n");
    currHand = state->handCount[currPlayer];
    printf("Hand Count: %d\n", currHand);
    
    //Testing
    int uErrors = 0;
    
    //Check Hand Count: 5
    if(currHand != 5)
    {
        uErrors++;
        printf("Hand Card Count Checked: FAILED!\n");
        printf("Expected: 5, Actual: %d\n", currHand);
    }
    else{
        printf("Hand Count Checked: Okay!\n");
    }
    
    state->handCount[currPlayer] = 3;
    currHand = 3;
    
    //Check Hand Count: 3
    if((currHand) != 3)
    {
        uErrors++;
        printf("Hand Card Count Checked: FAILED!\n");
        printf("Expected: 5, Actual: %d\n", currHand);
    }
    else{
        printf("Hand Count Checked: Okay!\n");
    }
    
    //Check Hand Count: 4
    drawCard(whoseTurn(state), state);
    if((currHand+1) != (state->handCount[currPlayer]))
    {
        uErrors++;
        printf("Hand Card Count Checked: FAILED!\n");
        printf("Expected: 5, Actual: %d\n", currHand);
    }
    else{
        printf("Hand Count Checked: Okay!\n");
    }
    
    printf("Total Errors: %d\n", uErrors);
    
    return 0;

}
