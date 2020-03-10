

#include "random.h"

static uint8_t variable = 5; //milieu de 10 ?
static uint8_t *p_nbre=&variable;

uint8_t get_p_nbre(void){
	return *p_nbre;
}

uint8_t rand(void){
	uint8_t nouveau_nbre = (13 * (*p_nbre) + 7 ) % 37 ;
	*p_nbre = nouveau_nbre;
	return nouveau_nbre;
}


