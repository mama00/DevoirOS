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
    FILE *in;
    char *temp;
    char task[SIZE];

    TaskList tab_list;
    tab_list.size_list=0;


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
        add(name,priority,burst,&tab_list);
        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    schedule(PR,&tab_list);



    return 0;
}
