#include <myspace.h>
#include "vt100.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include "big_monsters.h"
#include "little_monster.h"

void moovemonsters(uint8_t time) // initialisé à 50
{
	uint8_t i = 1;
	while (i==1){
		sleep (time);
		delete_bm();
		delete_lm();
		changed_bm(1);
		changed_lm(1);
	}
}

void moove_myspace() {
	carac = serial_get_last_char();
	if (carac == 'i') {
		delete_myspace();
		myspace(0 , 1);
	}
	if (carac == 'a') {
		delete_myspace();
		myspace(0 , -1);
	}
}


