
#include "vt100.h"
#include "serial.h"

#ifndef MYSPACE_H_
#define MYSPACE_H_


void set_myspace(uint8_t val, uint8_t coo);
uint8_t get_myspace(uint8_t coo);

void moove_myspace(void);
void init_myspace(void);


#endif /* MYSPACE_H_ */
