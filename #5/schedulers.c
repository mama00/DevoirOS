#include "schedulers.h"


void add(char *name, int priority, int burst,Node **queue_head)
{
    Task * task=malloc(sizeof(Task));
    task->burst=burst;
    task->name=name;
    task->priority=priority;
    __sync_add_and_fetch(&task_id,1);
    task->tid=task_id;
    task->reponse_time=0;
    task->turnaround_time=burst;
    task->waiting_time=0;
    task->already_executed=0;
    insert(queue_head,task);

}

Job *PRR(Node **head_queue,Node *last_task_node)
{

    int quantum_time=20;
    Job *job = malloc(sizeof(Job));
    if(last_task_node==NULL)
    {
        if((*head_queue)->task->priority==(*head_queue)->next->task->priority)
        {
            job->task_node=(*head_queue);
            if((*head_queue)->task->burst<=quantum_time){
                job->time=(*head_queue)->task->burst;
                delete(head_queue,(*head_queue)->task);
            }
            else{
                job->time=quantum_time;
                (*head_queue)->task->burst-=quantum_time;
            }
        }
        else
        {
            job->task_node=(*head_queue);
            job->time=(*head_queue)->task->burst;
            delete(head_queue,(*head_queue)->task);
        }
    }
    else
    {
        if(last_task_node->next->next==NULL)
        {
            if(last_task_node->next->task->priority==(*head_queue)->task->priority)
            {
                job->task_node=last_task_node->next;
                if(last_task_node->next->task->burst<=quantum_time){
                    job->time=last_task_node->next->task->burst;
                    delete(head_queue,last_task_node->next->task);
                }
                else{
                    job->time=quantum_time;
                    last_task_node->next->task->burst-=quantum_time;
                }
            }
            else
            {
                job->task_node=last_task_node->next;
                job->time=last_task_node->next->task->burst;
                delete(head_queue,last_task_node->next->task);

            }
        }
        else
        {
            if(last_task_node->next->task->priority==last_task_node->next->next->task->priority)
            {
                job->task_node=last_task_node->next;
                if(last_task_node->next->task->burst<=quantum_time){
                    job->time=last_task_node->next->task->burst;
                    delete(head_queue,last_task_node->next->task);
                }
                else{
                    job->time=quantum_time;
                    last_task_node->next->task->burst-=quantum_time;
                }
            }
            else
            {
                job->task_node=last_task_node->next;
                job->time=last_task_node->next->task->burst;
                delete(head_queue,last_task_node->next->task);

            }
        }

    }
    return job;
}

int cmp (const void * a, const void * b ) {
    const Node **pa = (const Node**)a;
    const Node **pb = (const Node**)b;
    return (*pa)->task->priority-(*pb)->task->priority;
}
void order_by_priority(Node **head_queue)
{
    Node * tab_node[20]={NULL};
    int i=0;
    while((*head_queue)!=NULL)
    {
        tab_node[i]=(*head_queue);
        i++;
        *head_queue=(*head_queue)->next;
    }
    qsort(tab_node,i,sizeof(Node*),cmp);
    *head_queue=NULL;
    i=0;
    while(tab_node[i]!=NULL)
    {
        insert(head_queue,tab_node[i]->task);
        i++;
    }
}


Job *RR(Node **head_queue,Node *last_task_node)
{
    Job * job=malloc(sizeof(Job));
    int quantum_time=20;
    if(*head_queue==NULL)
        return NULL;
    if(last_task_node!=NULL)
    {
        if(last_task_node->next==NULL)
        {
            job->task_node=*head_queue;
            job->time=quantum_time;
            (*head_queue)->task->burst-=quantum_time;
            if((*head_queue)->task->burst<=0)
            {
                job->time=(*head_queue)->task->burst+20;
                (*head_queue)->task->burst=0;
                delete(head_queue,(*head_queue)->task);

            }
            return job;
        }
        else
        {
            job->task_node=last_task_node->next;
            job->time=quantum_time;
            last_task_node->next->task->burst-=quantum_time;
            if(last_task_node->next->task->burst<=0)
            {
                job->time=last_task_node->next->task->burst+20;
                last_task_node->next->task->burst=0;
                delete(head_queue,last_task_node->next->task);
            }
            return job;
        }

    }
    else
    {
            job->task_node=*head_queue;
            job->time=quantum_time;
            (*head_queue)->task->burst-=quantum_time;
            if((*head_queue)->task->burst<=0)
            {
                job->time=(*head_queue)->task->burst+20;
                (*head_queue)->task->burst=0;
                delete(head_queue,(*head_queue)->task);
            }
            return job;
    }
}


Job *PR(Node **head_queue,Node *last_task_node)
{
    if(*head_queue==NULL)
        return NULL;
    Node *biggest_priority_node=*head_queue;
    Node *temp=(*head_queue)->next;
    while(temp!=NULL)
    {
        if(temp->task->priority>biggest_priority_node->task->priority)
        {
            biggest_priority_node=temp;
        }
        temp=temp->next;
    }
    delete(head_queue,biggest_priority_node->task);
    Job * job=malloc(sizeof(Job));
    job->task_node=biggest_priority_node;
    job->time=biggest_priority_node->task->burst;
    return job ;

}

Job *SJF(Node **head_queue,Node *last_task_node)
{
    if(*head_queue==NULL)
        return NULL;
    Node *shortest_burst_node=*head_queue;
    Node *temp=(*head_queue)->next;
    while(temp!=NULL)
    {
        if(temp->task->burst<shortest_burst_node->task->burst)
        {
            shortest_burst_node=temp;
        }
        temp=temp->next;
    }
    delete(head_queue,shortest_burst_node->task);
    Job * job=malloc(sizeof(Job));
    job->task_node=shortest_burst_node;
    job->time=shortest_burst_node->task->burst;
    return job ;

}

Job *FCFS(Node **head_queue,Node *last_task_node)
{
        if(*head_queue==NULL)
            return NULL;
        Job * job=malloc(sizeof(Job));
        job->task_node=*head_queue;
        job->time=(*head_queue)->task->burst;
        delete(head_queue,(*head_queue)->task);
        return job ;

}

Job *get_next_task(Node ** head_queue,int mode,Node * last_task_node)
{

    switch(mode)
    {

    case 1:
        return FCFS(head_queue,last_task_node);
    case 2:
        return SJF(head_queue,last_task_node);
    case 3:
        return PR(head_queue,last_task_node);
    case 4:
        return RR(head_queue,last_task_node);
    case 5:
        order_by_priority(head_queue);
        return RR(head_queue,last_task_node);
    }
    return NULL;
}

void schedule(int mode,Node **queue_head)
{
    //Copy linked  list to an array////////////////////
    Node * tab_node[100]={NULL};
    Node * temp=*queue_head;
    int i=0;
    while(temp!=NULL)
    {
        tab_node[i]=temp;
        temp=temp->next;
        i++;
    }
    //////////////////////////////////////////
    Node * queue_head_temp = *queue_head;
    Job * currentJobNode=NULL;
    currentJobNode=get_next_task(queue_head,mode,currentJobNode==NULL ? NULL : currentJobNode->task_node);
    if(currentJobNode!=NULL)
    {
        update_response_time_except(currentJobNode->task_node->task,*queue_head,currentJobNode->time);
        update_waiting_time_except(currentJobNode->task_node->task,*queue_head,currentJobNode->time);
        update_executing_time_for(currentJobNode->task_node->task,currentJobNode->time);
    }

    while (currentJobNode!=NULL)
    {
        run(currentJobNode->task_node->task,currentJobNode->time);
        currentJobNode=get_next_task(queue_head,mode,currentJobNode->task_node);
        if(currentJobNode!=NULL)
        {
            update_response_time_except(currentJobNode->task_node->task,*queue_head,currentJobNode->time);
            update_waiting_time_except(currentJobNode->task_node->task,*queue_head,currentJobNode->time);
            update_executing_time_for(currentJobNode->task_node->task,currentJobNode->time);
        }



    }
    print_statistics(tab_node,i);

}



