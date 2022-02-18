#include <stdint.h>
#include <pic32mx.h>
#include "game-engine.h"
#include <stdbool.h>

enum game_state{title_screen, main_menu, highscore_menu, in_game, defeat_screen};
enum game_state state = title_screen;

int main(){

	//if (state == title_screen){}

	
	display_init();
	display_string(0, "KTH/ICT lab");
	display_string(1, "in Computer");
	display_string(2, "Engineering");
	display_string(3, "Welcome!");
	display_update();

	while(1)
	{
		display_string(0, "KTH/ICT lab");
		display_string(1, "in Computer");
		display_string(2, "Engineering");
		display_string(3, "Welcome!");
		display_update();		
	}
	return 0;
}
