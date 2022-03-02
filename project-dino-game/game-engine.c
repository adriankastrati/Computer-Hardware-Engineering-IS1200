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

			if(get_pixel(&screen, x + j, y + i) && texture[i * width + j])//
				return true;
		}
	}

	return false;
}/*
bool collided(const uint8_t texture[], uint8_t width, uint8_t height, uint8_t at_x, uint8_t at_y)
{
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			if(texture[(i * width + j])
				return true;
		}
	}

	return false;
}
*/