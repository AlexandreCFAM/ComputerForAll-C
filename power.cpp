#include "power.h"
#include "Arduino.h"
#include "memory.h"
#include "task.h"

struct Task PowerTask;

Power PowerManager;

void Power::init()
{
    InitTask(5250, &PowerTaskFunction, &millis, &PowerTask);
}

float Power::voltage()
{
    ADMUX = 0x4F;
    delayMicroseconds(5);
    ADMUX = 0x4E;
    delayMicroseconds(200);
    ADCSRA |= (1 << ADEN);
    ADCSRA |= (1 << ADSC);
    while(ADCSRA & (1 << ADSC));
    return (1023 * 1.1) / ((unsigned int)ADCL | (ADCH << 8));
}

bool Power::state()
{
    if(Power::voltage() < 5.00 or Power::voltage() > 5.50) return false; // Bad
    else return true; //Good
}

void PowerTaskFunction()
{
    if(!PowerManager.state()) Serial.println("Power too low !");
    else;
}