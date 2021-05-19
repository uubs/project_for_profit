#include "list.h"
#include "list_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue* QueueInit() {
    // initial head node
    Queue* head = (Queue*) malloc (sizeof(Queue));
    head->key_type = GetKeyType();
    switch(head->key_type) {
        case INT:
            head->key.key_int = 0;
            break;
        case DOUBLE:
            head->key.key_double = 0;
            break;
        case STRING:
            head->_key_size = GetKeySize() + 1;
            head->key.key_string = NULL;
            break;
    }
    head->next = NULL;


    head->_queue_size = GetSizeOfList();
    head->_front_p = head; // 
    head->_tail_p = head;

    return head;
}

void QueuePush(Queue* head, void* key) {
    // malloc and initial a node
    Queue* node = (Queue*) malloc (sizeof(Queue));
    node->key_type = head->key_type;
    switch(head->key_type) {
        case INT:
            node->key.key_int = *((int*)key);
            break;
        case DOUBLE:
            node->key.key_double = *((double*)key);
            break;
        case STRING:
            node->key.key_string = (char*) malloc (head->_key_size);
            strncpy(node->key.key_string, (char*)key, head->_key_size);
            break;
    }
    node->next = NULL;

    ++ head->_queue_size;
    head->_tail_p -> next = node; // insert a node
    head->_tail_p = head->_tail_p->next;

    node->_front_p = NULL;
    node->_tail_p = NULL;
}

static void QueueNodeFree(Queue* p) {
    switch(p->key_type) {
        case INT:
        case DOUBLE:
            break;
        case STRING:
            free(p->key.key_string);
            break;
    }
    free(p);
}

void QueuePop(Queue* head) {
    if (QueueEmpty(head)) {
        printf("Queue is empty\n");
        exit(-1);
    }
    Queue* p = head->_front_p->next;
    head->_front_p->next = p->next; // delete node p
    QueueNodeFree(p); // free node p


    -- head->_queue_size;
    if (QueueEmpty(head)) {
        head->_tail_p = NULL;
    }
}

// access front element
Queue* QueueFront(Queue* head) {
    return head->_front_p->next;
}

// access back element
Queue* QueueBack(Queue* head) {
    return head->_tail_p;
}

size_t QueueSize(Queue* head) {
    return head->_queue_size;
}


// free all, including head node
void QueueFree(Queue* head) {
    while (!QueueEmpty(head)) {
        QueuePop(head);
    }
    QueueNodeFree(head);
    head = NULL;
}

int QueueEmpty(Queue* head) {
    if (head->_queue_size == 0) return 1;
    else return 0;
}

void QueuePrint(Queue* head) {

    if (QueueEmpty(head)) return;
    Queue* p = head->_front_p->next;
    switch(head->key_type) {
        case INT:
            while (p != head->_tail_p) {
                printf("%d -> ", p->key.key_int);
                p = p->next;
            }
            printf("%d\n", p->key.key_int);
            break;
        case DOUBLE:
            while (p != head->_tail_p) {
                printf("%f -> ", p->key.key_double);
                p = p->next;
            }
            printf("%f\n", p->key.key_double);
            break;
        case STRING:
            while (p != head->_tail_p) {
                printf("\"%s\" -> ", p->key.key_string);
                p = p->next;
            }
            printf("\"%s\"\n", p->key.key_string);
            break;
    }
}


////////////////////////////////////////////////////
///////////////// Queue Input Key : _queue_size   ////////////////
////////////////////////////////////////////////////
static void QueueInputKeyFromRandomNumbers(Queue* head) {

}

static void QueueInputKeyFromFormula(Queue* head) {

}

static char* FromFile(char* buf, const int idx, FILE* fp) {
    printf("key[idx] : ");
    fscanf(fp, "%255s", buf);
    return buf;
}

static void QueueInputKeyFromFile(Queue* head, char* file_name) {
    FILE* fp = fopen(file_name, "r");
    if (!fp) {
        printf("file open error\n");
        exit(-1);
    }

    char buf[256];
    switch(head->key_type) {
        case INT:
            for(int i = 0; i < head->_queue_size; ++ i) {
                int tmp = atoi(FromFile(buf, i, fp));
                QueuePush(head, &tmp);
            }
            break;
        case DOUBLE:
            for(int i = 0; i < head->_queue_size; ++ i) {
                double tmp = atof(FromFile(buf, i, fp));
                QueuePush(head, &tmp);
            }
            break;
        case STRING:
            for(int i = 0; i < head->_queue_size; ++ i) {
                FromFile(buf, i, fp);
                QueuePush(head, buf);
            }
            break;
    }

    fclose(fp);
}

static char* FromKeyBoard(char* buf, const int idx) {
    printf("key[idx] : ");
    scanf("%255s", buf);
    return buf;
}

static void QueueInputKeyFromKeyBoard(Queue* head) {
    char buf[256];
    switch(head->key_type) {
        case INT:
            for(int i = 0; i < head->_queue_size; ++ i) {
                int tmp = atoi(FromKeyBoard(buf, i));
                QueuePush(head, &tmp);
            }
            break;
        case DOUBLE:
            for(int i = 0; i < head->_queue_size; ++ i) {
                double tmp = atof(FromKeyBoard(buf, i));
                QueuePush(head, &tmp);
            }
            break;
        case STRING:
            for(int i = 0; i < head->_queue_size; ++ i) {
                FromKeyBoard(buf, i);
                QueuePush(head, buf);
            }
            break;
    }

}

void QueueInputKey(Queue* head) {
    if (head->_queue_size == 0) return;
    switch(GetInputMode()) {
        case RANDOM_NUMBERS:
            QueueInputKeyFromRandomNumbers(head);
            break;
        case GENERATE_FROM_FORMULA:
            QueueInputKeyFromFormula(head);
            break;
        case FROM_FILE:
            printf("Key input file : ");
            char file_name[256];
            scanf("%255s", file_name);
            QueueInputKeyFromFile(head, file_name);
            break;
        case FROM_KEYBOARD:
            QueueInputKeyFromKeyBoard(head);
            break;
    }
}

