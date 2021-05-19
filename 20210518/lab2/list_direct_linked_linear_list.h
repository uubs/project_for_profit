#ifndef _H_LIST_DIRECT_LINKED_LINEAR_LIST_H
#define _H_LIST_DIRECT_LINKED_LINEAR_LIST_H

#include "list_init.h"
typedef struct directlinkedlinearlist{
     Key key;
     KeyType key_type;

     struct directlinkedlinearlist* next;

     // used only for head pointer
     unsigned _key_size; // used for key_type=string
     struct directlinkedlinearlist* end;
 }DirectLinkedLinearList;

 DirectLinkedLinearList* DirectLinkedLinearList_Init(); 
 void DirectLinkedLinearList_InputKey(DirectLinkedLinearList* head);

 void DirectLinkedLinearList_PushFront(DirectLinkedLinearList* head);
 void DirectLinkedLinearList_PopFront(DirectLinkedLinearList* head);

 void DirectLinkedLinearList_PushBack(DirectLinkedLinearList* head);
 void DirectLinkedLinearList_PopBack(DirectLinkedLinearList* head);

 void DirectLinkedLinearList_Insert(DirectLinkedLinearList* head, DirectLinkedLinearList* p); // insert before p





#endif
