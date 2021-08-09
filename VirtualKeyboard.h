#ifndef __VIRTUAL__KEYBOARD__H
#define __VIRTUAL__KEYBOARD__H

/*
* Le clavier virtuelle est en fait la lecture du port série en attendant de développer le pilote pour le clavier physique
*/

class VirtualKeyboard
{
public:
    VirtualKeyboard(int baudrate);
};

#endif