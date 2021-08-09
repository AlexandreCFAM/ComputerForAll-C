#ifndef __KEYBOARD__DRIVER__H
#define __KEYBOARD__DRIVER__H

class Keyboard
{
public:
    Keyboard(unsigned char dp, unsigned char dm); //dp => broche d+ ; dm => broche d-
    ~Keyboard();
    bool init();
private:
    unsigned char _dp;
    unsigned char _dm;
};

#endif