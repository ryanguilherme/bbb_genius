#include "buzzer.h"

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  buzzerSoundStart
 *  Description:  produces the sound at the beggining of the game
 * =====================================================================================
 */

void buzzerSoundStart(){
    gpioSetPinValue(GPIO2, 8, HIGH);
    delay(100);
    gpioSetPinValue(GPIO2, 8, LOW);
    delay(100);
    gpioSetPinValue(GPIO2, 8, HIGH);
    delay(100);
    gpioSetPinValue(GPIO2, 8, LOW);
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  buzzerGameOver
 *  Description:  produces the gameover sound
 * =====================================================================================
 */

void buzzerGameOver(){
    gpioSetPinValue(GPIO2, 8, HIGH);
    delay(250);
    gpioSetPinValue(GPIO2, 8, LOW);
    delay(250);
//    gpioSetPinValue(GPIO2, 8, HIGH);
//    delay(500);
//    gpioSetPinValue(GPIO2, 8, LOW);
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  buzzerGameOver
 *  Description:  produces the sound of victory
 * =====================================================================================
 */

void buzzerVictorySound(){
    gpioSetPinValue(GPIO2, 8, HIGH);
    delay(2000);
    gpioSetPinValue(GPIO2, 8, LOW);

    gpioSetPinValue(GPIO2, 8, HIGH);
    delay(100);
    gpioSetPinValue(GPIO2, 8, LOW);
    gpioSetPinValue(GPIO2, 8, HIGH);
    delay(100);
    gpioSetPinValue(GPIO2, 8, LOW);
}