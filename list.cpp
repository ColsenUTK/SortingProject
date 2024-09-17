#include "volsort.h"
#include <cstddef>


List::List() {
    head = nullptr;
    size = 0;
}

List::~List() {
    Node * next;
    Node * current = head;

    for (int i = 0; i < size; i++) {
        next = current->next;
        delete current;
        current = next;
    }
}

bool node_number_compare(const Node *a, const Node *b) {

    return a->number < b->number;

}

bool node_string_compare(const Node *a, const Node *b) {

    return stoi(a->string) < stoi(b->string);
    
}
