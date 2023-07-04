//
// Created by ryan on 28/06/23.
//

#ifndef LED_H
#define LED_H

#include "soc_AM335x.h"
#include "hw_types.h"
#include "control_module.h"
#include "gpio.h"

typedef enum _pinNum{
    PIN1=1,
    PIN2,
    PIN3,
    PIN4,
    PROTO1,
    PROTO2,
    PROTO3,
    PROTO4
}pinNum;

void ledConfig();
void ledOn(pinNum);
void ledOff(pinNum);

#endif //LED_H
