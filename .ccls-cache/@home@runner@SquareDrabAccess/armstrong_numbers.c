#include "armstrong_numbers.h"
   #include <stdio.h>
#include <stdbool.h>
#include <math.h>

   bool is_armstrong_number (int candidate) {
    int digit, result;
       int candidateCopy = candidate;
       int length = log10(candidate)+1;
    
    while(candidate>0)
    {
        digit = candidate%10;
        result += pow(digit, length);
        candidate = candidate/10;
    }
       return result==candidateCopy;
   }