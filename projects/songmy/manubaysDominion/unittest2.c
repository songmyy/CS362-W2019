//unit test to check game ends properly

#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"



//helper functions
int ifFailed = 0;
int ifAnyFailed() {
  return ifFailed;
}

int main() {

  //ends when all cards used up
  struct gameState* state2 = malloc(sizeof(struct gameState));
  int i;
  for (i = 0; i < 25; i++) {
    state2->supplyCount[i] = 0;
  }
  int result2 = isGameOver(state2);
  if (1 == result2){
    printf("PASS: isGameOver: no more cards in supply(%d)\n" , result2);
  }
  else{
    printf("FAIL: isGameOver: expected != actual (%d != %d)\n", 1, result2);
    ifFailed = 1;
  }

  //ends when all province cards used
  struct gameState* state1 = malloc(sizeof(struct gameState));
  state1->supplyCount[province] = 0;
  int result1 = isGameOver(state1);
  if (1 == result1){
    printf("PASS: isGameOver: province cards all used (%d)\n" , result1);
  }
  else{
    printf("FAIL: isGameOver: expected != actual (%d != %d)\n", 1, result1);
    ifFailed = 1;
  }

  //game should not end if there are still cards and return 0 
  struct gameState* state3 = malloc(sizeof(struct gameState));
  for (i = 0; i < 25; i++) {
    state3->supplyCount[i] = 10;
  }
  int result3 = isGameOver(state3);
  if (0 == result3){
    printf("PASS: isGameOver: cards not all used - did not end (%d)\n" , result3);
  }
  else{
    printf("FAIL: isGameOver: expected != actual (%d != %d)\n", 0, result3);
    ifFailed = 1;
  }

  if (!ifAnyFailed()) {
    printf("TEST SUCCESS\n");
  } else {
    printf("TEST FAILED\n");
  }
}