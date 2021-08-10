#include "task.h"
#include "scheduler.h"
#include "power.h"
#include "Arduino.h"
#include "audio.h"
#include "timer.h"

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Booting kernel..."));
  PowerManager.init();
  timer2.init();
  audio.init();
}

void loop()
{
  Scheduler::run();
}
