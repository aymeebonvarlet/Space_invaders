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
#include "menu.h"
#include "random.h"
#include "scores.h"
#include "lost.h"
#include "win.h"
#include "init.h"

//timer pour que les monstres avance
static uint8_t time_to_moove_monster = 1;
static uint8_t first_shoot_myspace = 0;
static uint8_t time_shoot_bigm = 1;

int main(void)

{

	serial_init(115200);
	vt100_clear_screen();

	//on affiche le menu et ses extensions, le play est initialisé à false
	while (!get_play())
	{
		signed char carac = serial_get_last_char();
		menu();
		if (carac == ' ')
		{
			set_play(true);
			vt100_clear_screen();
		}
	}
	init();

	while (1)
	{
		while (get_play())
		{
			display_life();
			signed char carac = serial_get_last_char();
			moove_myspace(carac);

			sleep(2);
			//on fait bouger les monstres
			if (time_to_moove_monster % 100 == 0)
			{
				moove_bm(1);
			}
			//les big monster shoot
			if (time_shoot_bigm % 25 == 0)
			{
				set_p_id_random(rand() % 10);
				shoot_bigmonster(get_p_id_random());
			}
			if (get_shootbm(1) > get_bigm(get_p_id_random(), 1))
			{
				shoot_bigmonster(get_p_id_random());
			}

			if (carac == ' ')
			{
				shoot_myspace();
				first_shoot_myspace = 1;
			}

			if (get_shoot(1) < get_myspace(1) && first_shoot_myspace)
			{
				shoot_myspace();
			}
			time_to_moove_monster++;
			time_shoot_bigm++;

			if (get_nb_kill_bm() == 10)
			{
				set_play(false);
			}
		}
		vt100_clear_screen();


		while (!get_play())
		{
			signed char carac = serial_get_last_char();
			if (get_nb_kill_bm() == 10)
			{
				win();
			}
			else
			{
				lost();
			}

			if (carac == ' ')
			{
				set_play(true);
				vt100_clear_screen();
				init();
				init_lifes();

				time_to_moove_monster = 1;
				first_shoot_myspace = 0;
				time_shoot_bigm = 1;
			}
		}

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
