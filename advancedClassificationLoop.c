#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isArmstrong(int num){
   int numToCheck = num;
   int sum = 0;
   int nDigits = floor(log10(abs(numToCheck))) + 1;
   while(numToCheck != 0){
       int lastDigit = numToCheck%10;
       sum += pow(lastDigit, nDigits);
       numToCheck = numToCheck/10;
   }
   return sum == num;
}


int isPalindrome(int num){
   int numToCheckStart = num;
   int numToCheckEnd = num;
   int length = floor(log10(abs(numToCheckStart))) + 1;
   int divaider = pow(10, length-1);
   for (int i = 0; i < length/2; ++i) {
       int start = (numToCheckStart/divaider)%10;
       int end = numToCheckEnd%10;
       if (start != end){
           return 0;
       }
       numToCheckStart = numToCheckStart/10;
       divaider = divaider/10;
   }
   return 1;
}

