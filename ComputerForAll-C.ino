#include "task.h"
#include "scheduler.h"
#include "power.h"
#include "Arduino.h"
#include "memory.h"

void setup()
{
  Serial.begin(9600);
  PowerManager.init();
  if(!memory::init())
  {
    Serial.println("Error while memory initializing!");
    while(1);
  }else;
}

void loop()
{
  Scheduler::run();
}
