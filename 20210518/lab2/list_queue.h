#ifndef _H_LIST_QUEUE_H_
#define _H_LIST_QUEUE_H_

#include "list.h"

typedef struct queue{
    Key key;
    KeyType key_type;
    struct queue* next;

    //////only used by head pointer of queue////////////
    struct queue* _front_p; // always point to head of queue; 
    struct queue* _tail_p; /// always point to end of queue
    unsigned _key_size; // used for key_type=string
    int _queue_size;
}Queue;

//////////////////////////////////////////////////////////////////////
/////////   (1) Queue* head = (Queue*)Init() { include QueueInit() } ///////
/////////   (2) QueueInputKey(head)  //////////////////////////////////////
/////////   (3) do something    //////////////////////////////////////
/////////   (4) QueueFree(head)    //////////////////////////////////////
/////////////////////////////////////////////////////////////////////
Queue* QueueInit();
void QueueInputKey(Queue* head);

void QueuePush(Queue* head, void* key);
void QueuePop(Queue* head);
Queue* QueueFront(Queue* head); // access front element
Queue* QueueBack(Queue* head); // access back element
size_t QueueSize(Queue* head);
int QueueEmpty(Queue* head);
void QueuePrint(Queue* head);
void QueueFree(Queue* head);

#endif


