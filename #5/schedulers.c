#include "schedulers.h"


void add(char *name, int priority, int burst,TaskList *task_list)
{
    Task temp;
    temp.name=name;
    temp.priority=priority;
    temp.burst=burst;
    task_list->task_list[task_list->size_list++]=temp;

}

void FCFS(TaskList *task_list)
{
    int i=0;
    printf("Actual list of task \n");

    for(i=0;i<task_list->size_list;i++)
    {
        printf("%s %d %d \n",task_list->task_list[i].name,task_list->task_list[i].priority,task_list->task_list[i].burst);
    }
    printf("Output for FCFS ALGORITHM\n");
    i=0;
    for(i=0;i<task_list->size_list;i++)
    {
        printf("%s %d %d \n",task_list->task_list[i].name,task_list->task_list[i].priority,task_list->task_list[i].burst);
    }

}

int cmp_sjf (const void * a, const void * b)
{

  Task *orderA = (Task *)a;
  Task *orderB = (Task *)b;

  return ( orderA->burst - orderB->burst );
}
void SJF(TaskList *task_list)
{
    int i=0;
    printf("Actual list of task \n");

    for(i=0;i<task_list->size_list;i++)
    {
        printf("%s %d %d \n",task_list->task_list[i].name,task_list->task_list[i].priority,task_list->task_list[i].burst);
    }

    qsort(task_list->task_list,task_list->size_list,sizeof(Task),cmp_sjf);
    printf("Output for SJF ALGORITHM\n");
    i=0;
    for(i=0;i<task_list->size_list;i++)
    {
        printf("%s %d %d \n",task_list->task_list[i].name,task_list->task_list[i].priority,task_list->task_list[i].burst);
    }

}

int cmp_pr (const void * a, const void * b)
{

  Task *orderA = (Task *)a;
  Task *orderB = (Task *)b;

  return ( orderB->priority - orderA->priority );
}
void PR(TaskList *task_list)
{
    int i=0;
    printf("Actual list of task \n");

    for(i=0;i<task_list->size_list;i++)
    {
        printf("%s %d %d \n",task_list->task_list[i].name,task_list->task_list[i].priority,task_list->task_list[i].burst);
    }

    qsort(task_list->task_list,task_list->size_list,sizeof(Task),cmp_pr);
    printf("Output for PR ALGORITHM\n");
    i=0;
    for(i=0;i<task_list->size_list;i++)
    {
        printf("%s %d %d \n",task_list->task_list[i].name,task_list->task_list[i].priority,task_list->task_list[i].burst);
    }

}

void RR(TaskList *task_list)
{
    int i=0;
    printf("Actual list of task \n");

    for(i=0;i<task_list->size_list;i++)
    {
        printf("%s %d %d \n",task_list->task_list[i].name,task_list->task_list[i].priority,task_list->task_list[i].burst);
    }



}

void PRR(TaskList *task_list)
{


}

void schedule(int mode,TaskList *task_list)
{
    switch(mode)
    {

    case 1:
        FCFS(task_list);
    break;
    case 2:
        SJF(task_list);
    break;

    case 3:
        PR(task_list);
    break;

    case 4:
        RR(task_list);
    break;

    case 5:
        PRR(task_list);
    break;

    }

}



