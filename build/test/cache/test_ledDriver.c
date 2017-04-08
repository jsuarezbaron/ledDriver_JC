#include "ledDriver.h"
#include "unity.h"


uint16_t address;



void setUp(){



}



void tearDown(){

 address=0;

}





void testDriver_LedsOffAfterCreate(){

 uint16_t virtualLedsTx=0xFFFF;

 LedDriver_Create(&virtualLedsTx);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtualLedsTx)), (((void *)0)), (UNITY_UINT)(18), UNITY_DISPLAY_STYLE_HEX16);

}



void testDriver_TurnOnledUno(){

 uint16_t virtualLeds=0x0001;

 LedDriver_Create(&virtualLeds);

        LedDriver_TurnOn(1,&virtualLeds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((virtualLeds)), (((void *)0)), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_HEX16);

}





void testDriver_TurnOffledUno(){



 uint16_t virtualLeds1=0x0001;

 LedDriver_Create(&virtualLeds1);

        LedDriver_TurnOff(1,&virtualLeds1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtualLeds1)), (((void *)0)), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX16);

}







void testDriver_TurnOnMultipleLeds(){

 uint16_t virtualLedsX;

        LedDriver_Create(&virtualLedsX);

 LedDriver_TurnOn(9,&virtualLedsX);

 LedDriver_TurnOn(8,&virtualLedsX);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x180)), (UNITY_INT)(UNITY_INT16)((virtualLedsX)), (((void *)0)), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_HEX16);

}





void testDriver_TurnOffMultipleLeds(){

 uint16_t virtualLedsA;

        LedDriver_Create(&virtualLedsA);

 LedDriver_TurnAllOn(&virtualLedsA);

 LedDriver_TurnOff(9,&virtualLedsA);

 LedDriver_TurnOff(8,&virtualLedsA);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)(((~0x180)&0xffff)), (UNITY_INT)(UNITY_INT16)((virtualLedsA)), (((void *)0)), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_HEX16);

}



void testDriver_TurnOffAnyLed(){

 uint16_t virtualLedsY;

        LedDriver_Create(&virtualLedsY);

        LedDriver_TurnAllOn(&virtualLedsY);

 LedDriver_TurnOff(8,&virtualLedsY);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xff7f)), (UNITY_INT)(UNITY_INT16)((virtualLedsY)), (((void *)0)), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_HEX16);

}









void testDriver_AllLedsOn(){

    uint16_t LEDSXYZaddress;

    LedDriver_Create(&LEDSXYZaddress);

    LedDriver_TurnAllOn(&LEDSXYZaddress);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xffff)), (UNITY_INT)(UNITY_INT16)((LEDSXYZaddress)), (((void *)0)), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_HEX16);

}







void testDriver_AllLedsOff(){

    uint16_t LEDSXYZaddress2;

    LedDriver_Create(&LEDSXYZaddress2);

    LedDriver_TurnAllOn(&LEDSXYZaddress2);

    LedDriver_TurnAllOff(&LEDSXYZaddress2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((LEDSXYZaddress2)), (((void *)0)), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_HEX16);

}







void testDriverValoresAltosyBajos(){

        uint16_t virtualLedsZ;

 LedDriver_Create(&virtualLedsZ);

 LedDriver_TurnOn(1,&virtualLedsZ);

 LedDriver_TurnOn(16,&virtualLedsZ);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x8001)), (UNITY_INT)(UNITY_INT16)((virtualLedsZ)), (((void *)0)), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_HEX16);

}







void testDriverValoresFueradeLimites(){

 uint16_t virtualLedsW;

        LedDriver_Create(&virtualLedsW);

 LedDriver_TurnOn(-1,&virtualLedsW);

 LedDriver_TurnOn(0,&virtualLedsW);

 LedDriver_TurnOn(17,&virtualLedsW);

 LedDriver_TurnOn(3141,&virtualLedsW);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtualLedsW)), (((void *)0)), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_HEX16);

}
