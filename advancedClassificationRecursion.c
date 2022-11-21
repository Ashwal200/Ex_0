#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//is armstrong recursion func

int isArmstrongByRcurse2(int numToCheck, int nDigits){
   if (numToCheck == 0){
       return 0;
   }
   return pow(numToCheck%10, nDigits) + isArmstrongByRcurse2(numToCheck/10, nDigits);
}
int isArmstrong(int num){
   int nDigits = floor(log10(abs(num))) + 1;
   return num == isArmstrongByRcurse2(num, nDigits);
}

// is palindrom recursion func


int isPalindromeByRecurse2(int numToCheck, int length){
   if(length <= 1){
       return 0;
   }
   int divaider = pow(10, length-1);
   int firstDigit = numToCheck/divaider;
   int lastDigit = numToCheck%10;
   int numberToSend = (numToCheck - divaider*firstDigit)/10;
   int numAns = 1;
   if(firstDigit == lastDigit) {
       numAns = 0;
   }
   return numAns + isPalindromeByRecurse2(numberToSend, length-2) ;
}
int isPalindrome(int num){
   int length = floor(log10(abs(num))) + 1;
   if(isPalindromeByRecurse2(num, length) == 0){
       return 1;
   }
   else{
       return 0;
   }
}