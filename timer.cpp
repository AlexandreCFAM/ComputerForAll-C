#include "timer.h"
#include "Arduino.h"
#include "task.h"

Timer timer;

void Timer::init(unsigned long period, void (*function)())
{
    Serial.println("Setting up timer...");
    Timer::update(period);
    Timer::Function = function;
}

ISR (TIMER2_OVF_vect)
{
    TCNT2 = 0;
    timer.count++;
    if(timer.count >= timer.noverflow)
    {
        timer.count = 0;
        if(timer.IsUsed) timer.Function();
        else;       
    }else;
}

void Timer::update(unsigned long period)
{
    IsUsed = true;
    //Un débordement = 4096 µs donc pour p µs il faut : (int)p/4096
    noverflow = (unsigned int)(period / 4096);
    count = 0;
    TCCR2A = 0;
    TCCR2B = 0b00000110; // horloge / 256
    TIMSK2 = 0b00000001;
    TCNT2 = 0;
    sei();
}

void Timer::update(unsigned long period, void (*function)())
{
    Timer::Function = function;
    Timer::update(period);
}

void Timer::stop()
{
    IsUsed = false;
}

void TimerFunctionExample()
{
    Serial.println("salut!");
}