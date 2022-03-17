#include <stdint.h>
#include <pic32mx.h>
#include "graphics.h"
#include <stdbool.h>

//Made by Adrian Kastrati & Deni Persson
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



