#include "myspace.h"
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "serial.h"
#include "vt100.h"
#include "moove_perso.h"
#include "shape.h"
#include "shoots.h"
#include "constants.h"
#include "timer.h"

int main(void)
{

	contour();
	init_bigm();
//	init_littlem();
	init_myspace();
	//timer pour que les monstres avance
	uint8_t time_to_moove_monster = 1;
	uint8_t tirer_au_moins_une_fois = 0;
	while (get_play())
	{
		signed char carac = serial_get_last_char();
		moove_myspace(carac);

		sleep(2);
		if (time_to_moove_monster % 150 == 0)
		{
			moove_bm(1);
		}


		if (carac == ' ')
		{
			shoot_myspace();
			tirer_au_moins_une_fois = 1;
		}

		if (get_shoot(1) < get_myspace(1) && tirer_au_moins_une_fois)
		{
			shoot_myspace();
		}
		time_to_moove_monster++;

	}
	while (1)
	{
	}
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size)
{
	/* TODO, implement your code here */
	return;
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void)
{
	/* TODO, implement your code here */
	return -1;
}
