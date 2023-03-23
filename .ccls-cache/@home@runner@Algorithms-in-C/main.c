#include "Armstrong_Numbers/armstrong_numbers.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

bool input_filter_int(char *string, int *integer);

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
            printf("\nPlease enter a valid number within the range!\n\n");
            userInputValid = false;      
        }
    } else
    printf("Valid inputs are between %d-%d!", 1, algorithmListLength);
      printf("\nPlease enter a valid number!\n\n");
  }

  printf("\n\nYour choice was:\n %s\n\n", algorithmList[inputNum-1]);

  return 0;
}

bool input_filter_int(char *string, int *integer) {
  int i = 0; // Track current index

  while (isspace(string[i]))
    i++; // Find the first non-whitespace character

  int length = strlen(string); // Get length of string

  if (length == i)
    return false; // String is blank and thus invalid

  char integer_buffer[BUFFER_SIZE]; // Used to store integers found in string
  int integer_chars = 0; // Used to keep track of integer_buffer index

  // If first character is a minus symbol, add it to the integer buffer
  if (string[i] == '-') {
    integer_buffer[integer_chars] = '-';
    integer_chars++;
    i++;

    // If the chracter after the '-' symbol is not a number, input is invalid
    if (!isdigit(string[i]))
      return false;
  }

  // Keep looping until end of string or trailing whitespace is encountered
  while (i < length && !isspace(string[i])) {
    // Number is not a digit, invalid input
    if (!isdigit(string[i]))
      return false;

    //Store number into buffer and increment both indices
    integer_buffer[integer_chars] = string[i];
    integer_chars++;
    i++;
  }

    //Append null terminator to end of buffer to make it a valid string
integer_buffer[integer_chars] = '\0';

    //Loop through trailing whitespace characters
while (isspace(string[i])) i++;

    //If i is not at the end of the string, then a non-whitespace character was found. Thus string is invalid.
if (string[i] != '\0') return false;

//Convert string to int
    
*integer = atoi(integer_buffer);
    
  return true;
}