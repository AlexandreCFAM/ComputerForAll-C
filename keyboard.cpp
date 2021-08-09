#include "keyboard.h"
#include "Arduino.h"

Keyboard::Keyboard(unsigned char dp, unsigned char dm)
{
    _dp = dp;
    _dm = dm;
}

Keyboard::~Keyboard(){}

bool Keyboard::init()
{

}