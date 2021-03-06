#ifndef GRAPHICS
#define GRAPHICS
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include <stdint.h>   // Declarations of uint_32 and the like // Declarations of system-specific addresses etc 
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "graphics.h"
#define MAX_SCORES 32


//texture.h
const uint8_t const dinosaur1 [144];
const uint8_t const dinosaur2 [144];
const uint8_t const dinosaur3 [144];
const uint8_t const box [64];
const uint8_t const cloud [64];
const uint8_t const big_cloud [96];
const uint8_t const cactus [64];
const uint8_t const grass1 [18];
extern const uint8_t const font[128*8];
extern const uint8_t const icon[128];
void welcome_screen();

//menu.h
void switch_state();


//io.h
int getbtns(void);
int getsw(void);
bool btn_right();
bool btn_up();
bool btn_left();
bool get_switch1();
bool get_switch2();
bool get_switch3();
bool get_switch4();

struct Object{
    uint8_t x_pos;
    const uint8_t y_pos;
};

//interrupts
void enable_interrupt(void);
void init_timer();


//from labs
void display_image(int x, const uint8_t *data);
void display_init(void);
void display_string(int line, char *s);
void display_update(void);
uint8_t spi_send_recv(uint8_t data);
char *itoaconv(int num);
void labwork(void);
void quicksleep(int cyc);
extern char textbuffer[4][16];
void delay(int);
void time2string( char *, int );


//screen.h
typedef struct Screen{
        int pixels[128];
}Screen;

void texture2screen(Screen *screen, const uint8_t texture[], uint8_t width, uint8_t height, uint8_t x, uint8_t y);
/*
void obj2screen(Screen *screen, graphics_object *object);
*/
bool get_pixel(Screen * screen, unsigned int x, unsigned int y);
void set_pixel(Screen * screen, unsigned int x, unsigned int y, bool value);
void display_screen(Screen *screen);
void clear_screen(Screen *screen);
bool is_valid_pixel(int x, int y);
/*
void edit_game_object(graphics_object *game_object, const uint8_t texture_in[], uint8_t x_pos, uint8_t y_pos, int width, int height);
*/

//score.h
typedef struct Score{
    char name[3];
    int points;
    int position; 
} Score;

extern struct Score score_list[32];

void set_name(Score *score, char a, char b, char c);
Score create_score();
void init_highscore_list();
void delete_score_list();
void update_list(Score *save_score);
void print_score(Score ig, int line);
void set_name(Score *score, char a, char b, char c);


//game.h
bool is_collision(Screen *screen, const uint8_t texture[], uint8_t width, uint8_t height, uint8_t x, uint8_t y);
void push_cactus(int score, struct Object *obj0, struct Object *obj1, struct Object *obj2, struct Object *obj3);


//random.h, //taken from internet https://en.wikipedia.org/wiki/Xorshift
struct rand_state{
  uint32_t a;
};
/* The state word must be initialized to non-zero */

uint32_t xorshift32(struct rand_state *state);
xorwow(struct rand_state *state);

#endif


