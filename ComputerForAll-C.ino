#include "task.h"
#include "scheduler.h"
#include "power.h"
#include "Arduino.h"

void setup()
{
  Serial.begin(9600);
  PowerManager.init();
}

void loop()
{
  Scheduler::run();
}
