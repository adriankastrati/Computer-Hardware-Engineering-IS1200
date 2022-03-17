#include <stdint.h>
#include <pic32mx.h>
#include "graphics.h"
#include <stdbool.h>


//1/20 sek

//clear_screen();
//move objects on x-axis
//put bad guy on screen

bool is_collision(Screen *screen, const uint8_t texture[], uint8_t width, uint8_t height, uint8_t x, uint8_t y){
	int i, j;

	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			if(x+j >= 128 || y+i >= 32)
				continue;

			if(get_pixel(&screen, x + j, y + i) && texture[i * width + j])
				return true;
		}
	}

	return false;
}


void push_cactus(int score, struct Object *obj0, struct Object *obj1, struct Object *obj2, struct Object *obj3){
	int x, y, difference;
	struct Object ob0, ob1, ob2, ob3;
	ob0.x_pos = obj0 -> x_pos; 
	ob1.x_pos = obj1 -> x_pos; 
	ob2.x_pos = obj2 -> x_pos; 
	ob3.x_pos = obj3 -> x_pos; 


	struct Object arr[] = {ob0, ob1, ob2, ob3};
	/*
	for(x = 0; x < 4; x++){
		for(y = 0; y < 3; y++){
			if(y == x) continue;

			difference = arr[y + 1].x_pos - arr[x].x_pos;
			
			if(difference < 20 && difference > 15){
				arr[y + 1].x_pos += (15 + score % 10);
				difference = arr[y + 1].x_pos - arr[x].x_pos;

			}

			if(difference < 20){
			arr[y + 1].x_pos += (10 + score % 10);
			//difference = arr[y + 1].x_pos - arr[x].x_pos;
			}
		}
	}
	obj0 -> x_pos = ob0.x_pos;
	obj1 -> x_pos = ob1.x_pos;
	obj2 -> x_pos = ob2.x_pos;
	obj3 -> x_pos = ob3.x_pos;
	*/

	for(x = 0;x < 4; x++){
		for(y = 0; y < 4; y++){
		
			if(y == x) continue;
			
			if((arr[y].x_pos - arr[x].x_pos) < 35)
					arr[x].x_pos += 50;
		}
	}
	obj0 -> x_pos = ob0.x_pos;
	obj1 -> x_pos = ob1.x_pos;
	obj2 -> x_pos = ob2.x_pos;
	obj3 -> x_pos = ob3.x_pos;
}

//taken from internet https://en.wikipedia.org/wiki/Xorshift
/* The state array must be initialized to not be all zero in the first four words */
uint32_t xorshift32(struct rand_state *state)
{
	/* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
	uint32_t x = state->a;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return state->a = x;
}