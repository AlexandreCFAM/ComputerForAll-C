#ifndef __SCHEDULER__H
#define __SCHEDULER_H

#define TASKS_NUMBER 10

#include "task.h"

namespace Scheduler
{
    extern unsigned char TasksCount;
    extern struct Task *TasksList[10];
    extern unsigned char count;
    bool AddTask(struct Task *task);
    void run();
};

#endif