#include "LinkedList.h"

int main() {
    LinkedList list;
    list.insertbeg(10);
    list.insertend(20);
    list.insertposition(15, 2);
    list.display();             
    list.deleteposition(2);
    list.display();             
    list.deletebeg();
    list.deleteend();
    list.display();             
    return 0;
}
