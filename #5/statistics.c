#include "statistics.h"

void print_statistics(Node ** tab,int size)
{
    int nb=0;
    float sum_response=0;
    float sum_waiting=0;
    float sum_turnaround=0;
    int i=0;
    for(i=0;i<size;i++)
    {
        nb++;
        sum_response+=tab[i]->task->reponse_time;
        sum_waiting+=tab[i]->task->waiting_time;
        sum_turnaround+=tab[i]->task->turnaround_time;
        //printf("\n %d %d \n",tab[i]->task->tid,tab[i]->task->waiting_time);
        //printf("\n %d %d \n",tab[i]->task->tid,tab[i]->task->reponse_time);
    }
    printf("\nAverage Response Time : %.6f \n",sum_response/nb);
    printf("\nAverage Waiting Time : %.6f \n",sum_waiting/nb);
    printf("\nAverage Turnaournd Time : %.6f \n",sum_turnaround/nb);



}
void update_response_time_except(Task *task,Node * head,int time)
{
    Node * temp = head;
    task->already_executed=1;
    while((temp)!=NULL)
    {
        if((temp)->task->tid != task->tid && (temp)->task->already_executed==0)
        {
            (temp)->task->reponse_time+=time;
        }
        temp=(temp)->next;
    }
}
void update_waiting_time_except(Task *task,Node * head,int time)
{
    Node * temp = head;
    while((temp)!=NULL)
    {
        if((temp)->task->tid != task->tid )
        {
            (temp)->task->waiting_time+=time;
            (temp)->task->turnaround_time+=time;
        }
        temp=(temp)->next;
    }
}

void update_executing_time_for(Task * task,int time)
{
    task->turnaround_time+=time;
}

