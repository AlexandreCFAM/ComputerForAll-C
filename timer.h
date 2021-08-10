#ifndef __KERNEL__TIMER__H
#define __KERNEL__TIMER__H

class Timer
{
public:
    void init(unsigned long period, void (*function)());
    short int count;
    unsigned int noverflow;
    void update(unsigned long period);
    void update(unsigned long period, void (*function)()); //Pour changer la fonction si on a besoin
    void (*Function)();
    bool IsUsed; //Permet de dire aux autres fonctions que le timer est déjà utilisé et qu'il faut attendre
    void stop();
};

extern Timer timer;

void TimerFunctionExample();

#endif