//
// Created by ryan on 28/06/23.
//

#include "genius.h"

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusGpioModSetup
 *  Description:  configure Genius Game GPIO clock modules
 * =====================================================================================
 */
void geniusGpioModSetup() {
    gpioInitModule(GPIO1);
    gpioInitModule(GPIO2);
    gpioInitModule(GPIO3);
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusButtonSetup
 *  Description:  Configure Genius required buttons as input and interrupts
 * =====================================================================================
 */
void geniusButtonSetup() {
    intButtonSetup(GPIO1, B, PIN16);    //Yellow led
    intButtonSetup(GPIO1, A, PIN17);   //Blue led
    intButtonSetup(GPIO3, B, PIN21);  //Green led  
    intButtonSetup(GPIO3, A, PIN19); //Red led
    intButtonSetup(GPIO2, A, PIN6); //Start button
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusLedSetup
 *  Description:  configure Genius game leds mux and direction as output
 * =====================================================================================
 */
void geniusLedSetup() {
    for(int i = 7; i <= 13; i+= 2){
        gpioPinMuxSetup(GPIO2, i);
        gpioSetDirection(GPIO2, i, OUTPUT);
    }    
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusBuzzerSetup
 *  Description:  configure Genius buzzer mux and direction as output
 * =====================================================================================
 */
void geniusBuzzerSetup() {
    gpioPinMuxSetup(GPIO2, 8);
    gpioSetDirection(GPIO2, 8, OUTPUT);
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusSetup
 *  Description:  execute all Genius required setup functions
 * =====================================================================================
 */
void geniusSetup() {
    geniusGpioModSetup();
    geniusButtonSetup();
    geniusLedSetup();
    geniusBuzzerSetup();
    DMTimerSetUp(); //habilita o clock para o delay
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusGameOver
 *  Description:  do all need for end and reset the game
 * =====================================================================================
 */

void geniusGameOver(){
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

    GPIOINT2A = false; //espera apertar o botão de start
    sequenceSize = 0; //reseta as variáveis para conseguir
    currentIndex = -1;//reinicar normalmente
    
    buzzerGameOver();

    uartPutString(UART0, "Pressione o botão para iniciar o jogo\n\r", 40);
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusLedSequence
 *  Description:  turning the correspondent led of the sequence
 * =====================================================================================
 */

void geniusLedSequence(){
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
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusInputProcessing
 *  Description:  do logic for incoming input
 * =====================================================================================
 */

void geniusInputProcessing(){
    for(int i = 0; i < sequenceSize; i++){
        if(sequence[i] == RED){
            if(GPIOINT3A && currentSeq[currentIndex][i] == RED){
                uartPutString(UART0, "Você acertou o botao vermelho\n\r", 32);
                GPIOINT3A = false;
            }else{
                geniusGameOver();
                break;
            }
        }
        else if(sequence[i] == GREEN){
            if(GPIOINT3B && currentSeq[currentIndex][i] == GREEN){
                uartPutString(UART0, "Você acertou o botao verde\n\r", 29);
                GPIOINT3B = false;
            }else{
                geniusGameOver();
                break;
            }
        }
        else if(sequence[i] == BLUE){
            if(GPIOINT1A && currentSeq[currentIndex][i] == BLUE){
                uartPutString(UART0, "Você acertou o botao azul\n\r", 28);
                GPIOINT1A = false;
            }else{
                geniusGameOver();
                break;
            }
        }
        else if(sequence[i] == YELLOW){
            if(GPIOINT1B && currentSeq[currentIndex][i] == YELLOW){
                uartPutString(UART0, "Você acertou o botao amarelo\n\r", 32);
                GPIOINT1B = false;
            }else{
                geniusGameOver();
                break;
            }
        }

        delay(1000);
    }
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusVictory
 *  Description:  do all need for victory and reset the game
 * =====================================================================================
 */

void geniusVictory(){
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

    buzzerVictorySound();
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusFlagsUpdate
 *  Description:  updates the flags necessary for the correct functioning of the game
 * =====================================================================================
 */

void geniusFlagsUpdate(){
    sequenceSize++; 
    currentIndex++;
    contCurrentSequence = 0;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  geniusGameLoop
 *  Description:  do the loop of game
 * =====================================================================================
 */

void geniusGameLoop(){
    while(GPIOINT2A){     
        buzzerSoundStart();

        geniusLedSequence();
        
        delay(3000); // espera 3 segundos para começar a verificar 

        geniusInputProcessing();

        geniusFlagsUpdate();

        if(sequenceSize >= 16){
            geniusVictory();
            break;
        }
    }
}