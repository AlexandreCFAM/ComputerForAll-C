#ifndef __POWER__H
#define __POWER__H

#define POWER_BUTTON 2

class Power
{
public:
    float voltage();
    bool state();
    void init();
};

void PowerTaskFunction();
void ISR_POWER_BUTTON();

extern Power PowerManager;

#endif