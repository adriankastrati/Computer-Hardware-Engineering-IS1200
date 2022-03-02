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

bool if_jump(){
	if (btn_up) 
		return true;

		else return false;
}

jumping

if(if_jump && jump_value <= 8)
	jump_value++;

else if(if_jump && jump_value 9){
	jump_value--;
}



int heightJumped = 0;
if(btnup && !jumping && !falling)
{
 
	jumping = true;
}

if(jumping){
	heightJumped ++;
	y_pos ++;
	if(heightJumped >= 8)
	{
		jumping = false;
		falling = true;
	}
}
if(falling)
{
	y_pos--;
	heightjumped--;

	if (heightJumped == 0)
	{
		falling = false;
	}
}

