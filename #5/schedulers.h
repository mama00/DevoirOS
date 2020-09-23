#ifndef SCHEDULERS_H_INCLUDED
#define SCHEDULERS_H_INCLUDED

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10
#include "task.h"
// add a task to the list
void add(char *name, int priority, int burst,TaskList *task_list);

// invoke the scheduler
void schedule(int ,TaskList *);


#endif // SCHEDULERS_H_INCLUDED
