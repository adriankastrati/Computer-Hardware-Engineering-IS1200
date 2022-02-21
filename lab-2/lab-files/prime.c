/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

int is_prime(int n){
  int bool; 

 if (n < 2)
 bool = 0;
  else{
    bool = 1;
    for (int i = 2; i < (n/2); i++){
      if(n % i == 0){
        bool = 0;
        break;
      }
    }
  }

  return bool;
}


int main(void){
  printf("%d\n", is_prime(0));  // 2 is a prime.      Should print 1.
  printf("%d\n", is_prime(1)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(2)); // 987 is not a prime. Should print 0.
}
