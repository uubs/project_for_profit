#include "list_queue.h"
#include "list_init.h"

void Varint4() {
    // initial a queue
    Queue* head_1 = (Queue*)Init(0, STRING, 1, FROM_KEYBOARD, QUEUE);
    Queue* head_2 = (Queue*)Init(0, STRING, 1, FROM_KEYBOARD, QUEUE);

    QueuePush(head_1, "a");
    QueuePush(head_1, "b");
    QueuePush(head_1, "c");

    int first = 1;
    while(!QueueEmpty(head_1)) {
        Queue* p  = QueueFront(head_1);
        head_1->next = p->next; // remove node p, not free
        head_1->_queue_size --;
        if (first) {
            head_2->_tail_p = p;
            first = 0;
        }
        p->next = head_2->_front_p->next;
        head_2->_front_p->next = p;
        head_2->_queue_size ++;
    }

    QueuePrint(head_1);
    QueuePrint(head_2);
    QueueFree(head_1);
    QueueFree(head_2);
}

int main() {
    Varint4();
}


