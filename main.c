#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intro/intro.h"
#include "input_filters/input_filters.h"
#include "Armstrong_Numbers/armstrong_numbers.h"


#define BUFFER_SIZE 4096

int main(void) {


int choice = intro();

switch (choice)
{
    case 1:
        armstrong_numbers();
      break;

    case 2:
      // statements
      break;
    
    default:
      // default statements
        break;
}

    
  return 0;
}

