#ifndef __TASK__H
#define __TASK__H

struct Task
{
    unsigned char Priority;
    int TimeWait;
    void (*Function)();
    void run();
    unsigned long (*GetCurrentTime)();
    unsigned long LastTime;
    void init();
    bool IsReady();
};
void InitTask(int TimeWait, void (*Function)(), unsigned long (*GetCurrentTime)(), struct Task *task);

#endif