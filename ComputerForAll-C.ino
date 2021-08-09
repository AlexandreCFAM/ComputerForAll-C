#include "task.h"
#include "scheduler.h"
#include "Arduino.h"

struct Task task1;
struct Task task2;

void setup()
{
  Serial.begin(9600);
  InitTask(500, &FirstMessage, &millis, &task1);
  InitTask(1500, &SecondMessage, &millis, &task2);
}

void loop()
{
  Scheduler::run();
}

void FirstMessage()
{
  Serial.println("Message 1!");
}

void SecondMessage()
{
  Serial.println("Message 2!");
}