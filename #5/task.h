#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

/**
 * Representation of a task in the system.
 */

#ifndef TASK_H
#define TASK_H
#include <stdio.h>
#include <stdlib.h>
// representation of a task
typedef struct task {
    char *name;
    int tid;
    int priority;
    int burst;
} Task;

typedef struct TaskList {
    Task task_list[100];
    int size_list;
}TaskList;

#endif


#endif // TASK_H_INCLUDED
