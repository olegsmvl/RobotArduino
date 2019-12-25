#ifndef ENCODER_H
#define ENCODER_H
#include "Arduino.h"
class Encoder
{
private:
    /* data */
public:
    Encoder();
};

Encoder::Encoder()
{
    //https://chipenable.ru/index.php/programming-avr/187-uchebnyy-kurs-avr-taymer-schetchik-t0-rezhim-normal-ch2.html
    unsigned int i;
    i = TCNT1;  //регистр счетчика
    OCR1A = 0xFF;   //регистр стравнения канал А
    TCCR1A |= (1<<CS02)|(0<<CS01)|(1<<CS00);; //регистр конфигурации канал А
}



#endif