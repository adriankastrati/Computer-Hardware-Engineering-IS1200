
#include <stdint.h>   // Declarations of uint_32 and the like 
#include <pic32mx.h>  // Declarations of system-specific addresses etc 
#include "graphics.h"
#include <math.h>
#define MAX_SCORES 32

Score score_list[32];

void init_highscore_list(){
    int i;
    int n;
    
    for(i = 0; i < MAX_SCORES; i++){
        for(n = 0; n < 3; n++){
            score_list[i].name[n] = '-';
        }
        score_list[i].points = 0;
        score_list[i].position = i + 1;
    }
}

void delete_score_list(){
    int i;
    int n;
    for(i = 0; i < MAX_SCORES; i++){
        for(n = 0; n < 3; n++){
            score_list[i].name[n] = '-';
        }
        score_list[i].points = 0;
        score_list[i].position = i;
    }

    //write over value on kit
}
/*
void update_list(Score save_score){
    int updated = 0;
    struct score temp0;
    struct score temp1;
    //
    int i;

    for(i = 31; i >= 0; i--){
        if((score_list[i].points <= save_score.points) && !updated){
            temp0 = score_list[i];
            score_list[i] = save_score;
        }

        else{
            
            temp1 = score_list[i];
            if(i == 1){
                break;
            }

            score_list[i] = temp0;
            temp0 = score_list[i - 1];
        }
    }
    
        //write over value on kit

}*/

void dosom(Score ig, int start){
    int temp = ig.points;
    int digits = 0;
    
    //counts digits
    while(temp){
        temp /= 10;
        digits++;
    }

    temp = ig.position;
    //name 3 elements, position 2 elements, 1 null terminated, n digits
    char ret_arr[9 + digits];
    int loop1;

    //add position to char array
    for(loop1 = 0; loop1 < 3; loop1++){
    ret_arr[loop1] = temp % 10 + '0';
    temp /= 10;
    }

    ret_arr[loop1 + 1] = 58;

    //adds name to char array
    for (; loop1 < 6; loop1++){
        ret_arr[loop1] = ig.name[loop1 - 3];
    }
    
    ret_arr[loop1 + 1] = 58;

    

    //adds points to char array
    temp = ig.points;

    for(loop1 = 0; loop1 < digits + 6; loop1++){
        ret_arr[digits + 6 - loop1] = temp % 10 + '0';
        temp /= 10;
    }

    ret_arr[digits + 6] = 0;

    display_string(start, ret_arr);    
}
