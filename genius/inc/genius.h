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
 
extern int sequence[];
extern int sequenceSize;
extern int currentSeq[16][16];
extern int contCurrentSequence;

void geniusGpioModSetup();
void geniusButtonSetup();
void geniusLedSetup();
void geniusSetup();
void geniusLedSequence();


#endif //GENIUS_H
