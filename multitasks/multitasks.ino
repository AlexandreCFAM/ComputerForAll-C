#include <Arduino.h>
#include "scheduler.h"
#include "task.h"

struct Task task1;
struct Task task2;
struct Task task3;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  InitTask(245, &BlinkOn, &millis, &task1);
  InitTask(230, &BlinkOff, &millis, &task2);
  InitTask(2500, &ShowMessage, &millis, &task3);a
}


void loop()
{
  Scheduler::run();
}

void BlinkOn()
{
  digitalWrite(LED_BUILTIN, HIGH);
}

void BlinkOff()
{
  digitalWrite(LED_BUILTIN, LOW);
}

void ShowMessage()
{
  Serial.println("Hello World!");
}