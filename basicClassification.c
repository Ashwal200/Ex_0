#include <stdio.h>
#include <math.h>
int factorial(int num){
   int sum = 1;
   for (int i = 2; i <= num; ++i) {
       sum = i*sum;
   }
   return sum;
}
//is strong func
int isStrong(int numToCheck){
    if (numToCheck == 0)
    {
        return 0;
    }
    int inputnum = numToCheck;
    int sumToCheck = 0;
    while(numToCheck!= 0)
       {
       sumToCheck += factorial(numToCheck%10);
       numToCheck = numToCheck/10;
       }
    return inputnum == sumToCheck;
}



// is prime func
int isPrime(int numToCheck){
   if(numToCheck < 1){ return 0;}
   for (int i = 2; i <= sqrt(numToCheck); ++i) {
       if(numToCheck % i == 0){
           return 0;
       }
   }
   return 1;
}
