#define PIXEL_STRIP_LENGTH 8
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define STRIP_COUNT (SCREEN_WIDTH*SCREEN_HEIGHT/PIXEL_STRIP_LENGTH)

//pixel values
uint8_t screen[128][32];

const uint8_t const arrow[];
const uint8_t const good_car[];
const uint8_t const bad_car[];