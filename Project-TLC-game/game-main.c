#include <stdint.h>
#include <pic32mx.h>
#include "graphics.h"
#include <stdbool.h>

enum game_state{title_screen, main_menu, highscore_menu, in_game, defeat_screen};
enum game_state state = highscore_menu;

int main(){

	//if (state == title_screen){}

	
	display_init();
	display_string(0, "Dino Run");
	display_string(1, "IS1200");
	display_string(2, "Deni P");
	display_string(3, "Adrian K");
	display_update();

	delay(1000);

	int rowArrow = 2;
	int pressed = 0;
	
	while(1)
	{
		
		switch(state)
		{
			case title_screen:
			
			switch(rowArrow)
			{
				case 2:
					display_image(40, arrow3);
					break;
				case 3:
					display_image(40, arrow4);
					break;

			}
			
			display_string(0, "   Main Menu");
			display_string(1, "");
			display_string(2, "Play");
			display_string(3, "Highscores");

			if((button1_is_down() || button2_is_down()) && !pressed)
			{
				pressed = true;
				rowArrow++;
			}
			else if(!(button1_is_down() || button2_is_down()))
				pressed = false;

			if(rowArrow > 3)
				rowArrow = 2;

			break;
			
			case main_menu:
			break;

			case highscore_menu:

			display_string(0, "		Highscores		");
			

			break;

			case in_game:
			break;

			case defeat_screen:
			break;


		}
		
		//clear_screen();
		display_update();		
	}
	return 0;
}

