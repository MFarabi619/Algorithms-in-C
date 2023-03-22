#include "armstrong_numbers.h"

void armstrong_numbers_tests (){

int testNum[9]={
  0,5,10,153,100,9474,9475,9926315,9926314
  };

  char testExpected[9][6]={
  "true","true","false","true","false","true","false","true","false"
  };

  for (int i=0; i<9;i++){
        char * result = formatBool(is_armstrong_number(testNum[i]));
        printf("Expected %s for %d, got %s.\n",testExpected[i], testNum[i], result);
  }
    
    }