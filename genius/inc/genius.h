//
// Created by ryan on 28/06/23.
//

#ifndef GENIUS_H
#define GENIUS_H

#include "soc_AM335x.h"
#include "hw_types.h"
#include "control_module.h"
#include "gpio.h"

void geniusGpioModSetup();
void geniusButtonSetup();
void geniusLedSetup();
void geniusSetup();


#endif //GENIUS_H
