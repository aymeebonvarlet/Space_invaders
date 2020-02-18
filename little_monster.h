/*
 * little_monster.h
 *
 *  Created on: 17 févr. 2020
 *      Author: bonvarlet
 */

#ifndef LITTLE_MONSTER_H_
#define LITTLE_MONSTER_H_

// tab[numéro monstre][x,y]
uint8_t tab_littlem[14][2];

uint8_t** coordonnees_littlem(uint8_t i,uint8_t coo);
void init_littlem();
void changed_lm(uint8_t pas);
void delete_lm();


#endif /* LITTLE_MONSTER_H_ */
