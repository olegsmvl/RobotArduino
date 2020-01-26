#include "Encoder.h"

Encoder::Encoder()
{
    //https://chipenable.ru/index.php/programming-avr/187-uchebnyy-kurs-avr-taymer-schetchik-t0-rezhim-normal-ch2.html
    //unsigned int i;
    //i = TCNT1;  //регистр счетчика
    OCR4A = 0x6400;   //регистр стравнения канал А
    TCCR4A |= (1<<CS42)|(0<<CS41)|(1<<CS40); //делитель 128, регистр конфигурации канал А (биты тактирования и делителя)
    TCCR4A |= (1<<WGM42); //регистр конфигурации канал А, режим сброса при совпадении
    TIMSK4 |= 1<<OCIE4A; //включаем прерываение по совпадению
    //частота тактирования таймера - 8000 000 / 128 = 62,5 кгц
    //частота прерываний тактирование/OCR1A  = 62500/0x6400 = 2,44 гц

}

void Encoder::Init(){

}