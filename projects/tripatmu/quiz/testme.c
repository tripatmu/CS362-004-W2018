#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    
    //Initial Variable
    char randChar = '\0';
    int randVal = 0;
    
    //Random ASCII Value from 32 - 126
    randVal = (rand() % ((126 + 1) - 32)) + 32;
    
    //Typecast integer to character value
    randChar = (char)randVal;
    
    //Return Character
    return randChar;
}

char *inputString()
{
    // TODO: rewrite this function
    
    //Initial Variables for Random Size
    //int size = 0;
    int randSize = 0;
    
    //Random string size from 10 to 100
    //randSize = (rand() % ((100 + 1) - 10)) + 10;
    
    //Set Size to be 5 for character reset
    randSize = 5;

    //Initial Variables for Random String
    char* randString = malloc(randSize+1);
    int i = 0;
    
    //First letter in uppercase with ASCII range from 65 to 90
    //randString[i] = (rand() % ((90 + 1) - 65)) + 65;
    
    //Following letters in lowercase with ASCII range from 97 to 122
    for (i=0; i<randSize; i++){
        
        randString[i] = (rand() % ((122 + 1) - 97)) + 97;
    }
    
    //End string with a null terminator
    randString[i+1] = '\0';
    
    //Return String
    return randString;
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
