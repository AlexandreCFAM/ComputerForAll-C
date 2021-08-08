#ifndef __VIRTUAL_PWM__H
#define __VIRTUAL_PWM__H

#define FREQUENCY 250.0 //Hz => Essayer de ne pas dépasser cette valeur !

/*
* J'utilise la fonction milliseconds d'Arduino et elle supporte très mal les valeurs < 1 à virgule
* Càd que pour une fréquence de 1000.0 Hz, on a : (1 / (1000 * 2)) * 1000 = 0.5 ms. Mais j'obtiens 75 khz à l'oscilloscope !
* Pour obtenir des fréquences plus grande il faut utiliser delayMicroseconds mais le but n'est pas d'avoir une fréquence élevée, seulement
* de faire varier le rapport cyclique de ce signal.
*/

// #include "types.h"

struct VirtualPWM
{
    unsigned char pin;
    float rapport; //Entre 0.0 et 1.0
    unsigned short T = (1 / FREQUENCY) * 1000; //Période du signal en milliseconds
    void init(void (*TaskFunction)());
};

#endif