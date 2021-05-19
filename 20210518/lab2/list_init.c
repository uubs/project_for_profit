#include "list_init.h"
#include "list_queue.h"
#include "list_direct_linked_linear_list.h"

////////////////////////////////////////////////////////
///////////Confirue variable set by Init////////////////
///////////////////////////////////////////////////////
static int _n; // size of list (1)

static KeyType _key_type; // (2)
static unsigned _key_size; // used by STRING key type  (2)

static InputMode _input_mode; // specify the input data source (3)

static ListType _list_type; // specify the type of list (4)


////////////////////////////////////////////////////////
///////////Get Confirue variable////////////////////////
///////////////////////////////////////////////////////

int GetSizeOfList() {
    return _n;
}

unsigned GetKeySize() {
    return _key_size;
}

InputMode GetInputMode() {
    return _input_mode;
}

ListType GetListType() {
    return _list_type;
}

KeyType GetKeyType() {
    return _key_type; 
} 

int GetN() {
    return _n;
}
#include <stdio.h>
#include <stdlib.h>
void* Init(int n, KeyType key_type, unsigned key_size, InputMode input_mode, ListType list_type) {
    _n            = n;
    _key_type     = key_type;
    _key_size     = key_size;
    _input_mode   = input_mode;
    _list_type    = list_type;

    // initial list structure: 
    // (1) add a head node,  
    // (2) give value to key_type
    switch(_list_type) {
        case QUEUE: 
            return QueueInit();
            break;
        case STACK: 
            break;
        case DECK: 
            break;
        case DIRECT_LINKED_LINEAR_LIST: 
            return DirectLinkedLinearList_Init();
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
    return NULL;
}




