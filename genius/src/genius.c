//
// Created by ryan on 28/06/23.
//

#include "genius.h"

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusGpioModSetup
 *  Description:  configure Genius Game GPIO clock modules
 * =====================================================================================
 */
void geniusGpioModSetup() {
    gpioInitModule(GPIO1);
    gpioInitModule(GPIO2);
    gpioInitModule(GPIO3);
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusButtonSetup
 *  Description:  Configure Genius required buttons as input and interrupts
 * =====================================================================================
 */
void geniusButtonSetup() {
    intButtonSetup(GPIO1, B, PIN16);    //Yellow led
    intButtonSetup(GPIO1, A, PIN17);   //Blue led
    intButtonSetup(GPIO3, B, PIN21);  //Green led  
    intButtonSetup(GPIO3, A, PIN19); //Red led
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusLedSetup
 *  Description:  configure Genius game leds mux and direction as output
 * =====================================================================================
 */
void geniusLedSetup() {
    for(int i = 7; i <= 13; i+= 2){
        gpioPinMuxSetup(GPIO2, i);
        gpioSetDirection(GPIO2, i, OUTPUT);
    }
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusSetup
 *  Description:  execute all Genius required setup functions
 * =====================================================================================
 */
void geniusSetup() {
    geniusGpioModSetup();
    geniusButtonSetup();
    geniusLedSetup();
}