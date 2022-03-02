#include <stdint.h>
#include <pic32mx.h>
#include "graphics.h"
#include <stdbool.h>


//1/20 sek

//clear_screen();
//move objects on x-axis
//put bad guy on screen

bool is_collision(Screen *screen, const uint8_t texture[], int width, int height, int x, int y){
	int i, j;

	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			if(get_pixel(&screen, x + j, y + i))
				return true;
		}
	}

	return false;
}
