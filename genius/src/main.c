/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/07/2023 22:00:00
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *        Authors:  Ryan Guilherme (ryanguilhermetbt@gmail.com)
 *                  Guilherme Araújo ()
 *                  Éliton Melo (elitonp.melo@gmail.com)
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#include "timer.h"
#include "gpio.h"
#include "hw_types.h"
#include "soc_AM335x.h"
#include "interrupt.h"
#include "genius.h"
#include "uart.h"
#include "buzzer.h"

/**
 * INTERRUPTS BUTTONS FLAG DECLARATION
**/
bool GPIOINT0A = false;
bool GPIOINT0B = false;
bool GPIOINT1A = false;
bool GPIOINT1B = false;
bool GPIOINT2A = false;
bool GPIOINT2B = false;
bool GPIOINT3A = false;
bool GPIOINT3B = false;

/**
 * LED SEQUENCE ATTRIBUTES
**/
int sequenceSize = 1;
//int sequence[] ={RED, BLUE, GREEN, YELLOW, RED, BLUE, GREEN, YELLOW, RED, BLUE, GREEN, YELLOW, RED, BLUE, GREEN, YELLOW};
int sequence[5][16] = {
        {RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW},
        {BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN},
        {GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED},
        {YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE},
        {RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW, RED, GREEN, BLUE, YELLOW}
    };
int linha = 0;    
int currentSeq[16][16];
int currentIndex = 0;
int contCurrentSequence = 0;
int tempDelay = 2000;
bool flag_timer;

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  main function
 * =====================================================================================
 */
int main(void){

    disableWdt();

    geniusSetup();

    uartPutString(UART0, "Pressione o botão para iniciar o jogo\n\r", 40);

    while(1){
        geniusGameLoop(); 
    }

	return(0);
} /* ----------  end of function main  ---------- */

/* COMPILE AND RUN
 * setenv app "setenv autoload no; setenv ipaddr 10.4.1.2; setenv serverip 10.4.1.1; tftp 0x80000000 /tftpboot/appGenius.bin; go 0x80000000;"
 * run app
*/
