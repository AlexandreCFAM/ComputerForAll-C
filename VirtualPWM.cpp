#include <Arduino.h>
#include "VirtualPWM.h"
#include "task.h"

struct Task VirtPWMTask;

/*
* Pour avoir la tension de sortie de cette sortie, on multiplie le rapport cyclique par vdd (5V par exemple)
*/

void VirtualPWM::init(void (*TaskFunction)())
{
    InitTask(VirtualPWM::T, TaskFunction, &millis, &VirtPWMTask);
}