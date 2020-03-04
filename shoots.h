#include <stdbool.h>

#ifndef SHOOTS_H_
#define SHOOTS_H_


void set_dbm(uint8_t id, bool val);
bool get_dbm(uint8_t id);
void set_lbm(uint8_t id, bool val);
bool get_lbm(uint8_t id);
void shoot_myspace(void);

void set_shoot(uint8_t coo, uint8_t val);
uint8_t get_shoot(uint8_t coo);
#endif /* SHOOTS_H_ */
