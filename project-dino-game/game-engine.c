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