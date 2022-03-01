#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include <stdint.h>   // Declarations of uint_32 and the like // Declarations of system-specific addresses etc 
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "graphics.h"

enum game_state{main_menu, highscore_menu, in_game, defeat_screen};
enum game_state state = in_game;
int init = 0;

void switch_state();

int main(){
	//if (state == title_screen){}

	display_init();
 	
	init_highscore_list();

	welcome_screen();
	
	Screen s;
	clear_screen(&s);
	display_screen(&s);
	
	int x;
	int cactusPos = 140; 

	//graphics_object backgroundObjects [] = { create_graphicsObject(grass1, 128, 29, 6, 3 ) };
	

	int num_of_objects = 1;
	int n;
	
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
			//ground
			for (x = 0; x < 128; x++)
			{
				set_pixel(&s, x, 31, true);

			}

			texture2screen(&s, dinosaur1, 8, 8, 16, 16);
			//texture2screen(&s, box, 8, 8, 4, 4);
			texture2screen(&s, cactus, 8, 8, cactusPos, 23);

			
			texture2screen(&s, grass1, 6, 3, 80, 29);
/*
			for(n = 0; n < num_of_objects; n++)
			{
				texture2screen(&s, backgroundObjects[n].texture, backgroundObjects[n].width, backgroundObjects[n].height, backgroundObjects[n].x_pos, 29);
				backgroundObjects[n].x_pos --;

				if(backgroundObjects[n].x_pos  <= 7)
					backgroundObjects[n].x_pos = 150;
			}
*/
			cactusPos--;

			if (cactusPos<= 7)
				cactusPos += 128;

			delay(50);

			break;

	
		}		
		display_screen(&s); //sends pixels to screen 

	}
	return 0;
}

void switch_state(enum game_state st){
	state = st;
	init = 1;
}