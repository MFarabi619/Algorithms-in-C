
   #include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define formatBool(b) ((b) ? "true" : "false")

   bool is_armstrong_number (int candidate) {
    int digit, result=0;
       int candidateCopy = candidate;
       int length = log10(candidate)+1;
    
    while(candidate>0)
    {
        digit = candidate%10;
        result += (int) pow(digit, length);
        candidate = candidate/10;
    }
       return result==candidateCopy;
   }


    void test (int num, char *expected){
        char * result = formatBool(is_armstrong_number(num));
        printf("Expected %s for %d, got %s.\n",expected, num, result);
    }

   int main() {
       int testNum[9]={
       0,5,10,153,100,9474,9475,9926315,9926314
       };
       
       char testExpected[9][6]={
       "true","true","false","true","false","true","false","true","false"
       };

       for (int i=0; i<9;i++){
           test(testNum[i],testExpected[i]);
       }
       return 0;
   }