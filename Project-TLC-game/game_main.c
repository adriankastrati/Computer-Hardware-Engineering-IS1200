#include <stdint.h>
#include <pic32mx.h>
#include "game-engine.h"
#include <stdbool.h>

enum game_state{title_screen, main_menu, highscore_menu, in_game, defeat_screen};
enum game_state state = title_screen;
//if (state == title_screen){}
