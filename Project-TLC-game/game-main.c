#include <stdint.h>
#include <pic32mx.h>
#include "graphics.h"
#include <stdbool.h>

enum game_state{title_screen, main_menu, highscore_menu, in_game, defeat_screen};
enum game_state state = title_screen;
int init = 0;

void switch_state();

int main(){

	//if (state == title_screen){}

	
	display_init();
	display_string(0, "Dino Run");
	display_string(1, "IS1200");
	display_string(2, "Deni P");
	display_string(3, "Adrian K");
	display_update();

	delay(1000);

	int rowArrow = 1;
	int pressed = 0;

	int score = 0;
	
	while(1)
	{
		if(btns_released() && pressed)
			pressed = false;
		
		switch(state)
		{
			case title_screen:
			
			switch(rowArrow)
			{
				case 1:
					display_image(25, arrow3);
					break;
				case 2:
					display_image(50, arrow4);
					break;

			}
			
			display_string(0, "    Main Menu");
			display_string(1, "Play");
			display_string(2, "Hiscores");
			display_string(3, "");

			if((btn_left() || btn_right()) && !pressed)
			{
				pressed = true;
				rowArrow++;
			}
			else if(btn_p() && !pressed)
			{
				pressed = true;

				if(rowArrow == 1)
					switch_state(in_game);
				else
					switch_state(highscore_menu);

			}
			

			if(rowArrow > 2)
				rowArrow = 1;


			break;
			
			case main_menu:
			break;

			case highscore_menu:

			display_string(0, "		Highscores		");
			if(init)
			{
				init = 0;
				display_string(0, "		Highscores		");
				display_string(1, "");
				display_string(2, "");
				display_string(3, "");
			}
			if(btn_p()&&!pressed)
			{
				pressed = true;
				switch_state(title_screen);
			}
			

			break;

			case in_game:
			if(init)
			{
				init = 0;
				score = 0;
				display_string(0, "SCORE: ");
				display_string(1, "");
				display_string(2, "");
				display_string(3, "");
			}

			if(btn_p()&&!pressed)
			{
				pressed = true;
				switch_state(title_screen);
			}
			break;

			case defeat_screen:
			break;


		}
		
		//clear_screen();
		display_update();		
	}
	return 0;
}
void switch_state(enum game_state st)
{
	state = st;
	init = 1;
}

