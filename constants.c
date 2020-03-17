/*
 * constants.c
 *
 *  Created on: 18 févr. 2020
 *      Author: bonvarlet
 */
#include <stdbool.h>
#include "constants.h"

static bool play = false;


void set_play(bool new)
{
	play = new;

}
bool get_play(void)
{
	return play;
}


