#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int testSize = 10000;
    int testPass = 0;
    int testFail = 0;
    
    printf("Testing Adventurer\n");
    
    //Set up intial game state
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int bonus = 0;
    int i = 0;
    
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    //Loop for random testing
    for (i=0; i<testSize; i++){
    
        //Variable for testing and error counts
        int currHand = 0;
        int hPosition = 0;
        int cError = 0;
        
        srand(0);
        
        //Initialize game
        //Randomize number of players and seed for the game
        struct gameState *state = newGame();
        int numPlayers = (rand() % MAX_PLAYERS) + 1;
        int randomSeed = rand();
     
        //Initialize game
        int gameStart = initializeGame(numPlayers, kingdomCards, randomSeed, state);
        
        if(gameStart != 0){
            
            cError++;
        }
        
        //Randomize game state variables
        int currPlayer = rand() % numPlayers;
        state->handCount[currPlayer] = rand() % MAX_HAND;
        state->deckCount[currPlayer] = rand() % MAX_DECK;
        state->discardCount[currPlayer] = rand() % MAX_HAND;
        
        //Get current state of the game
        currHand = state->handCount[currPlayer];
        
        int numAct=0;
        numAct = state->numActions;
        
        int numCoins=0;
        updateCoins(currPlayer, state, bonus);
        numCoins = state->coins;
        
        int numPlayed=0;
        numPlayed = state->playedCardCount;

        
        //Testing Adventurer
        state->hand[currPlayer][hPosition]=adventurer;

        playCard(hPosition,c1,c2,c3,state);
        
        updateCoins(currPlayer, state, bonus);
        
        //Checking and Comparing Values Before vs. After Card Effect
        //printf("Random Testing Run: %d\n", i);
        
        //Check Hand Count: Greater than or equal to +1
        if(currHand+1 >= (state->handCount[currPlayer]))
        {
            cError++;
        }
        
        //Check Number of Actions: No Change
        if(state->numActions != numAct)
        {
            cError++;
        }
        
        //Check Coins: Greater than Before
        if(state->coins < numCoins)
        {
            cError++;
        }
      
        //Check Play Count: No Change
        if(state->playedCardCount != numPlayed)
        {
            cError++;
        }
        
        //Check for any errors
        if(cError > 0)
        {
            
            testFail = testFail + 1;
        }
        else
        {
            
            testPass = testPass + 1;
        }
       
        
    }
    
    //Print summary report
    printf("Total Tests: %d\n",testSize);
    printf("Tests Passed: %d\n",testPass);
    printf("Tests Failed: %d\n",testFail);
    
    return 0;

}
