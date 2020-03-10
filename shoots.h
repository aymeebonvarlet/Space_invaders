#include <stdbool.h>

#ifndef SHOOTS_H_
#define SHOOTS_H_


void set_dbm(uint8_t id, bool val);
bool get_dbm(uint8_t id);
void set_lbm(uint8_t id, bool val);
bool get_lbm(uint8_t id);
void shoot_myspace(void);

void set_shoot(uint8_t coo, float val);
uint8_t get_shoot(uint8_t coo);


void set_shootbm(uint8_t coo, float val);
uint8_t get_shootbm(uint8_t coo);
void shoot_bigmonster(uint8_t id_bigm);

void set_p_id_random(uint8_t new);
uint8_t get_p_id_random(void);
#endif /* SHOOTS_H_ */
