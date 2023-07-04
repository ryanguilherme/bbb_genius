//
// Created by ryan on 28/06/23.
//

#include "interrupt.h"

#include "hw_types.h"
#include "uart.h"

void timerIrqHandler(void) {
    HWREG(SOC_DMTIMER_7_REGS + DMTIMER_IRQSTATUS) = 0x2;

    flag_timer = true;

    DMTimerDisable(SOC_DMTIMER_7_REGS);
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  gpioIsrHandler
 *  Description: Interrupt Service Routine for GPIO
 * =====================================================================================
 */
void gpioIsrHandler(void){

    uartPutString(UART0, "BUTTON PRESSED\n\r", 17);
    /* Clear the status of the interrupt flags */
    HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_0) = 0x10000000;

    flag_gpio ^= 1;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  ISR_Handler
 *  Description: Interrupt Service Routine
 * =====================================================================================
 */

void ISR_Handler(void){
	/* Verify active IRQ number */
	unsigned int irq_number = HWREG(INTCPS + INTC_SIR_IRQ) & 0x7f;
	switch(irq_number){
		case 95:
			timerIrqHandler();
			uartPutString(UART0,"Interupt timer on!\n\r",21);
			break;
		case 98:
			gpioIsrHandler();
			uartPutString(UART0,"Interupt button on!\n\r",23);
			break;
	}
    /* acknowledge IRQ */
	HWREG(INTCPS + INTC_CONTROL) = 0x1;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  mirClear
 *  Description: Enable interrupt for a specific source
 * =====================================================================================
 */

void mirClear(int number) {
    int MIR_CLEAR = number / 32;
    int SOURCE = number % 32;
    switch (MIR_CLEAR) {
        case 0:
            HWREG(INTCPS + INTC_MIR_CLEAR0) |= (1<<SOURCE);
            break;
        case 1:
            HWREG(INTCPS + INTC_MIR_CLEAR1) |= (1<<SOURCE);
            break;
        case 2:
            HWREG(INTCPS + INTC_MIR_CLEAR2) |= (1<<SOURCE);
            break;
        case 3:
            HWREG(INTCPS + INTC_MIR_CLEAR3) |= (1<<SOURCE);
            break;
        default:
            break;
    }
}