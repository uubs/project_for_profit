#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SortGeneral(head, p, p_pre, pos_p, pos_p_pre) do {\\
    while (p) { \\
        int flag = 1; \\
        while (pos_p != p && flag) {\\
            switch(GetKeyType()) {\\
                case INT: \\\\
                    if (p->key.key_int >= pos_p->key.key_int) {\\
                        pos_p_pre = pos_p;\\
                        pos_p = pos_p->next;\\
                    } else {\\
                        flag = 0;\\
                    }\\
                    break;\\
                case DOUBLE:\\
                    if (p->key.key_double >= pos_p->key.key_double) {\\
                        pos_p_pre = pos_p;\\
                        pos_p = pos_p->next;\\
                    } else {\\
                        flag = 0;\\
                    }\\
                    break;\\
                case STRING:\\
                    if (strcmp(p->key.key_string , pos_p->key.key_string) > 0) {\\
                        pos_p_pre = pos_p;\\
                        pos_p = pos_p->next;\\
                    } else {\\
                        flag = 0;\\
                    }\\
            }\\
        }\\
        if (pos_p != p)  {  \\
            p_pre->next = p->next; \\
            p->next = pos_p;\\
            pos_p_pre->next = p; \\
            p = p_pre->next; \\
        } else {\\
            p_pre = p;\\
            p = p->next;\\
        }\\
        pos_p = head->next;\\
        pos_p_pre = head; \\
    } \\
} while(0)

// sort for DirectLinkedLinearList
// sort from small to large
static void SortDirectLinkedLinearList(DirectLinkedLinearList* head) {

    DirectLinkedLinearList* p = head->next, *first_node = p, *pos_p = p; 
    DirectLinkedLinearList* p_pre = head, *pos_p_pre = head;

    while (p) { // for the node not null
        int flag = 1;
        while (pos_p != p && flag) {// find the node to insert before: first insert after, then swap the key of two node
            switch(GetKeyType()) {
                case INT:
                    if (p->key.key_int >= pos_p->key.key_int) {
                        pos_p_pre = pos_p;
                        pos_p = pos_p->next;
                    } else {
                        flag = 0;
                    }
                    break;
                case DOUBLE:
                    if (p->key.key_double >= pos_p->key.key_double) {
                        pos_p_pre = pos_p;
                        pos_p = pos_p->next;
                    } else {
                        flag = 0;
                    }
                    break;
                case STRING:
                    if (strcmp(p->key.key_string , pos_p->key.key_string) > 0) {
                        pos_p_pre = pos_p;
                        pos_p = pos_p->next;
                    } else {
                        flag = 0;
                    }
            }
        }
        if (pos_p != p)  { // insert before 
            p_pre->next = p->next; // delete node p
            p->next = pos_p;
            pos_p_pre->next = p; 
            p = p_pre->next; // p_pre do not change
        } else {
            p_pre = p;
            p = p->next;
        }
        pos_p = first_node;
        pos_p_pre = head;
    }
}

void Sort() {
    switch (GetListType()) {
        case QUEUE: 
            break;
        case STACK: 
            break;
        case DECK: 
            break;
        case DIRECT_LINKED_LINEAR_LIST: 
            SortDirectLinkedLinearList((DirectLinkedLinearList* )GetHeadNode());
            break;
        case INVERTED_SINGLE_LINKED_LINEAR_LIST: 
            break;
        case DOUBLE_LINKED_LINEAR_LIST:
            break;
        case SINGLE_LINKED_RING_LIST:
            break;
        case DOUBLE_LINKED_RING_LIST:
            break;
        default:
            printf("intilize list error\n");
            exit(-1);
    }
}
