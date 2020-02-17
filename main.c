
#include <myspace.h>
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "serial.h"
#include "vt100.h"
#include "moove_perso.h"
#include "big_monsters.h"
#include "shape.h"
#include "little_monster.h"
#include "shoots.h"



int main(void)
{
	contour();
	init_bigm();
	init_littlem();
	init_myspace();
	int i = 1;
	moovemonsters(50);



  /* Initialize LEDs */
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);

  /* Turn on LEDs */
  STM_EVAL_LEDOn(LED3);
  STM_EVAL_LEDOn(LED4);
  STM_EVAL_LEDOn(LED5);
  STM_EVAL_LEDOn(LED6);


  while (1)
  {
	  moove_myspace();
	  shoot();
  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
