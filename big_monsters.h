/*
 * big_monsters.h
 *
 *  Created on: 5 févr. 2020
 *      Author: bonvarlet
 */

#ifndef BIG_MONSTERS_H_
#define BIG_MONSTERS_H_



void init_bigm(void);
void set_bigm(uint8_t id, uint8_t xory, uint8_t new_val);
uint8_t get_bigm(uint8_t id, uint8_t xory);
void moove_bm(uint8_t pas);
void delete_onebm(uint8_t id);
void delete_bm(void);
#endif /* BIG_MONSTERS_H_ */
