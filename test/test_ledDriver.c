#include "unity.h"
#include "ledDriver.h"

uint16_t address;

void setUp(){

}

void tearDown(){
	address=0;
}

/* Test 1 Todos los leds deben estar apagados después de inicializar el driver */
void testDriver_LedsOffAfterCreate(){
	uint16_t virtualLedsTx=0xFFFF;//Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLedsTx);//funcion que quiero testear
	TEST_ASSERT_EQUAL_HEX16(0,virtualLedsTx);
}

void testDriver_TurnOnledUno(){
	uint16_t virtualLeds=0x0001;//Req 2,Req 5,Req 6 y Req 8.Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds);//funcion que quiero testear
        LedDriver_TurnOn(1,&virtualLeds);//Req 7->"1" Encendido/ "0" Apagado
	TEST_ASSERT_EQUAL_HEX16(1,virtualLeds);
}

/*Test 2 Un led puede ser encendido individualmente*/
void testDriver_TurnOffledUno(){

	uint16_t virtualLeds1=0x0001;//Para el Test 1 se deja ya que pone los inicializa en 1
	LedDriver_Create(&virtualLeds1);//funcion que quiero testear
        LedDriver_TurnOff(1,&virtualLeds1);//Req 7->"1" Encendido/ "0" Apagado
	TEST_ASSERT_EQUAL_HEX16(0,virtualLeds1);
}


/****************************Test 4 Múltiple leds pueden ser encendidos/apagados *********************/
void testDriver_TurnOnMultipleLeds(){
	uint16_t virtualLedsX;
        LedDriver_Create(&virtualLedsX); //
	LedDriver_TurnOn(9,&virtualLedsX);
	LedDriver_TurnOn(8,&virtualLedsX);
	TEST_ASSERT_EQUAL_HEX16(0x180, virtualLedsX);
}

/***********************Apagar multiples leds**********************************/
void testDriver_TurnOffMultipleLeds(){
	uint16_t virtualLedsA;
        LedDriver_Create(&virtualLedsA); //
	LedDriver_TurnAllOn(&virtualLedsA);
	LedDriver_TurnOff(9,&virtualLedsA);
	LedDriver_TurnOff(8,&virtualLedsA);
	TEST_ASSERT_EQUAL_HEX16((~0x180)&0xffff, virtualLedsA);
}
/***************************Aún no funciona*********************************/
void testDriver_TurnOffAnyLed(){
	uint16_t virtualLedsY;
        LedDriver_Create(&virtualLedsY);
        LedDriver_TurnAllOn(&virtualLedsY);
	LedDriver_TurnOff(8,&virtualLedsY);
	TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLedsY);
}
/*************************Aún no funciona***********************************/

/* Encender todos los leds */

void testDriver_AllLedsOn(){
    uint16_t LEDSXYZaddress;
    LedDriver_Create(&LEDSXYZaddress);
    LedDriver_TurnAllOn(&LEDSXYZaddress);  
    TEST_ASSERT_EQUAL_HEX16(0xffff, LEDSXYZaddress);
}

/* Apagar todos los leds */

void testDriver_AllLedsOff(){
    uint16_t LEDSXYZaddress2;
    LedDriver_Create(&LEDSXYZaddress2);
    LedDriver_TurnAllOn(&LEDSXYZaddress2);
    LedDriver_TurnAllOff(&LEDSXYZaddress2); 
    TEST_ASSERT_EQUAL_HEX16(0, LEDSXYZaddress2);
}

/* Test 8 Verificación de valores límites */

void testDriverValoresAltosyBajos(){
        uint16_t virtualLedsZ;
	LedDriver_Create(&virtualLedsZ);
	LedDriver_TurnOn(1,&virtualLedsZ);
	LedDriver_TurnOn(16,&virtualLedsZ);
	TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLedsZ);
}

/* Test 9 Verificación de valores fuera de límites */ 

void testDriverValoresFueradeLimites(){
	uint16_t virtualLedsW;
        LedDriver_Create(&virtualLedsW);
	LedDriver_TurnOn(-1,&virtualLedsW);
	LedDriver_TurnOn(0,&virtualLedsW);
	LedDriver_TurnOn(17,&virtualLedsW);	
	LedDriver_TurnOn(3141,&virtualLedsW);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLedsW);
}


