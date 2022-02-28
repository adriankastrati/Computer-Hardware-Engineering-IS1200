#include <stdint.h>
#include <pic32mx.h>
#include "graphics.h"
#include <stdbool.h>

enum game_state{title_screen, main_menu, highscore_menu, in_game, defeat_screen};
enum game_state state = highscore_menu;

void init_io(void){
    //initiate buttons to input
    TRISDSET = 0x7 << 5;
}

int getbtns(void){
    return (PORTD >> 4) & 0xE;
}

bool btn_right(){
    if((PORTD >> 5) & 0x1) return true;

    else return false;
}

bool btn_up(){
    if((PORTD >> 6) & 0x1) return true;

    else return false;
}

bool btn_left(){
    if((PORTD >> 7) & 0x1) return true;

    else return false;
}
int main(){

	//if (state == title_screen){}

	while(1){
	display_init();
	
	if(btn_right) display_string(0, "Generic Racing");
	
	if(btn_left)display_string(1, "IS1200");
	
	if(btn_up)display_string(2, "Deni P");

	display_update();
	delay(1000);

	}
	
	while(1)
	{
		int rowArrow;
		switch(state)
		{
			case title_screen:
			rowArrow = 0;
			//display_image(40, arrow);
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
