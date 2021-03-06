/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include <stdio.h>

#include "task.h"

// run this task for the specified time slice
void run(Task *task, int slice) {
    printf("Running task = id:[%d] name:[%s] priority:[%d]  for %d units.\n",task->tid,task->name, task->priority, slice);
}
