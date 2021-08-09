#ifndef __TASK__H
#define __TASK__H

struct Task
{
    // unsigned char Priority;
    int TimeWait;
    void (*Function)();
    void run();
    unsigned long (*GetCurrentTime)();
    unsigned long LastTime;
    unsigned long LastTimeExecution; //Si on a besoin de savoir à quand remonte l'exécution de la tâche
    void init();
    bool IsReady();
};
void InitTask(int TimeWait, void (*Function)(), unsigned long (*GetCurrentTime)(), struct Task *task);

#endif