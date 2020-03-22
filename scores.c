#include "vt100.h"
#include "serial.h"

static uint8_t life_myspace = 3;

static uint8_t score=0;

void set_life_myspace(uint8_t new){
	life_myspace+=new;
}

void set_score(uint8_t new){
	score+=new;
}

uint8_t get_life_myspace(void){
	return life_myspace;
}

void display_life(void){
	vt100_move(69, 23);
	serial_puts("Life : ");
	vt100_move(75, 23);
	serial_putchar('0' + life_myspace);
}

void display_score(void){
	vt100_move(3, 23);
	serial_puts("Score : ");
	vt100_move(10, 23);
	serial_putchar('0' + score);

}
