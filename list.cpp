#include "volsort.h"
#include <cstddef>


List::List() {
    head = nullptr;
    size = 0;
}

// traverses the whole list, deleting nodes as it goes
List::~List() {
    Node * next;
    Node * current = head;

    for (size_t i = 0; i < size; i++) {
        next = current->next;
        delete current;
        current = next;
    }
}

// compare numerically
bool node_number_compare(const Node *a, const Node *b) {

    return a->number < b->number;

}

// compare a string lexigraphically
bool node_string_compare(const Node *a, const Node *b) {

    return a->string < b->string;

}
