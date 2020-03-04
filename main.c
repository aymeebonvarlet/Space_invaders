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

	while (get_play())
	{
		moove_myspace();

		sleep(10);
		uint8_t time_to_moove_monster = 0;
		if (time_to_moove_monster % 10)
		{
			moove_bm(2);
		}

		signed char carac = serial_get_last_char();
		if (carac == ' ')
		{
			shoot_myspace();
		}
		if (get_shoot(1) < get_myspace(1))
		{
			shoot_myspace();
		}
//		time_to_moove_monster++;

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
