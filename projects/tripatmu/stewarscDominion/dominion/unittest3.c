#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main(){

    printf("Testing getCost\n");
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
    
    printf("\nInitial Values\n");
    int i = 0;
    int cost = 0;
    for (i = 0; i < 27; i++){
        cost = getCost(i);
        printf("Card Number: %d, Cost: %d\n", i, cost);
    }

    int currHand = 0;
    
    //Testing
    int uErrors = 0;
    
    //Check Card Cost: Adventurer
    if(getCost(adventurer) != 6)
    {
        uErrors++;
        printf("\nCard Cost Checked: FAILED!\n");
        printf("Expected: 5, Actual: %d\n", currHand);
    }
    else{
        printf("\nCard Cost Checked: Okay!\n");
    }
    
    //Check Card Cost: Smithy
    if(getCost(smithy) != 4)
    {
        uErrors++;
        printf("Card Cost Checked: FAILED!\n");
        printf("Expected: 4, Actual: %d\n", currHand);
    }
    else{
        printf("Card Cost Checked: Okay!\n");
    }
    
    //Check Card Cost: Silver
    if(getCost(silver) != 3)
    {
        uErrors++;
        printf("Card Cost Checked: FAILED!\n");
        printf("Expected: 3, Actual: %d\n", currHand);
    }
    else{
        printf("Card Cost Checked: Okay!\n");
    }
    
    //Check Card Cost: Feast
    if(getCost(feast) != 4)
    {
        uErrors++;
        printf("Card Cost Checked: FAILED!\n");
        printf("Expected: 4, Actual: %d\n", currHand);
    }
    else{
        printf("Card Cost Checked: Okay!\n");
    }
   
    //Check Card Cost: Council Hall
    if(getCost(council_room) != 5)
    {
        uErrors++;
        printf("Card Cost Checked: FAILED!\n");
        printf("Expected: 5, Actual: %d\n", currHand);
    }
    else{
        printf("Card Cost Checked: Okay!\n");
    }
    printf("Total Errors: %d\n", uErrors);


    return 0;

}
