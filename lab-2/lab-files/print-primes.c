/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6
int column_counter = 0;

int is_prime(int n){
  int bool = 1;
  for (int i = 2; i <= (n/2); i++){
    if(n % i == 0){
      bool = 0;
      break;
    }
  }
  return bool;
}

void print_number(int value){
  int space_counter = 0;

  //counts number of spaces needed to fill 
  for(int space = value; space != 0; space_counter++){
    space /= 10;
  }
  //prints amount of needed spaces 
  for(int i = 10 - space_counter; i >= 0; i--){
    printf(" ");
  }
  //prints value
  printf("%d", value);

  
  column_counter++;

  //checks if the printed columns has reached 6  
  if(column_counter == COLUMNS){
    printf("\n");
    column_counter = 0;
  }
}

void print_primes(int n){
  // Should print out all prime numbers less than 'n'
  // with the following formatting. Note that
  // the number of columns is stated in the define
  // COLUMNS
  for(int counter = 2; counter <= n; counter++){
    if(is_prime(counter) == 1){
      print_number(counter); 
    }
  } 
  printf("\n");
}


// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}
