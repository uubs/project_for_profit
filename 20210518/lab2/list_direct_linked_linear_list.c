#include "list_direct_linked_linear_list.h"

DirectLinkedLinearList* DirectLinkedLinearListInit() {
                 _head = (DirectLinkedLinearList* ) malloc (sizeof(DirectLinkedLinearList));
             ((DirectLinkedLinearList* )_head)->key_type = _key_type;
             ((DirectLinkedLinearList* )_head)->next = NULL;
             if (_key_type == STRING) ((DirectLinkedLinearList* )_head)->key.key_string = NULL;


}

void DirectLinkedLinearListPrint(DirectLinkedLinearList* head) {
 void Print() {
     DirectLinkedLinearList* head = GetHeadNode();
     DirectLinkedLinearList* p = head->next;
     int cnt = GetSizeOfList();
     for (int i = 0; i < cnt; ++ i) {
         switch (GetKeyType()) {
             case INT:
                 printf("%d ->", p->key.key_int);
                 break;
             case DOUBLE:
                 printf("%lf -> ", p->key.key_double);
                 break;
             case STRING:
                 printf("%s -> ", p->key.key_string);
                 break;
         }
         p = p->next;
     }
     printf("\n");
 }

}

void DirectLinkedLinearListFree(DirectLinkedLinearList* head) {
     #define FreeNode(head) do { \
     void* p = NULL;\
     while (head) {\
         p = head;\
         head = head->next;\
         free(p); \
     }\
 } while(0)

 #define FreeString(head) do {\
     void* p = NULL;\
     while (head) {\
         p = head->key.key_string;\
         head = head->next;\
         free(p);\
     }\
 } while(0)

 void Free() {
     // for DirectLinkedLinearList
     DirectLinkedLinearList* head = GetHeadNode();
     if (GetKeyType() == INT || GetKeyType() == DOUBLE) {
         FreeNode(head);
     } else {
         FreeString(head);
         FreeNode(head);
     }
 }


}

void DirectLinkedLinearListSort(DirectLinkedLinearList* head) {

    DirectLinkedLinearList* p = head->next, *pos_p = p; 
    DirectLinkedLinearList* p_pre = head, *pos_p_pre = head;

    int first = 1;
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


void FromKeyBoardForDirectLinkedLinearList(DirectLinkedLinearList* head) {
     int cnt = head->_key_size;

     DirectLinkedLinearList* p_pre = head;
     DirectLinkedLinearList* p = NULL;

     for (int i = 0; i < cnt; ++ i) {
         // malloc
         p = (DirectLinkedLinearList*) malloc(sizeof(DirectLinkedLinearList));
         p->key_type = GetKeyType();
         if (GetListType()) p->key.key_string = NULL;

         printf("input [%d] key : ", i + 1);

         char fmt[25] = "%";
         char string[25];
         switch (GetKeyType()) { // give a type accroding to the input
             case INT:
                 scanf("%d", &p->key.key_int);
                 break;
             case DOUBLE:
                 scanf("%lf", &p->key.key_double);
                 break;
             case STRING:
                 // generate "%ns"
                 sprintf(string, "%d", GetKeySize());
                 strcat(fmt, string);
                 strcat(fmt, "s");

                 p->key.key_string = (char*) malloc (GetKeySize());
                 scanf(fmt, p->key.key_string);
                 char ch;
                 while ((ch = getchar()) != EOF && ch != '\n'); // clear input buffer
                 break;
         }

         p_pre->next = p;
         p_pre = p;
         printf("\n");
     }
 }

void DirectLinkedLinearListInputKey(DirectLinkedLinearList* head) {
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

