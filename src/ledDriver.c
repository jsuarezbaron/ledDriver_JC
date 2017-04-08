
#include "ledDriver.h"

//static uint16_t * ledsAddress;

void LedDriver_Destroy(uint16_t *ledsAddress){

}

void LedDriver_Create(uint16_t *ledsAddress){
	//ledsAddress=address;
	*ledsAddress=0;// se borra envia error el test1 de la funcion
}


void LedDriver_TurnOn(int ledNumber, uint16_t  *ledsAddress){
	//*ledsAddress=1;
	if (ledNumber <= 0 || ledNumber > 16)
	return;
        *ledsAddress |= 1 << (ledNumber - 1);
         //ledsAddress |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber, uint16_t  *ledsAddress){
     //*ledsAddress = 0;
	if (ledNumber <= 0 || ledNumber > 16)
	return;
       *ledsAddress &= ~(1 << (ledNumber - 1));
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
return 1 << (ledNumber - 1);
}

void LedDriver_TurnAllOn(uint16_t  *ledsAddress){
*ledsAddress = 0xffff;
}

void LedDriver_TurnAllOff(uint16_t  *ledsAddress){
*ledsAddress = 0;
}
