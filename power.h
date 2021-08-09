#ifndef __POWER__H
#define __POWER__H

class Power
{
public:
    float voltage();
    bool state();
    void init();
};

void PowerTaskFunction();

extern Power PowerManager;

#endif