#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6
int column_counter = 0;

void print_sieves();
void print_number();



int main(int argc, char *argv[]){
    if(argc == 2)
        print_sieves(atoi(argv[1]));
    
    else
        printf("Please state an interger number.\n");
  
    return 0;
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

void print_sieves(int n){
       
    int bool_arr_n [n];
    
    //sets the array to all primes
    for(int i = 0; i < n; i++){
        bool_arr_n[i] = 1;
    }

    for(int i = 2; i < n; i++){
       
        if(!bool_arr_n[i - 1]){
            continue;
        }

        for(int np = i + i; np < n; np += i){
                bool_arr_n[np - 1] = 0;
        }
        
        print_number(i);
    }
}


