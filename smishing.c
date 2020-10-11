/*
  This code will detect the number of keywords common in an SMS phishing message using string tokenizing.

  --Brandon Yates
*/

#include <stdio.h>
#include <string.h>
#define MAX_CHAR 1000
#define MAX_WORDS 500

int read_line(char *str, int n);


int main()
{
  char message[MAX_WORDS]; //this is array that will be filled from the tokenization.
  int i = 0;

  //keywords are the words that will be searched for.
  char keywords[][20] = {"suspended", "locked", "bank", "update", "statement", "personal",
                      "click", "compromised", "deactivated", "reactivate", "account",
                      "alert", "confirm", "won", "selected", "claim", "urgent", "disabled",
                      "expire"};


  printf("Input: ");

  read_line(message, MAX_CHAR-1);

  printf("\nOutput: \n");


  char *pch;
  pch = strtok(message," ,.!");//*pch is the pointer that is returned from strtok. delimiters include white space, ,, ., and !

  while(pch != NULL)//required to test if pch ends.
  {

    for(i = 0; i < 19; i++)//loops through the spots in keywords[i].
    {

        if(strcmp(keywords[i], pch) == 0)//compare keywords[i] to array in pch.
        {
            printf("%s\n", keywords[i]);
            break;
        }
    }

    pch = strtok(NULL," ,.!");//terminates the while loop
  }

  return 0;
}

int read_line(char *str, int n)
{
          int ch; int i = 0;

          while ((ch = getchar()) != '\n')
          {  if (i < n)
             { *str++= ch;
	      i++;
             }
	  }
          *str = '\0';   /* terminates string */
          return i;        /* number of characters stored */
}
