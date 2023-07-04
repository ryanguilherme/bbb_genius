//
// Created by ryan on 28/06/23.
//

#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "soc_AM335x.h"
#include "hw_types.h"
#include "timer.h"
#include "gpio.h"

extern bool flag_gpio;
extern bool flag_timer;

/**
 * GPIO INTERRUPTION FLAGS DECLARATION
**/
bool GPIOINT0A;
bool GPIOINT0B;
bool GPIOINT1A;
bool GPIOINT1B;
bool GPIOINT2A;
bool GPIOINT2B;
bool GPIOINT3A;
bool GPIOINT3B;

#define INTCPS                  0x48200000
#define INTC_MIR_CLEAR0         0x88
#define INTC_MIR_CLEAR1         0xA8
#define INTC_MIR_CLEAR2         0xC8
#define INTC_MIR_CLEAR3         0xE8
#define INTC_SIR_IRQ            0x40
#define INTC_CONTROL            0x48

void gpioIsrHandler(gpioMod, intMode, pinNum);
void ISR_Handler(void);
void timerIrqHandler(void);
void mirClear(int);

#endif //INTERRUPT_H
