#include "../list.h"

void TestDirectLinkedLinearList() {
    /*
     Init(5, INT, 0, FROM_KEYBOARD, DIRECT_LINKED_LINEAR_LIST); // Input OK
     Sort(); // Sort OK
     Print();
     Free(); // OK
     */

     Init(5, DOUBLE, 0, FROM_KEYBOARD, DIRECT_LINKED_LINEAR_LIST); // INPUT OK
     Sort(); // Sort OK
     Print();
     Free();

     Init(5, STRING, 20, FROM_KEYBOARD, DIRECT_LINKED_LINEAR_LIST); // Input OK
     Sort(); // Sort OK
     Print();
     Free();
}

int main() {
     TestDirectLinkedLinearList();

}
