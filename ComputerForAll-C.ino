#include "VirtualPWM.h"
#include "scheduler.h"

struct VirtualPWM vp;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  vp.pin = 2;
  vp.rapport = 0.90;
  vp.init(&function);
  
}

void loop()
{
  Scheduler::run();
}

void function()
{
  digitalWrite(2, HIGH);
  delay((int)(vp.T*vp.rapport));
  digitalWrite(2, LOW);
}
