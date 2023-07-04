//
// Created by ryan on 28/06/23.
//

#ifndef GENIUS_H
#define GENIUS_H

#include "soc_AM335x.h"
#include "hw_types.h"
#include "control_module.h"
#include "gpio.h"

typedef enum color{
    RED,
    GREEN,
    BLUE,
    YELLOW
}Color;
 
int sequence[] ={RED, BLUE, GREEN, YELLOW, RED, BLUE, GREEN, YELLOW, RED, BLUE, GREEN, YELLOW, RED, BLUE, GREEN, YELLOW};
int sequenceSize = 1;

void geniusGpioModSetup();
void geniusButtonSetup();
void geniusLedSetup();
void geniusSetup();


#endif //GENIUS_H
