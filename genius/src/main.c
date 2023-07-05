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
int currentSeq[16][16];
int currentIndex = 0;
int contCurrentSequence = 0;
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

    gpioPinMuxSetup(GPIO2, 8);
    gpioSetDirection(GPIO2, 8, OUTPUT);

    uartPutString(UART0, "Pressione o botão para iniciar o jogo\n\r", 40);

    while(1){
        //uartPutString(UART0, "Pressione o botão para iniciar o jogo\n\r", 40);
        while(GPIOINT2A){
            gpioSetPinValue(GPIO2, 8, HIGH);
            delay(100);
            gpioSetPinValue(GPIO2, 8, LOW);
            delay(100);
            gpioSetPinValue(GPIO2, 8, HIGH);
            delay(100);
            gpioSetPinValue(GPIO2, 8, LOW);

            geniusLedSequence();
            
            delay(3000); // espera 3 segundos para começar a verificar 

            
            for(int i = 0; i < sequenceSize; i++){
                if(sequence[i] == RED){
                    if(GPIOINT3A && currentSeq[currentIndex][i] == RED){
                        uartPutString(UART0, "Você acertou o botao vermelho\n\r", 32);
                        GPIOINT3A = false;
                    }else{
                        uartPutString(UART0, "Você errou a sequencia\n\r", 26);
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
                        currentIndex = -1;
                        gpioSetPinValue(GPIO2, 8, HIGH);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, LOW);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, HIGH);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, LOW);
                        uartPutString(UART0, "Pressione o botão para iniciar o jogo\n\r", 40);
                        break;
                    }
                }
                else if(sequence[i] == GREEN){
                    if(GPIOINT3B && currentSeq[currentIndex][i] == GREEN){
                        uartPutString(UART0, "Você acertou o botao verde\n\r", 29);
                        GPIOINT3B = false;
                    }else{
                        uartPutString(UART0, "Você errou a sequencia\n\r", 26);
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
                        currentIndex = -1;
                        gpioSetPinValue(GPIO2, 8, HIGH);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, LOW);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, HIGH);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, LOW);
                        uartPutString(UART0, "Pressione o botão para iniciar o jogo\n\r", 40);
                        break;
                    }
                }
                else if(sequence[i] == BLUE){
                    if(GPIOINT1A && currentSeq[currentIndex][i] == BLUE){
                        uartPutString(UART0, "Você acertou o botao azul\n\r", 28);
                        GPIOINT1A = false;
                    }else{
                        uartPutString(UART0, "Você errou a sequencia\n\r", 26);
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
                        currentIndex = -1;
                        gpioSetPinValue(GPIO2, 8, HIGH);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, LOW);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, HIGH);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, LOW);
                        uartPutString(UART0, "Pressione o botão para iniciar o jogo\n\r", 40);
                        break;
                    }
                }
                else if(sequence[i] == YELLOW){
                    if(GPIOINT1B && currentSeq[currentIndex][i] == YELLOW){
                        uartPutString(UART0, "Você acertou o botao amarelo\n\r", 32);
                        GPIOINT1B = false;
                    }else{
                        uartPutString(UART0, "Você errou a sequencia\n\n\n\n\r", 29);
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
                        currentIndex = -1;
                        gpioSetPinValue(GPIO2, 8, HIGH);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, LOW);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, HIGH);
                        delay(500);
                        gpioSetPinValue(GPIO2, 8, LOW);
                        uartPutString(UART0, "Pressione o botão para iniciar o jogo\n\r", 40);
                        break;
                    }
                }

                delay(1000);
            }

            sequenceSize++;
            currentIndex++;
            contCurrentSequence = 0;
            if(sequenceSize >= 16){
                uartPutString(UART0, "Você ganhou o jogo\n\r", 21);
                sequenceSize = 1;
                currentIndex = 0;
                GPIOINT2A = false;
                
                gpioSetPinValue(GPIO2, 7, HIGH);
                gpioSetPinValue(GPIO2, 9, HIGH);
                gpioSetPinValue(GPIO2, 11, HIGH);
                gpioSetPinValue(GPIO2, 13, HIGH);
                delay(1000);
                gpioSetPinValue(GPIO2, 7, LOW);
                gpioSetPinValue(GPIO2, 9, LOW);
                gpioSetPinValue(GPIO2, 11, LOW);
                gpioSetPinValue(GPIO2, 13, LOW);

                gpioSetPinValue(GPIO2, 8, HIGH);
                delay(2000);
                gpioSetPinValue(GPIO2, 8, LOW);

                gpioSetPinValue(GPIO2, 8, HIGH);
                delay(100);
                gpioSetPinValue(GPIO2, 8, LOW);
                gpioSetPinValue(GPIO2, 8, HIGH);
                delay(100);
                gpioSetPinValue(GPIO2, 8, LOW);
                break;
            }
        } 
    }

	return(0);
} /* ----------  end of function main  ---------- */

/* COMPILE AND RUN
 * setenv app "setenv autoload no; setenv ipaddr 10.4.1.2; setenv serverip 10.4.1.1; tftp 0x80000000 /tftpboot/appGenius.bin; go 0x80000000;"
 * run app
*/
