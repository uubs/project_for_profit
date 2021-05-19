#include "list_direct_linked_linear_list.h"
#include "list_init.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

DirectLinkedLinearList* DirectLinkedLinearList_Init() {
    DirectLinkedLinearList* head = (DirectLinkedLinearList* ) malloc (sizeof(DirectLinkedLinearList));
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

    head->_list_size = GetSizeOfList();
    head->end = head;
    return head;
}

// insert element at beginning
void DirectLinkedLinearList_PushFront(DirectLinkedLinearList* head, void* key) {
    DirectLinkedLinearList* p = (DirectLinkedLinearList*) malloc (sizeof(DirectLinkedLinearList));
    // malloc p
    
    switch(head->key_type) {
        case INT:
            head->key.key_int = *((int*)key);
            break;
        case DOUBLE:
            head->key.key_double = *((double*)key);
            break;
        case STRING:
            head->key.key_string = (char*) malloc (head->_key_size);
            strncpy(p->key.key_string, (char*)key, head->_key_size);
            break;
    }

    if (head->next == NULL) {
        head->next = p;
        p->next = NULL;
        head->end = p;
        return;
    }
    DirectLinkedLinearList_Insert(head, p, head->next);
}

// pop element at beginning and free it
void DirectLinkedLinearList_PopFront(DirectLinkedLinearList* head) {
    if (DirectLinkedLinearList_Empty(head)) {
        printf("list is empty");
        exit(-1);
    }

    DirectLinkedLinearList_Erase(head, head->next);
}

 // add element at end
void DirectLinkedLinearList_PushBack(DirectLinkedLinearList* head, void* key) {
    DirectLinkedLinearList* p = (DirectLinkedLinearList*) malloc (sizeof(DirectLinkedLinearList));
    // malloc p
    
    switch(head->key_type) {
        case INT:
            p->key.key_int = *((int*)key);
            break;
        case DOUBLE:
            p->key.key_double = *((double*)key);
            break;
        case STRING:
            p->key.key_string = (char*) malloc (head->_key_size);
            strncpy(p->key.key_string, (char*)key, head->_key_size);
            break;
    }
    head->end->next = p;
    p->next = NULL;
    head->end = p;
    ++ head->_list_size;
}

 // pop element at end
void DirectLinkedLinearList_PopBack(DirectLinkedLinearList* head) {
    if (DirectLinkedLinearList_Empty(head)) {
        printf("list is empty");
        exit(-1);
    }

    DirectLinkedLinearList_Erase(head, head->end);
}


// after insert: order is  insert_p p
void DirectLinkedLinearList_Insert(DirectLinkedLinearList* head, DirectLinkedLinearList* insert_p,DirectLinkedLinearList* p) {
    if (p == NULL) {
        printf("insert error 1");
        exit(-1);
    }
    // find p_pre
    DirectLinkedLinearList* p_pre = head;
    while (p_pre->next != p) {
        p_pre = p_pre->next;
        if (p_pre == NULL) {
            printf("insert error 2");
            exit(-1);
        }
    }

    p_pre->next = insert_p;
    ++ head->_list_size;
} 

// delete element p and free
void DirectLinkedLinearList_Erase(DirectLinkedLinearList* head, DirectLinkedLinearList* p)  {
    // find p_pre
    DirectLinkedLinearList* p_pre = head;
    while (p_pre->next != p) {
        p_pre = p_pre->next;
        if (p_pre == NULL) {
            printf("p is not in list");
            exit(-1);
        }
    }

    // erase the end ele; not the head
    if (p != head && p->next == NULL) head->end = p_pre;
    // free p
    switch(head->key_type) {
        case INT:
            free(p);
            break;
        case DOUBLE:
            free(p);
            break;
        case STRING:
            free(p->key.key_string);
            free(p);
            break;
    }
    p_pre->next = NULL;
    -- head->_list_size;
}

int DirectLinkedLinearList_Empty(DirectLinkedLinearList* head) {
    if (head->next == NULL) return 1;
    else return 0;
}


// free all list including head pointer
void DirectLinkedLinearList_Free(DirectLinkedLinearList* head) {
    while (head->next != NULL)
        DirectLinkedLinearList_PopFront(head);
    switch(head->key_type) {
        case INT:
            free(head);
            break;
        case DOUBLE:
            free(head);
            break;
        case STRING:
            free(head->key.key_string);
            free(head);
            break;
    }
}



void DirectLinkedLinearList_Print(DirectLinkedLinearList* head) {
     DirectLinkedLinearList* p = head->next;
     int first = 1;
     while (p) {
         if (first)  first = 0;
         else printf(" -> ");
         switch (GetKeyType()) {
             case INT:
                 printf("%d", p->key.key_int);
                 break;
             case DOUBLE:
                 printf("%lf", p->key.key_double);
                 break;
             case STRING:
                 printf("%s", p->key.key_string);
                 break;
         }
         p = p->next;
     }
     printf("\n");
 }

void DirectLinkedLinearList_Sort(DirectLinkedLinearList* head, SortMode mode) {

    DirectLinkedLinearList* p = head->next, *pos_p = p; 
    DirectLinkedLinearList* p_pre = head, *pos_p_pre = head;

    int first = 1;
    while (p) { // for the node not null
        int flag = 1;
        while (pos_p != p && flag) {// find the node to insert before: first insert after, then swap the key of two node
            switch(GetKeyType()) {
                case INT:
                    if (mode == ABS) {
                        if (abs(p->key.key_int) >= abs(pos_p->key.key_int)) {
                            pos_p_pre = pos_p;
                            pos_p = pos_p->next;
                        } else {
                            flag = 0;
                        }

                    } else {
                        if (p->key.key_int >= pos_p->key.key_int) {
                            pos_p_pre = pos_p;
                            pos_p = pos_p->next;
                        } else {
                            flag = 0;
                        }
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

        if (first) {
            p_pre = p;
            p = p->next;
            first = 0;
            continue;
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
        pos_p = head->next;
        pos_p_pre = head;
    }
}


 ///////////////////////////////////////////////////////////////////////////////////
 ///////////////// DirectLinkedLinearList Input Key : _list_size   ////////////////
 //////////////////////////////////////////////////////////////////////////////////


static void DirectLinkedLinearListFromRandomNumbers(DirectLinkedLinearList* head) {

}
static void DirectLinkedLinearListFromFormula(DirectLinkedLinearList* head) {

}
static void DirectLinkedLinearListFromFile(DirectLinkedLinearList* head, const char* file_name) {

}

static char* FromKeyBoard(char* buf, const int idx) {
    printf("key[idx] : ");
    scanf("%255s", buf);
    return buf;
}

static void DirectLinkedLinearListFromKeyBoard(DirectLinkedLinearList* head) {
     char buf[256];
     switch(head->key_type) {
         case INT:
             for(int i = 0; i < head->_key_size; ++ i) {
                 int tmp = atoi(FromKeyBoard(buf, i));
                 DirectLinkedLinearList_PushBack(head, &tmp);
             }
             break;
         case DOUBLE:
             for(int i = 0; i < head->_key_size; ++ i) {
                 double tmp = atof(FromKeyBoard(buf, i));
                 DirectLinkedLinearList_PushBack(head, &tmp);
             }
             break;
         case STRING:
             for(int i = 0; i < head->_key_size; ++ i) {
                 FromKeyBoard(buf, i);
                 DirectLinkedLinearList_PushBack(head, buf);
             }
             break;
     }

}

void DirectLinkedLinearListInputKey(DirectLinkedLinearList* head) {
    if (head->_list_size == 0) return;
     switch(GetInputMode()) {
         case RANDOM_NUMBERS:
             DirectLinkedLinearListFromRandomNumbers(head);
             break;
         case GENERATE_FROM_FORMULA:
             DirectLinkedLinearListFromFormula(head);
             break;
         case FROM_FILE:
             printf("Key input file : ");
             char file_name[256];
             scanf("%255s", file_name);
             DirectLinkedLinearListFromFile(head, file_name);
             break;
         case FROM_KEYBOARD:
             DirectLinkedLinearListFromKeyBoard(head);
             break;
     }
 }

