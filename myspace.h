/*
 * initiatilisation_perso.h
 *
 *  Created on: 27 janv. 2020
 *      Author: bonvarlet
 */

#ifndef MYSPACE_H_
#define MYSPACE_H_

#include <stdint.h>

typedef struct tableau_x_y{
	uint8_t tab[2];
}myspace;

void contour();
void myspace(uint8_t x , uint8_t new_x);
void delete_myspace(uint8_t x , uint8_t new_x);
void init_myspace();


#endif /* MYSPACE_H_ */
