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
	

	uint8_t x;
	uint8_t cactusPos = 100; 
	uint8_t num_of_objects = 1;
	uint8_t n;
	uint8_t dino_ground_pos = 19;
	uint8_t dino_anim_stage = 0;
	uint8_t dino_anim_frame_count = 3;
	
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
				if(btn_up() && !jumping && !falling){
				
					jumping = true;
				}

				if(jumping){
					jump_value ++;
					
					if(jump_value == 25)
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

			//print dino
			if(dino_anim_stage <= 1)
				texture2screen(&s, dinosaur1, 12, 12, 40, dino_ground_pos - jump_value);	
			else if(dino_anim_stage > 1 && dino_anim_stage <= 3)
				texture2screen(&s, dinosaur2, 12, 12, 40, dino_ground_pos - jump_value);
			else if(dino_anim_stage > 3 && dino_anim_stage <= 5)
				texture2screen(&s, dinosaur3, 12, 12, 40, dino_ground_pos - jump_value);
			else if(dino_anim_stage > 5 && dino_anim_stage <= 7)
				texture2screen(&s, dinosaur2, 12, 12, 40, dino_ground_pos - jump_value);			

			dino_anim_stage++;

			if(dino_anim_stage >= (dino_anim_frame_count+1)*2)
				dino_anim_stage = 0;


			//check if texture collide with objects on screen, freeze screen
			if(is_collision(&s, cactus, 8, 8, cactusPos, 21)) 
			{
				while(1);
			}
			//print enemy texture
			texture2screen(&s, cactus, 8, 8, cactusPos, 21);

			//print background
			//texture2screen(&s, grass1, 6, 3, cactusPos + 10, 29);
			
			//ground
			for (x = 0; x < 128; x++){
				set_pixel(&s, x, 31, true);
			}
			

			cactusPos--;
			if (cactusPos<= 10)
				cactusPos += 128;
			

			//ground
			for (x = 0; x < 128; x++){
				set_pixel(&s, x, 31, true);
			}
		}		
		
		display_screen(&s);
		delay(20);
		

	}
	return 0;
}

void switch_state(enum game_state st){
	state = st;
	init = 1;
}