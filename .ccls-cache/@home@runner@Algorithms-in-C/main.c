#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "Armstrong_Numbers/armstrong_numbers.h"

#define BUFFER_SIZE 4096

bool input_filter_int(char *string, int *integer);

int main(void) {

  char *introMessage = 
    "NOTE: THIS PROJECT IS A WORK IN PROGRESS!\n\n"
    "Hello! Welcome to my personal algorithm library! :)\n\n"
    "Displayed below is a list of available algorithms you can explore.\n\n"
    "Please enter the corresponding number of the algorithm you'd like to use into the console:\n\n";

    char algorithmList[][100] = {
    "1. Armstrong Numbers\n",
    "2. Hamming Distance between DNA Strands\n\n"};
    
    int algorithmListLength = sizeof(algorithmList)/sizeof(algorithmList[0]);

      printf("%s", introMessage);
    for (int i=0; i<algorithmListLength; i++){
    printf("%s", algorithmList[i]);
    }

    char userInput[10];
    bool userInputValid = false;
    
    while (userInputValid ==false){
    fgets(userInput, sizeof(userInput), stdin);
        userInput[strlen(userInput)-1]=0;
        // scanf("%s", userInput);
        // printf("reached");
    // userInputValid = isdigit(userInput);
        // printf("%d", userInputValid);
        printf("\nYour input was: %s\n", userInput);
        printf("Valid inputs are between %d-%d!", 1, algorithmListLength);
        if (userInputValid){break;}
        else printf("\nPlease enter a valid number!\n\n");
    }
    
    
    int num = (int) userInput;
    
    printf("\n\nYour choice was %s\n\n", algorithmList[(int) userInput]);

    
  armstrong_numbers_tests();
  return 0;
}

bool input_filter_int(char *string, int *integer){
int i = 0; //Track current index

    while(isspace(string[i])) i++; //Find the first non-whitespace character

    int length = strlen(string); //Get length of string

    if (length == i) return false; //String is blank and thus invalid

    char integer_buffer[BUFFER_SIZE];//Used to store integers found in string
    int integer_chars = 0; //Used to keep track of integer_buffer index

    //If first character is a minus symbol, add it to the integer buffer
    if (string[i]== '-') {
        integer_buffer[integer_chars] ='-';
        integer_chars++;
        i++;
        
        //If the chracter after the '-' symbol is not a number, input is invalid
    if (!isdigit(string[i])) return false;
    }

    return true;
    
}