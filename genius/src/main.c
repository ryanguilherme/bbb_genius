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
int sequence[] ={RED, BLUE, GREEN, YELLOW, RED, BLUE, GREEN, YELLOW, RED, BLUE, GREEN, YELLOW, RED, BLUE, GREEN, YELLOW};

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

    DMTimerSetUp();

    while(1){
        uartPutString(UART0, "Pressione o botão para iniciar o jogo\n\r", 40);
        while(GPIOINT2A){
           for(int i = 0; i < sequenceSize; i++){
                if(sequence[i] == RED){
                    gpioSetPinValue(GPIO2, 7, HIGH);
                    delay(1000);
                    gpioSetPinValue(GPIO2, 7, LOW);
                }
                else if(sequence[i] == GREEN){
                    gpioSetPinValue(GPIO2, 9, HIGH);
                    delay(1000);
                    gpioSetPinValue(GPIO2, 9, LOW);
                }
                else if(sequence[i] == BLUE){
                    gpioSetPinValue(GPIO2, 11, HIGH);
                    delay(1000);
                    gpioSetPinValue(GPIO2, 11, LOW);
                }
                else if(sequence[i] == YELLOW){
                    gpioSetPinValue(GPIO2, 13, HIGH);
                    delay(1000);
                    gpioSetPinValue(GPIO2, 13, LOW);
                }
            }

            delay(3000);

            for(int i = 0; i < sequenceSize; i++){
                if(sequence[i] == RED){
                    if(GPIOINT3A){
                        uartPutString(UART0, "Você acertou a sequência\n\r", 28);
                        GPIOINT3A = false;
                    }else{
                        gpioSetPinValue(GPIO2, 7, HIGH);
                        gpioSetPinValue(GPIO2, 9, HIGH);
                        gpioSetPinValue(GPIO2, 11, HIGH);
                        gpioSetPinValue(GPIO2, 13, HIGH);
                        delay(1000);
                        gpioSetPinValue(GPIO2, 7, LOW);
                        gpioSetPinValue(GPIO2, 9, LOW);
                        gpioSetPinValue(GPIO2, 11, LOW);
                        gpioSetPinValue(GPIO2, 13, LOW);
                        GPIOINT2A = false;
                        sequenceSize = 0;
                        break;
                    }
                }
                else if(sequence[i] == GREEN){
                    if(GPIOINT3B){
                        uartPutString(UART0, "Você acertou a sequência\n\r", 28);
                        GPIOINT3B = false;
                    }else{
                        gpioSetPinValue(GPIO2, 7, HIGH);
                        gpioSetPinValue(GPIO2, 9, HIGH);
                        gpioSetPinValue(GPIO2, 11, HIGH);
                        gpioSetPinValue(GPIO2, 13, HIGH);
                        delay(1000);
                        gpioSetPinValue(GPIO2, 7, LOW);
                        gpioSetPinValue(GPIO2, 9, LOW);
                        gpioSetPinValue(GPIO2, 11, LOW);
                        gpioSetPinValue(GPIO2, 13, LOW);
                        GPIOINT2A = false;
                        sequenceSize = 0;
                        break;
                    }
                }
                else if(sequence[i] == BLUE){
                    if(GPIOINT1A){
                        uartPutString(UART0, "Você acertou a sequência\n\r", 28);
                        GPIOINT1A = false;
                    }else{
                        gpioSetPinValue(GPIO2, 7, HIGH);
                        gpioSetPinValue(GPIO2, 9, HIGH);
                        gpioSetPinValue(GPIO2, 11, HIGH);
                        gpioSetPinValue(GPIO2, 13, HIGH);
                        delay(1000);
                        gpioSetPinValue(GPIO2, 7, LOW);
                        gpioSetPinValue(GPIO2, 9, LOW);
                        gpioSetPinValue(GPIO2, 11, LOW);
                        gpioSetPinValue(GPIO2, 13, LOW);
                        GPIOINT2A = false;
                        sequenceSize = 0;
                        break;
                    }
                }
                else if(sequence[i] == YELLOW){
                    if(GPIOINT1B){
                        uartPutString(UART0, "Você acertou a sequência\n\r", 28);
                        GPIOINT1B = false;
                    }else{
                        gpioSetPinValue(GPIO2, 7, HIGH);
                        gpioSetPinValue(GPIO2, 9, HIGH);
                        gpioSetPinValue(GPIO2, 11, HIGH);
                        gpioSetPinValue(GPIO2, 13, HIGH);
                        delay(1000);
                        gpioSetPinValue(GPIO2, 7, LOW);
                        gpioSetPinValue(GPIO2, 9, LOW);
                        gpioSetPinValue(GPIO2, 11, LOW);
                        gpioSetPinValue(GPIO2, 13, LOW);
                        GPIOINT2A = false;
                        sequenceSize = 0;
                        break;
                    }
                }
            }

            sequenceSize++;
        } 
    }

	return(0);
} /* ----------  end of function main  ---------- */

/* COMPILE AND RUN
 * setenv app "setenv autoload no; setenv ipaddr 10.4.1.2; setenv serverip 10.4.1.1; tftp 0x80000000 /tftpboot/appGenius.bin; go 0x80000000;"
 * run app
*/
