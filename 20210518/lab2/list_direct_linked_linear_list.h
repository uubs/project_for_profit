#ifndef _H_LIST_DIRECT_LINKED_LINEAR_LIST_H
#define _H_LIST_DIRECT_LINKED_LINEAR_LIST_H

#include "list_init.h"
typedef struct directlinkedlinearlist{
     Key key;
     KeyType key_type;

     struct directlinkedlinearlist* next;

     // used only for head pointer
     unsigned _key_size; // used for key_type=string
     int _list_size; 
     struct directlinkedlinearlist* end;
}DirectLinkedLinearList;

typedef enum {
    INSERT,
    BOUBLE,
    ABS // first turn value to abs, then compare it
}SortMode;

//////////////////////////////////////////////////////////////////////
/////////   (1) DirectLinkedLinearList* head = (DirectLinkedLinearList*)Init() { include DirectLinkedLinearList_Init() } ///////
/////////   (2) DirectLinkedLinearList_InputKey(head)  //////////////////////////////////////
/////////   (3) do something    //////////////////////////////////////
/////////   (4) DirectLinkedLinearList_Free(head)    //////////////////////////////////////
/////////////////////////////////////////////////////////////////////


DirectLinkedLinearList* DirectLinkedLinearList_Init(); 
void DirectLinkedLinearList_InputKey(DirectLinkedLinearList* head);

// insert element at beginning
void DirectLinkedLinearList_PushFront(DirectLinkedLinearList* head, void* p);
// pop element at beginning and free
void DirectLinkedLinearList_PopFront(DirectLinkedLinearList* head);

// add element at end 
void DirectLinkedLinearList_PushBack(DirectLinkedLinearList* head, void* p);
// pop element at end
void DirectLinkedLinearList_PopBack(DirectLinkedLinearList* head);

// after insert: order is  insert_p p
void DirectLinkedLinearList_Insert(DirectLinkedLinearList* head, DirectLinkedLinearList* insert_p, DirectLinkedLinearList* p); 
// delete element p and free
void DirectLinkedLinearList_Erase(DirectLinkedLinearList* head, DirectLinkedLinearList* p); // delete element and free

int DirectLinkedLinearList_Empty(DirectLinkedLinearList* head);

void DirectLinkedLinearList_Free(DirectLinkedLinearList* head);

void DirectLinkedLinearList_Print(DirectLinkedLinearList* head); 

void DirectLinkedLinearList_Sort(DirectLinkedLinearList* head, SortMode mode);



#endif
