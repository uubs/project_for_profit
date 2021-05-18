#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void InputKeyFromKeyBoardForDirectLinkedLinearList() {
    int cnt = GetN();

    DirectLinkedLinearList* head = GetHeadNode();
    DirectLinkedLinearList* p_pre = head;
    DirectLinkedLinearList* p = NULL;

    for (int i = 0; i < cnt; ++ i) {
        // malloc
        p = (DirectLinkedLinearList*) malloc(sizeof(DirectLinkedLinearList));
        p->key_type = GetKeyType();
        if (GetListType()) p->key.key_string = NULL;

        printf("input [%d] key : ", i + i);
        
        char fmt[25] = "%";
        char string[25];
        switch (GetKeyType()) {
            case INT:
                scanf("%d", &p->key.key_int);
                break;
            case DOUBLE:
                scanf("%lf", &p->key.key_double);
                break;
            case STRING:
                // generate "%ns"
                itoa(GetKeySize(), string, 10);
                strcat(fmt, string);       
                strcat(fmt, "s");

                scanf(fmt, &p->key.key_string);
                break;
        }

        p_pre->next = p;
        p_pre = p;
        printf("\n");
    }
}

static void InputKeyFromKeyBoard() {
    switch (GetListType()) {
         case QUEUE:
             break;
         case STACK:
             break;
         case DECK:
             break;
         case DIRECT_LINKED_LINEAR_LIST:
            InputKeyFromKeyBoardForDirectLinkedLinearList();
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

// the the key from different source
void InputKey() {
    switch(GetInputMode()) {
        case RANDOM_NUMBERS: 
            break;
        case GENERATE_FROM_FORMULA: 
            break;
        case FROM_FILE: 
            break;
        case FROM_KEYBOARD:
            InputKeyFromKeyBoard();
            break;
    }
}
