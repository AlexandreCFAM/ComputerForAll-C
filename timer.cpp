#include "Arduino.h"
#include "timer.h"

#define TIMER2_PERIOD 0.5 //µs

Timer2 timer2;

void Timer2::init()
{
    Serial.println("Setting up timer 2...");
    cli();
    bitClear(TCCR2A, WGM20);
    bitClear(TCCR2A, WGM21);
    TCCR2B = 0b00000010;
    TIMSK2 = 0b00000001;
    TCNT2 = 0;
    sei();
    Timer2::OverflowCount = 0;
}

ISR(TIMER2_OVF_vect)
{
    TCNT2 = 0;
    timer2.OverflowCount++;
}