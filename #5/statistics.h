#ifndef STATISTICS_H_INCLUDED
#define STATISTICS_H_INCLUDED
#include "schedulers.h"
void update_response_time_except(Task *task,Node * head,int time);
void print_statistics(Node **,int size);

void update_waiting_time_except(Task *task,Node * head,int time);
void update_executing_time_for(Task *,int time);

#endif // STATISTICS_H_INCLUDED

