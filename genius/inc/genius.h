//
// Created by ryan on 28/06/23.
//

#ifndef GENIUS_H
#define GENIUS_H

#include "soc_AM335x.h"
#include "hw_types.h"
#include "control_module.h"
#include "gpio.h"
#include "timer.h"
#include "uart.h"
#include "buzzer.h"

typedef enum color{
    RED,
    GREEN,
    BLUE,
    YELLOW
}Color;
 
extern int sequence[5][16];
extern int sequenceSize;
extern int currentSeq[16][16];
extern int contCurrentSequence;
extern int tempDelay;
extern int linha;

void geniusGpioModSetup();
void geniusButtonSetup();
void geniusLedSetup();
void geniusSetup();
void geniusLedSequence();
void geniusBuzzerSetup();
void geniusInputProcessing();
void geniusGameOver();
void geniusVictory();
void geniusFlagsUpdate();
void geniusGameLoop();

#endif //GENIUS_H
