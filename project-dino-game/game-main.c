#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include <stdint.h>   // Declarations of uint_32 and the like // Declarations of system-specific addresses etc 
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "graphics.h"

enum game_state{main_menu, highscore_menu, in_game, defeat_screen};
enum game_state state = in_game;

int init = 0;
int jump_value = 0;
bool jumping = false;
bool falling = false;

int main(){
	display_init();
	
	welcome_screen();

	//screen init
	Screen s;
	clear_screen(&s);
	display_screen(&s);
	

	int x;
	int cactusPos = 100; 
	int num_of_objects = 1;
	int n;
	int dino_ground_pos = 26;
	
	while(1)
	{	
		clear_screen(&s); // clears screen before next frame
		switch(state)
		{
			
			case main_menu:
			break;

			case highscore_menu:
			break;

			case in_game:

			clear_screen(&s);


    		if( (IFS(0) & 0x100) == 0x100 ){      
	      		IFSCLR(0) = 1 << 8;
    
				if(btn_up && !jumping && !falling){
				
					jumping = true;
				}

				if(jumping){
					jump_value ++;
					if(jump_value >= 8)
					{
						jumping = false;
						falling = true;
					}
				}

				if(falling){
					jump_value--;

					if (jump_value == 0)
					{
						falling = false;
					}
				}

				display_screen(&s); //sends pixels to screen 

			}			
			
			texture2screen(&s, dinosaur1, 8, 8, 20, dino_ground_pos - jump_value);
			
			cactusPos--;
			jump_value--;
			if (cactusPos<= 7)
				cactusPos += 128;

			delay(20);
			
			if(is_collision(&s, cactus, 8, 8, cactusPos, 21))
			{}
			texture2screen(&s, cactus, 8, 8, cactusPos, 21);
		}		
		
		for (x = 0; x < 128; x++){
				set_pixel(&s, x, 31, true);
		}
		
		texture2screen(&s, grass1, 6, 3, cactusPos + 10, 29);



	}
	return 0;
}

void switch_state(enum game_state st){
	state = st;
	init = 1;
}