#include "task.h"
#include "scheduler.h"

void Task::run()
{
    (*Function)();
}

void Task::init()
{
    Task::LastTime = Task::GetCurrentTime();
    Task::LastTimeExecution = Task::GetCurrentTime();
}

void InitTask(int TimeWait, void (*Function)(), unsigned long (*GetCurrentTime)(), struct Task *task)
{
    // task->Priority = 0;
    task->TimeWait = TimeWait;
    task->Function = Function;
    task->GetCurrentTime = GetCurrentTime;
    task->init();
    Scheduler::AddTask(task);
}

bool Task::IsReady()
{
    if(Task::GetCurrentTime() - Task::LastTime >= Task::TimeWait) return true;
    else return false;
}