#include "shoots.h"
#include "serial.h"
#include "vt100.h"
#include "timer.h"
#include "shape.h"
#include "myspace.h"
#include "big_monsters.h"
void init(void)
{
	contour();
	init_bigm();
//	init_littlem();
	init_myspace();
}

void init_lifes(void){
	for (uint8_t i=0 ; i<10 ; i++){
		set_dbm(i, true);
	}
	set_life_myspace(3);
}


