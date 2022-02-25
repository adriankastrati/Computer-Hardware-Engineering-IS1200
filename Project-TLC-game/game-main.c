#include <stdint.h>
#include <pic32mx.h>
#include "graphics.h"
#include <stdbool.h>

enum game_state{title_screen, main_menu, highscore_menu, in_game, defeat_screen};
enum game_state state = highscore_menu;

int main(){

	//if (state == title_screen){}

	
	display_init();
	display_string(0, "Generic Racing");
	display_string(1, "IS1200");
	display_string(2, "Deni P");
	display_string(3, "Adrian K");
	display_update();

	delay(1000);
	
	while(1)
	{
		int rowArrow;
		switch(state)
		{
			case title_screen:
			rowArrow = 0;
			display_image(40, arrow);
			display_string(0, "   Main POop");
			display_string(1, "");
			display_string(2, "Play");

			display_string(3, "Highscores");

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

