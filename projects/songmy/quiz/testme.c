//Name: Myung Jin Song
//Date: 02-10-19
//Assignment: CS362 - Random Testing Quiz
//Will create random characters and strings which will be compared
//and cause program to end when final if statement is produced 
//random character and string selection will be set so that
//only the target statements are produced

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
  // TODO: rewrite this function

  //create an array containing the 9 possible characters for c in testme function
  char randomChar;
  char cStates[9] = "[({ ax})]";

  //generate and return random character with max limit of 9 possibilities
  randomChar = cStates[rand() % 9];
  return randomChar;
}

char *inputString()
{
  // TODO: rewrite this function

  //create array containing possible letters for s in testme function
  char sStates[5] = "rest";

  //generate and return random sequence of letters as the string
  //use loop to set each position with random letter to form 4 letter string
  //with /0 to end the string
  int i;
  char *randomString = malloc(sizeof(char) * 5);
  for (i = 0; i < 5; i++) {
    randomString[i] = sStates[rand() % 5];
  }
  //had to set last letter as 0 to end the string
  //was not sure how to accomplish this part randomly 
  randomString[5] = '\0';
  return randomString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
      && s[2] == 's' && s[3] == 'e'
      && s[4] == 't' && s[5] == '\0'
      && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
  srand(time(NULL));
  testme();
  return 0;
}
