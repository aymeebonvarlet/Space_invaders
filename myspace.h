/*
 * initiatilisation_perso.h
 *
 *  Created on: 27 janv. 2020
 *      Author: bonvarlet
 */

#ifndef MYSPACE_H_
#define MYSPACE_H_

#include <stdint.h>


uint8_t tab_myspace[2];

void contour();
myspace(uint8_t x , uint8_t pas);
void delete_myspace(uint8_t x , uint8_t new_x);
void init_myspace();


#endif /* MYSPACE_H_ */
