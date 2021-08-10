#include "scheduler.h"
#include "task.h"

struct Task *Scheduler::TasksList[TASKS_NUMBER];

unsigned char Scheduler::TasksCount = 0;

unsigned char Scheduler::count = 0;

bool Scheduler::AddTask(struct Task *task)
{
    if(Scheduler::TasksCount + sizeof(struct Task) > TASKS_NUMBER * sizeof(struct Task)) return false;
    else
    {
        Scheduler::TasksList[Scheduler::TasksCount] = task;
        Scheduler::TasksCount += sizeof(struct Task);
        return true;
    }
}

void Scheduler::run()
{
    for(Scheduler::count = 0; Scheduler::count < Scheduler::TasksCount; Scheduler::count = Scheduler::count + sizeof(struct Task))
    {
        if(Scheduler::TasksList[Scheduler::count]->IsReady())
        {
            Scheduler::TasksList[Scheduler::count]->run();
            // Scheduler::TasksList[Scheduler::count]->LastTime = Scheduler::TasksList[Scheduler::count]->GetCurrentTime();
            Scheduler::TasksList[Scheduler::count]->LastTime += Scheduler::TasksList[Scheduler::count]->TimeWait;
        }else;
    }

}