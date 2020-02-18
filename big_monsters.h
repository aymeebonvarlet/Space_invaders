/*
 * big_monsters.h
 *
 *  Created on: 5 févr. 2020
 *      Author: bonvarlet
 */

#ifndef BIG_MONSTERS_H_
#define BIG_MONSTERS_H_


// tab[numéro monstre][x,y]
uint8_t tab_bigm[10][2];


uint8_t** coordonnees_bigm(uint8_t i,uint8_t coo);
void init_bigm();

void changed_bm(pas);
void delete_onebm(uint8_t id);
void delete_bm();
#endif /* BIG_MONSTERS_H_ */
