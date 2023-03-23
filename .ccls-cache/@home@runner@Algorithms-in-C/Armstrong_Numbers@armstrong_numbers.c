#include <stdbool.h>
#include <stdio.h>
#include "armstrong_numbers.h"
#include "../input_filters/input_filters.h"

#define BUFFER_SIZE 4096

/*A program that detects whether a number is an Armstrong number.

An Armstrong number is a number that is the sum of its own digits each raised to
the power of the number of digits.

For example:

9 is an Armstrong number, because 9 = 9^1 = 9
10 is not an Armstrong number, because 10 != 1^2 + 0^2 = 1
153 is an Armstrong number, because: 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
154 is not an Armstrong number, because: 154 != 1^3 + 5^3 + 4^3 = 1 + 125 + 64 =
190 */

char introMessage[] = "\n\nAn Armstrong number is a number that is the sum of its own digits each raised to the power of the number of digits."
"For example:\n\n"
"9 is an Armstrong number, because 9 = 9^1 = 9\n"
"10 is not an Armstrong number, because 10 != 1^2 + 0^2 = 1\n"
"153 is an Armstrong number, because: 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153\n"
"154 is not an Armstrong number, because: 154 != 1^3 + 5^3 + 4^3 = 1 + 125 + 64 =\n"
"190\n\n";

void armstrong_numbers(){
    printf(introMessage);
    bool userInputValid=false;
    char userInput[BUFFER_SIZE];
    int num = 0;
    
    do {
        printf("Please enter a number: \n");
        fgets(userInput, BUFFER_SIZE, stdin);
        userInputValid = input_filter_int(userInput, &num);
    } while (!userInputValid);

    if (is_armstrong_number(num)){
        printf("\n%d is valid Armstrong number!", num);
    }
    else printf("\n%d is not a valid Armstrong number!", num);
}

bool is_armstrong_number(int candidate) {
  int digit, result = 0;
  int candidateCopy = candidate;
  int length = log10(candidate) + 1;

  while (candidate > 0) {
    digit = candidate % 10;
    result += (int)pow(digit, length);
    candidate = candidate / 10;
  }
  return result == candidateCopy;
}
