#include <stdio.h>
#include <stdlib.h>
#include "Armstrong_Numbers/armstrong_numbers.h"

int main(void) {

  char *introMessage = 
    "Hello! Welcome to my personal algorithm library! :)\n\n"
    "Displayed below is a list of available algorithms you can explore.\n\n"
    "Please enter the corresponding number of the algorithm you'd like to use into the console:\n\n";

    char algorithmList[][100] = {
    "1. Armstrong Numbers\n",
    "2. Hamming Distance between DNA Strands\n"};
    int algorithmListLength = sizeof(algorithmList)/sizeof(algorithmList[0]);

      printf("%s", introMessage);
    for (int i; i<algorithmListLength;i++){
    printf("%s", algorithmList[i]);
    }

    char userInput[10];
    scanf("%s", userInput);
printf("reached");
    isdigit(userInput) ? printf("\n"):printf("Please enter a valid number!");
    
    int num = (int) userInput;
    
    printf("Your choice was %s", algorithmList);

    
  armstrong_numbers_tests();
  return 0;
}