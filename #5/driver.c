/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#include "details.h"

#define SIZE    100
#define FCFS 1
#define SJF 2
#define PR 3
#define RR 4
#define PRR 5


int main(int argc, char *argv[])
{
    // init tasks ids
    task_id=0;
    FILE *in;
    char *temp;
    char task[SIZE];
    Node *task_queue=NULL;
    char *name;
    int priority;
    int burst;
    char des[255]="schedule.txt";
    in = fopen(des,"r");

    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        add(name,priority,burst,&task_queue);
        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    schedule(PRR,&task_queue);
    traverse(task_queue);


    return 0;
}
