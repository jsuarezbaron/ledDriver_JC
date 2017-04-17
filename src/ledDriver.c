
#include "ledDriver.h"

//static uint16_t * ledsAddress;

void LedDriver_Destroy(uint16_t *ledsAddress){

}

/*!
* \brief LedDriver_Create instancia  una dirección de memoria para
* 	utilizarla dentro de los tests.
*/
void LedDriver_Create(uint16_t *ledsAddress){
	//ledsAddress=address;
	*ledsAddress=0;// se borra envia error el test1 de la funcion
/*!
*@param -> *ledsAddress
*@return -> ninguno
*/
}

/*!
* \brief LedDriver_TurnOn instancia  una dirección de memoria para
* 	y un led para utilizar dentro de los tests. En este caso para
*	encender un led.
*/
void LedDriver_TurnOn(int ledNumber, uint16_t  *ledsAddress){
	//*ledsAddress=1;
	if (ledNumber <= 0 || ledNumber > 16)
	return;
        *ledsAddress |= 1 << (ledNumber - 1);
         //ledsAddress |= convertLedNumberToBit(ledNumber);
/*!
*@param -> *ledNumber Número de led a probar.
*@param -> *ledsAddress Dirección de memoria usada.
*@return -> ninguno
*/
}

/*!
* \brief LedDriver_TurnOn instancia  una dirección de memoria para
* 	y un led para utilizar dentro de los tests. En este caso para
*	apagar un led.
*/
void LedDriver_TurnOff(int ledNumber, uint16_t  *ledsAddress){
     //*ledsAddress = 0;
	if (ledNumber <= 0 || ledNumber > 16)
	return;
       *ledsAddress &= ~(1 << (ledNumber - 1));
/*!
*@param -> *ledNumber Número de led a probar.
*@param -> *ledsAddress Dirección de memoria usada.
*@return -> ninguno
*/
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
return 1 << (ledNumber - 1);
}

/*!
* \brief LedDriver_TurnAllOn instancia  una dirección de memoria para
* 	 utilizar dentro de los tests. En este caso para
*        encender todos los leds.
*/
void LedDriver_TurnAllOn(uint16_t  *ledsAddress){
*ledsAddress = 0xffff;
/*!
*@param -> *ledsAddress Dirección de memoria usada.
*@return -> ninguno
*/
}

/*!
* \brief LedDriver_TurnOn instancia  una dirección de memoria para
* 	 utilizar dentro de los tests. En este caso para
*	 apagar todos los leds.
*/
void LedDriver_TurnAllOff(uint16_t  *ledsAddress){
*ledsAddress = 0;
/*!
*@param -> *ledsAddress Dirección de memoria usada.
*@return -> ninguno
*/
}
