
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
#include "constants.h"



int main(void)
{
	contour();
	init_bigm();
	init_littlem();
	init_myspace();

  while (play.tab[0])
  {
	  moove_myspace();
	  shoot();
	  moovemonsters(50);

  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}


uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
