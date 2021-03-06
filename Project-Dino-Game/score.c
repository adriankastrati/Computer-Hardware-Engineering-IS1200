#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include <stdint.h>   // Declarations of uint_32 and the like // Declarations of system-specific addresses etc 
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "graphics.h"

Score score_list[MAX_SCORES];

Score create_score(){
    Score new;
    int i;
    for(i = 0; i < 3; i++){
        new.name[i] = 32;
    }

    new.points = 0;
    
    return new;
}

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


void update_list(Score *save_score){
    char edited = 0;
    int i;
    int j;
    bool added = false;
    Score temp0;
    Score temp1;


    for(i = 0, j = 0; i < MAX_SCORES - 1; i++, j++){    
        if(save_score -> points < score_list[i].points){
            continue;
        }
        
        if(!added){
            temp0 = score_list[i];
            score_list[i] = *save_score;

            score_list[i].position = i + 1;
            save_score -> position = i + 1;
            added = true;
            continue;
        }
        
        temp1 = score_list[i];
        score_list[i] = temp0;
        score_list[i].position = i + 1;
    }
}

void print_score(Score ig, int line){    
    //position 2 elements, 2 spaces, name 3 elements, 2 spaces, max 4 digits digits, 1 null terminated
    char ret_arr[14];
    int loop1;
    int temp = ig.position;

    //add position to char array
    for(loop1 = 1; loop1 >= 0; loop1--){
        ret_arr[loop1] = temp % 10 + '0';
        temp /= 10;
    }
    
    //adds spaces between position and name
    ret_arr[2] = 32;
    ret_arr[3] = 32;

    //adds name to char array
    for (loop1 = 0; loop1 < 3; loop1++){
        ret_arr[loop1 + 4] = ig.name[loop1];        
    }
    
    //adds spaces between name and points
    ret_arr[7] = 32;
    ret_arr[8] = 32;


    //adds  points to char array
    temp = ig.points;

    for(loop1 = 0; loop1 < 4; loop1++){
        ret_arr[12 - loop1] = temp % 10 + '0';
        temp /= 10;
    } 

    //nul terminated
    ret_arr[13] = '\0'; 
    
    for(loop1 = 0; loop1 < 13; loop1++)

    display_string(line, ret_arr);
}

void set_name(Score *score, char a, char b, char c){
    score -> name[0] = a;
    score -> name[1] = b;
    score -> name[2] = c;
}