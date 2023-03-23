#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Armstrong_Numbers/armstrong_numbers.h"
#include "input_filters/input_filters.h"

#define BUFFER_SIZE 4096

int main(void) {

  char *introMessage =
      "NOTE: THIS PROJECT IS A WORK IN PROGRESS!\n\n"
      "Hello! Welcome to my personal algorithm library! :)\n\n"
      "Displayed below is a list of available algorithms you can explore.\n\n"
      "Please enter the corresponding number of the algorithm you'd like to "
      "use into the console:\n\n";

  char algorithmList[][BUFFER_SIZE] = {"1. Armstrong Numbers\n",
                               "2. Hamming Distance between DNA Strands\n\n"};

  int algorithmListLength = sizeof(algorithmList) / sizeof(algorithmList[0]);

  printf("%s", introMessage);
  for (int i = 0; i < algorithmListLength; i++) {
    printf("%s", algorithmList[i]);
  }

  char userInput[BUFFER_SIZE];
    int inputNum=0;
    bool userInputValid = false;

  while (userInputValid == false) {
      
    fgets(userInput, BUFFER_SIZE, stdin);
    userInputValid=input_filter_int(userInput, &inputNum);
      
    printf("\nYour input was: %s\n", userInput);
    if (userInputValid) {
        if (inputNum<=algorithmListLength && inputNum>0){
        break;
        }
        else {
            printf("Please enter a valid number within the range!\n");
    printf("Valid inputs are between %d-%d!\n\n", 1, algorithmListLength);
            userInputValid = false;
            continue;
        }
    } else
    {
      printf("\nPlease enter a valid number!\n\n");
        printf("Valid inputs are between %d-%d!", 1, algorithmListLength);
    }
  }

  printf("\n\nYour choice was:\n %s\n\n", algorithmList[inputNum-1]);

    

  return 0;
}

