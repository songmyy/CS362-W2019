//unit test to insure proper coin counts

#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

//helper functions
int ifFailed = 0;
int ifAnyFailed() {
  return ifFailed;
}

void testCoin(int coinType, int coinAmount, int points) {

  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  state1->handCount[playerIndex] = 1;
  state1->hand[playerIndex][0] = coinType;
  updateCoins(playerIndex, state1, points);
  printf("Checking coins for card type %d and points %d\n", coinType, points);

  if (coinAmount == state1->coins){
      printf("PASS: updateCoins: sum of coins (%d)\n" , state1->coins);
  }
  else{
    printf("FAIL: updateCoins: expected != actual (%d != %d)\n", coinAmount, state1->coins);
    ifFailed = 1;
  }
}

int main() {

  testCoin(copper, 1, 0);
  testCoin(silver, 2, 0);
  testCoin(gold, 3, 0);

  if (!ifAnyFailed()) {
    printf("TEST SUCCESS\n");
  } else {
    printf("TEST FAILED\n");
  }
}