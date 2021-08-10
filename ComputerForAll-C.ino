#include "task.h"
#include "scheduler.h"
#include "power.h"
#include "Arduino.h"
#include "audio.h"
#include "timer.h"

void setup()
{
  Serial.begin(9600);
  // delay(500);
  Serial.println(F("Booting kernel..."));
  PowerManager.init();
  audio.init();
  audio.buzz(440, 150);
  // audio.buzz(440, 150);
}

void loop()
{
  Scheduler::run();
}
