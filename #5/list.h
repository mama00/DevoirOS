#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

/**
 * list data structure containing the tasks in the system
 */

#include "task.h"

struct node {
    Task *task;
    struct node *next;
};
typedef struct node Node;

// insert and delete operations.
void insert(struct node **head, Task *task);
void delete(struct node **head, Task *task);
void traverse(struct node *head);

#endif // LIST_H_INCLUDED
