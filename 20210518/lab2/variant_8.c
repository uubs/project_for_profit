#include "list_init.h"
#include "list_direct_linked_linear_list.h"

void Variant8() {
    DirectLinkedLinearList* head = (DirectLinkedLinearList*) Init(0, INT, 0, FROM_KEYBOARD, DIRECT_LINKED_LINEAR_LIST);

    int tmp[8] = {1, 5, 2, 3, -1, -5, -2, -3};
    for (int i = 0; i < 8; ++ i) {
        DirectLinkedLinearList_PushBack(head, &tmp[i]);
    }

    DirectLinkedLinearList_Print(head);
    DirectLinkedLinearList_Sort(head, ABS);
    DirectLinkedLinearList_Print(head);
}

int main() {
    Variant8();
}
