#ifndef SERIAL_H_
#define SERIAL_H_

#include <stdint.h>

void serial_init(const uint32_t baudrate);
void serial_putchar(const volatile char c);
void serial_puts(const volatile char *s);

/* -1 if none */
signed char serial_get_last_char(void); // renvoie -1 si rien, sinon le caractère 
 
#endif /* SERIAL_H_ */
