/*
 * =====================================================================================
 *
 *       Filename:  timer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31/05/2018 19:30:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Francisco Helder (FHC), helderhdw@gmail.com
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#include "timer.h"
#include "uart.h"

/******************************************************************************
**                      INTERNAL FUNCTION PROTOTYPES
*******************************************************************************/

/******************************************************************************
**                      INTERNAL VARIABLE DEFINITIONS
*******************************************************************************/

/*FUNCTION*-------------------------------------------------------
*
* Function Name : DMTimerWritePostedStatusGet
* Comments      : Read the status of Write Posted Status register.
*
* \param   baseAdd       Base Address of the DMTimer Module Register.
*
* \return  This API returns the status of TWPS register.
*END*-----------------------------------------------------------*/
static unsigned int DMTimerWritePostedStatusGet(unsigned int baseAdd) {
    /* Return the status of TWPS register */
    return (HWREG(baseAdd + DMTIMER_TWPS));
}


/*FUNCTION*-------------------------------------------------------
*
* Function Name : DMTimerWaitForWrite
* Comments      : This macro will check for write POSTED status
*
* \param   reg          Register whose status has to be checked
*
*    'reg' can take the following values \n
*    DMTIMER_WRITE_POST_TCLR - Timer Control register \n
*    DMTIMER_WRITE_POST_TCRR - Timer Counter register \n
*    DMTIMER_WRITE_POST_TLDR - Timer Load register \n
*    DMTIMER_WRITE_POST_TTGR - Timer Trigger register \n
*    DMTIMER_WRITE_POST_TMAR - Timer Match register \n
*
*END*-----------------------------------------------------------*/
#define DMTimerWaitForWrite(reg, baseAdd)   \
            if(HWREG(baseAdd + DMTIMER_TSICR) & DMTIMER_TSICR_POSTED)\
            while((reg & DMTimerWritePostedStatusGet(baseAdd)));


/*FUNCTION*-------------------------------------------------------
*
* Function Name : DMTimerCounterSet
* Comments      :Set/Write the Counter register with the counter value.
*
* \param   baseAdd       Base Address of the DMTimer Module Register.
* \param   counter       Count value for the timer.
*
* \return  None.
*
* \note    Value can be loaded into the counter register when the counter is 
*          stopped or when it is running.
*
*END*-----------------------------------------------------------*/
void DMTimerCounterSet(unsigned int baseAdd, unsigned int counter) {
    /* Wait for previous write to complete */
    DMTimerWaitForWrite(DMTIMER_WRITE_POST_TCRR, baseAdd);

    /* Set the counter value */
    HWREG(baseAdd + DMTIMER_TCRR) = counter;
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : DMTimerCounterGet
* Comments      : Get/Read the counter value from the counter register.
*
* \param   baseAdd       Base Address of the DMTimer Module Register.
*
* \return  This API returns the count value present in the DMTimer Counter
*          register.
*
* \note:   Value can be read from the counter register when the counter is
*          stopped or when it is running.
*END*-----------------------------------------------------------*/
unsigned int DMTimerCounterGet(unsigned int baseAdd){
    /* Wait for previous write to complete */
    DMTimerWaitForWrite(DMTIMER_WRITE_POST_TCRR, baseAdd);

    /* Read the counter value from TCRR */
    return (HWREG(baseAdd + DMTIMER_TCRR));
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : DMTimerEnable
* Comments      :This API will start the timer.  
* \param   baseAdd       Base Address of the DMTimer Module Register.
*
* \return  None.
*
* \note    The timer must be configured before it is started/enabled.
*
*END*-----------------------------------------------------------*/
void DMTimerEnable(unsigned int baseAdd){

    /* Wait for previous write to complete */
    DMTimerWaitForWrite(DMTIMER_WRITE_POST_TCLR, baseAdd);

    /* Start the timer */
    HWREG(baseAdd + DMTIMER_TCLR) |= DMTIMER_TCLR_ST;
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : DMTimerDisable
* Comments      :This API will stop the timer.  
* \param   baseAdd       Base Address of the DMTimer Module Register.
*
* \return  None.
*
*END*-----------------------------------------------------------*/
void DMTimerDisable(unsigned int baseAdd){

    /* Wait for previous write to complete */
    DMTimerWaitForWrite(DMTIMER_WRITE_POST_TCLR, baseAdd);

    /* Stop the timer */
    HWREG(baseAdd + DMTIMER_TCLR) &= ~DMTIMER_TCLR_ST;
}

/*FUNCTION*-------------------------------------------------------
*
* Function Name : DMTimerSetup
* Comments      : Setup the timer for one-shot and compare mode.
*
* \param   
*
*END*-----------------------------------------------------------*/
void DMTimerSetUp(void){
    /*  Clock enable for DMTIMER7 TRM 8.1.12.1.25 */
	ckmSetCLKModuleRegister(SOC_CM_PER_REGS, CM_PER_TIMER7_CLKCTRL, CM_PER_TIMER7_CLKCTRL_MODULEMODE_ENABLE);

    while((HWREG(SOC_CM_PER_REGS + CM_PER_TIMER7_CLKCTRL) &
    CM_PER_TIMER7_CLKCTRL_MODULEMODE) != CM_PER_TIMER7_CLKCTRL_MODULEMODE_ENABLE){};
}

#ifdef INTERRUPT

void delay(unsigned int mSec){

    unsigned int countVal = TIMER_OVERFLOW - (mSec * TIMER_1MS_COUNT);

    /* Wait for previous write to complete */
    DMTimerWaitForWrite(DMTIMER_TWPS_W_PEND_TCRR, SOC_DMTIMER_7_REGS);

    /* Load the register with the re-load value */
    HWREG(SOC_DMTIMER_7_REGS + DMTIMER_TCRR) = countVal;

    flag_timer = false;

    /* Enable the DMTimer interrupts */
    HWREG(SOC_DMTIMER_7_REGS + DMTIMER_IRQENABLE_SET) = DMTIMER_TWPS_W_PEND_TCRR;

    /* Start the DMTimer */
    DMTimerEnable(SOC_DMTIMER_7_REGS);

    while(flag_timer == false);

    /* Disable the DMTimer interrupts */
    HWREG(SOC_DMTIMER_7_REGS + DMTIMER_IRQENABLE_CLR) = 0x2;
}

#else

/*FUNCTION*-------------------------------------------------------
*
* Function Name : Delay
* Comments      :
*END*-----------------------------------------------------------*/
void delay(unsigned int mSec){
	while(mSec != 0){
        DMTimerCounterSet(SOC_DMTIMER_7_REGS, 0);
        DMTimerEnable(SOC_DMTIMER_7_REGS);
        while(DMTimerCounterGet(SOC_DMTIMER_7_REGS) < TIMER_1MS_COUNT);
        DMTimerDisable(SOC_DMTIMER_7_REGS);
        mSec--;
    }
}

#endif //INTERRUPT


