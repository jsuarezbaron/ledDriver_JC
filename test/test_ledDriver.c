#include "unity.h"
#include "ledDriver.h"

uint16_t address;
/*! \ address es una variable usada para asignar un valor nulo */

void setUp(){

}

void tearDown(){
	address=0;
}

/*!
* \brief Test 1 Todos los leds deben estar apagados después de inicializar el driver.
* 		Se prueba con la variable virtualLedsTx que es una dirección de memoria.  
*               virtualLedsTx=0xFFFF inicializa todos los leds en 1             
* \param[En] Ninguno
*/
void testDriver_LedsOffAfterCreate(){
	uint16_t virtualLedsTx=0xFFFF;     
	LedDriver_Create(&virtualLedsTx); 
	TEST_ASSERT_EQUAL_HEX16(0,virtualLedsTx);
/*!
*@param -> Ninguno
*@return -> Ninguno
*/
}

/*!
*\brief Test 2 Un led puede ser encendido individualmente
* virtualLedsTx=0x0001 inicializa el led 1 e 1.
*\param[En] Ninguno
*/
void testDriver_TurnOnledUno(){
	uint16_t virtualLeds=0x0001;		 
	LedDriver_Create(&virtualLeds);		
        LedDriver_TurnOn(1,&virtualLeds);	
	TEST_ASSERT_EQUAL_HEX16(1,virtualLeds);
/*!
*@param -> Ninguno
*@return -> Ninguno
*/
}

/*!
*\brief Test 3 Un led puede ser apagado individualmente.
*\param[En] Ninguno
*/
void testDriver_TurnOffledUno(){

	uint16_t virtualLeds1=0x0001;			//Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds1);		//funcion que quiero testear
        LedDriver_TurnOff(1,&virtualLeds1);		//Req 7->"1" Encendido/ "0" Apagado
	TEST_ASSERT_EQUAL_HEX16(0,virtualLeds1);
/*!
*@param -> Ninguno
*@return -> Ninguno
*/
}


/*!
*\brief Test 4a Múltiple leds pueden ser apagados. 
* \param[En] Ninguno
*/
void testDriver_TurnOnMultipleLeds(){
	uint16_t virtualLedsX;
        LedDriver_Create(&virtualLedsX); 
	LedDriver_TurnOn(9,&virtualLedsX);
	LedDriver_TurnOn(8,&virtualLedsX);
	TEST_ASSERT_EQUAL_HEX16(0x180, virtualLedsX);
/*!
*@param -> Ninguno
*@return -> Ninguno
*/
}

/*!
*\brief Test 4b Múltiple leds pueden ser encendidos. 
*\param[En] Ninguno
*/
void testDriver_TurnOffMultipleLeds(){
	uint16_t virtualLedsA;
        LedDriver_Create(&virtualLedsA); 
	LedDriver_TurnAllOn(&virtualLedsA);
	LedDriver_TurnOff(9,&virtualLedsA);
	LedDriver_TurnOff(8,&virtualLedsA);
	TEST_ASSERT_EQUAL_HEX16((~0x180)&0xffff, virtualLedsA);
/*!
*@param -> Ninguno
*@return -> Ninguno
*/
}

/*!
*\brief Test 5 Múltiple leds pueden ser encendidos. 
*\param[En] Ninguno
*/
void testDriver_TurnOffAnyLed(){
	uint16_t virtualLedsY;
        LedDriver_Create(&virtualLedsY);
        LedDriver_TurnAllOn(&virtualLedsY);
	LedDriver_TurnOff(8,&virtualLedsY);
	TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLedsY);
/*!
*@param -> Ninguno
*@return -> Ninguno
*/
}


/*!
* \brief Test 6 Encender todos los leds. 
* \param[En] Ninguno
*/

void testDriver_AllLedsOn(){
    uint16_t LEDSXYZaddress;                       
    LedDriver_Create(&LEDSXYZaddress);
    LedDriver_TurnAllOn(&LEDSXYZaddress);  
    TEST_ASSERT_EQUAL_HEX16(0xffff, LEDSXYZaddress);
/*!
*@param -> Ninguno
*@return -> Ninguno
*/
}

/*!
* \brief Test 7 Apagar todos los leds. 
* \param[En] Ninguno
*/
void testDriver_AllLedsOff(){
    uint16_t LEDSXYZaddress2;
    LedDriver_Create(&LEDSXYZaddress2);
    LedDriver_TurnAllOn(&LEDSXYZaddress2);
    LedDriver_TurnAllOff(&LEDSXYZaddress2); 
    TEST_ASSERT_EQUAL_HEX16(0, LEDSXYZaddress2);
/*!
*@param -> Ninguno
*@return -> Ninguno
*/
}

/*!
* \brief Test 8 Verificación de valores límites.
* \param[En] Ninguno
*/
void testDriverValoresAltosyBajos(){
        uint16_t virtualLedsZ;
	LedDriver_Create(&virtualLedsZ);
	LedDriver_TurnOn(1,&virtualLedsZ);
	LedDriver_TurnOn(16,&virtualLedsZ);
	TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLedsZ);
/*!
*@param -> Ninguno
*@return -> Ninguno
*/
}

/*!
* \brief Test 9 Verificación de valores fuera de límites.
* \param[En] Ninguno
*/ 
void testDriverValoresFueradeLimites(){
	uint16_t virtualLedsW;
        LedDriver_Create(&virtualLedsW);
	LedDriver_TurnOn(-1,&virtualLedsW);
	LedDriver_TurnOn(0,&virtualLedsW);
	LedDriver_TurnOn(17,&virtualLedsW);	
	LedDriver_TurnOn(3141,&virtualLedsW);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLedsW);
/*!
*@param -> Ninguno
*@return -> Ninguno
*/
}


