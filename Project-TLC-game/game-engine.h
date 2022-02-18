//Value of buttons, 
char button_input(char direction);


void move_good_car(char direction);

// if collision, call ISR to check what collided,
//bool collision();

void spawn_bad_car();

uint8_t spi_send_recv(uint8_t data);

void display_init(void);

void display_update(void);

/* Declare display_debug - a function to help debugging.

   After calling display_debug,
   the two middle lines of the display show
   an address and its current contents.

   There's one parameter: the address to read and display.

   Note: When you use this function, you should comment out any
   repeated calls to display_image; display_image overwrites
   about half of the digits shown by display_debug.
*/
void display_debug( volatile int * const addr );

extern const uint8_t const font[128*8];

void display_image(int x, const uint8_t *data);

void display_string(int line, char *s);

