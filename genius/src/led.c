//
// Created by ryan on 28/06/23.
//

#include "led.h"

void ledConfig(){
    /*-----------------------------------------------------------------------------
     * configure mux pin in control module
     *-----------------------------------------------------------------------------*/
    HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a5)   |= 7;
    HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a6)   |= 7;
    HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a7)   |= 7;
    HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a8)   |= 7;
    HWREG(SOC_CONTROL_REGS+CM_conf_lcd_data0) |= 7;
    HWREG(SOC_CONTROL_REGS+CM_conf_lcd_data1) |= 7;
    HWREG(SOC_CONTROL_REGS+CM_conf_lcd_data2) |= 7;
    HWREG(SOC_CONTROL_REGS+CM_conf_lcd_data3) |= 7;

    /*-----------------------------------------------------------------------------
     *  set pin direction as output
     *-----------------------------------------------------------------------------*/
    HWREG(SOC_GPIO_1_REGS+GPIO_OE) &= ~(0x1E00000);
    HWREG(SOC_GPIO_2_REGS+GPIO_OE) &= ~(0x3C0);
}

void ledOn(pinNum PIN){
    switch (PIN) {
        case PIN1:
            HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<21;
            break;
        case PIN2:
            HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<22;
            break;
        case PIN3:
            HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<23;
            break;
        case PIN4:
            HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<24;
            break;
        case PROTO1:
            HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<6;
            break;
        case PROTO2:
            HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<7;
            break;
        case PROTO3:
            HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<8;
            break;
        case PROTO4:
            HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<9;
            break;
        default:
            break;
    }
}

void ledOff(pinNum PIN){
    switch (PIN) {
        case PIN1:
            HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<21;
            break;
        case PIN2:
            HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<22;
            break;
        case PIN3:
            HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<23;
            break;
        case PIN4:
            HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<24;
            break;
        case PROTO1:
            HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<6;
            break;
        case PROTO2:
            HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<7;
            break;
        case PROTO3:
            HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<8;
            break;
        case PROTO4:
            HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<9;
            break;
        default:
            break;
    }
}

