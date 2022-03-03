#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include <stdint.h>   // Declarations of uint_32 and the like // Declarations of system-specific addresses etc 
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "graphics.h"

#define JUMP_HEIGHT 20

enum game_state{main_menu, highscore_menu, in_game, defeat_screen};
enum game_state state = in_game;

int init = 0;
int jump_value = 0;
bool jumping = false;
bool falling = false;

struct Object{
	uint8_t x_pos;
	uint8_t y_pos;
};

struct xorshift32_state {
  uint32_t a;
};

/* The state word must be initialized to non-zero */
uint32_t xorshift32(struct xorshift32_state *state)
{
	/* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
	uint32_t x = state->a;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return state->a = x;
}



int main(){
	display_init();
	
	welcome_screen();

	//screen init
	Screen s;
	clear_screen(&s);
	display_screen(&s);
	

	uint8_t x;
	uint8_t cactusPos = 100; 

	unsigned char random_value;
	struct rand_state rand;
	rand.a = 1;
	int current_random;

	char cloud_counter = 0;
	uint16_t cloud_speed = 0;
	uint16_t cloud_pos = 128;


	uint8_t n;
	uint8_t dino_ground_pos = 19;
	uint8_t dino_anim_stage = 0;
	uint8_t dino_anim_frame_count = 3;

	struct Object cactusObj1 = { 100, 23 };
	struct Object cactusObj2 = { 150, 23 };
	struct Object cactusObj3 = { 200, 23 };
	struct Object cactusObj4 = { 250, 23 };
	struct Object grassObj1 = { 50, 29 };
	struct Object grassObj2 = { 75, 29 };
	struct Object grassObj3 = { 25, 29 };
	struct Object grassObj4 = { 125, 29 };
	struct Object grassObj5 = { 150, 29 };



	struct Object objects[] = { 
		cactusObj1, cactusObj2, cactusObj3, cactusObj4, grassObj1, grassObj2, grassObj3, grassObj4, grassObj5
	};
	uint8_t num_of_objects = 9;

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
				random_value = xorshift32(&rand);
				random_value = random_value % 20;
	      
				if(btn_up() && !jumping && !falling)
					jumping = true;
				

				if(jumping){
					jump_value ++;
					
					if(jump_value == JUMP_HEIGHT)
					{
						jumping = false;
						falling = true;
					}
				}
				
				if(falling){
					jump_value--;

					if (jump_value == 0)
						falling = false;
				}

			for(x = 0; x < 4; x++){ //dino anim
					
					clear_screen(&s);
					if(dino_anim_stage <= 1)
						texture2screen(&s, dinosaur1, 12, 12, 40, dino_ground_pos - jump_value);

					else if(dino_anim_stage > 1 && dino_anim_stage <= 3)
						texture2screen(&s, dinosaur2, 12, 12, 40, dino_ground_pos - jump_value);

					else if(dino_anim_stage > 3 && dino_anim_stage <= 5)
						texture2screen(&s, dinosaur3, 12, 12, 40, dino_ground_pos - jump_value);

					else if(dino_anim_stage > 5 && dino_anim_stage <= 7)
						texture2screen(&s, dinosaur2, 12, 12, 40, dino_ground_pos - jump_value);

					if(is_collision(&s, cactus, 8, 8, objects[x].x_pos, objects[x].y_pos))
					{
						while(1);
					}
			}
			
			dino_anim_stage++;

			if(dino_anim_stage >= (dino_anim_frame_count+1)*2)
				dino_anim_stage = 0;

			for(x = 0; x < num_of_objects; x++)
			{
				if(x < 4)
					texture2screen(&s, cactus, 8, 8, objects[x].x_pos, objects[x].y_pos);
				else
					texture2screen(&s, grass1, 6, 3, objects[x].x_pos, objects[x].y_pos);

				objects[x].x_pos --;

				if(objects[x].x_pos <= 10)
					objects[x].x_pos += (random_value + 130);
			}

			//print background
			
			//ground
			for (x = 0; x < 128; x++)
				set_pixel(&s, x, 31, true);

			//ground
			for (x = 0; x < 128; x++)
				set_pixel(&s, x, 31, true);

			texture2screen(&s, cloud, 8, 8, cloud_pos, 10);

			cloud_counter++;
			if(cloud_counter == 3){
				cloud_counter = 0;
				cloud_speed ++;
			}
			if(cloud_pos <= 10)
				cloud_pos += (random_value*2 + 300);

			
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
