#include <myspace.h>
#include "vt100.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>
#include "big_monsters.h"
#include "little_monster.h"
#include "moove_perso.h"
#include "constants.h"

void shoot_myspace(){
	unsigned char carac = serial_get_last_char();
	if (carac = ' ');
		uint8_t x_shoot = myspace.tab[0] + 2 ; // pour que le tire débute au milieu du vasseau)
		for (uint8_t  i = myspace.tab[1]+1 ; i > VT100_SCREEN_YMIN ; i-- ){
			if(i>myspace.tab[1]+1){ // on efface le shoot précédent en sachant qu’il fait au moins un tir
				vt100_move(x_shoot,i-1);
				serial_puts(" ");
			}
			vt100_move(x_shoot,i);
			serial_puts("|");
			for (uint8_t id_bm = 0 ; id_bm < 11 ; id_bm ++){
				uint8_t ** c = coordonnees_bigm(i,x_shoot);
				if( c <= x_shoot <= c +8){
					delete_onebm(id_bm);
					death_bm[id_bm]=false;
					break;
				}
			}
			for (uint8_t id_lm = 0 ; id_lm < 11 ; id_lm ++){
				uint8_t ** c = coordonnees_littlem(i,x_shoot);
				if( c <= x_shoot <= c +4){
					delete_onelm(id_lm);
					death_lm[id_lm]=false;
					break;
				}
			}
		}
}


