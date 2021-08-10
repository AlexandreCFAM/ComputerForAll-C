#ifndef __TIMER__KERNEL__H
#define __TIMER__KERNEL__H

class Timer2
{
public:
    void init();
    unsigned long OverflowCount;
};

extern Timer2 timer2;

#endif