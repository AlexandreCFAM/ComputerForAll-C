#include "task.h"
#include "scheduler.h"
#include "power.h"
#include "Arduino.h"
#include "audio.h"

void setup()
{
  Serial.begin(9600);
  PowerManager.init();
  audio.init();
}

void loop()
{
  Scheduler::run();
}
