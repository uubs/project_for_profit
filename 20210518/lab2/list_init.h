#ifndef _H_LIST_H_
#define _H_LIST_H_
#include <stdio.h>

typedef enum {INT, DOUBLE, STRING} KeyType; // types of keys
typedef enum {RANDOM_NUMBERS, GENERATE_FROM_FORMULA, FROM_FILE, FROM_KEYBOARD} InputMode; // the input data source
typedef enum {
    QUEUE, 
    STACK, 
    DECK, 
    DIRECT_LINKED_LINEAR_LIST, 
    INVERTED_SINGLE_LINKED_LINEAR_LIST, 
    DOUBLE_LINKED_LINEAR_LIST,
    SINGLE_LINKED_RING_LIST,
    DOUBLE_LINKED_RING_LIST
} ListType;

//////////////////////////////
////// list Family ///////////
/////////////////////////////
// list have head node
typedef union {
    int key_int;
    double key_double;
    char* key_string;
} Key;

typedef struct {
    Key key;
    KeyType key_type;

}Stack;

typedef struct {
    Key key;
    KeyType key_type;

}Deck;


typedef struct {

}InvertedSingleLinkedLinearList;

typedef struct {

}DoubleLinkedLinearList;

typedef struct {

}SingleLinkedRingList;

typedef struct {

}DoubleLinkedRingList;

/////////////////////////////////
////// Initilization  ///////////
////////////////////////////////

void* Init(int n, KeyType key_type, unsigned key_size, InputMode input_mode, ListType list_type); 

 void* GetHeadNode();
 // current size of list or  initial size of list
 int GetSizeOfList();
 unsigned GetKeySize();
 InputMode GetInputMode();
 ListType GetListType();
 KeyType GetKeyType();
 int GetN();

#endif

