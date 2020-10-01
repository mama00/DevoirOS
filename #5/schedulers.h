#ifndef SCHEDULERS_H_INCLUDED
#define SCHEDULERS_H_INCLUDED

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10
#include "task.h"
#include "list.h"
#include "cpu.h"
#include "statistics.h"
int task_id;
typedef struct job
{
    Node * task_node;
    int time;
}Job;
// add a task to the list
void add(char *name, int priority, int burst,Node **queue_head);

// invoke the scheduler
void schedule(int ,Node **queue_head);

Job * get_next_task(Node **,int,Node *);

#endif // SCHEDULERS_H_INCLUDED
