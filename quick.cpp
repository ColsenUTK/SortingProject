// quick.cpp

#include "volsort.h"

#include <cstdlib>
#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {

    l.head = qsort(l.head, numeric);

}

Node *qsort(Node *head, bool numeric) {
    if (head == nullptr || head->next == nullptr) return head;

    Node *left = nullptr, *right = nullptr;
    Node *pivot = head;
    head = head->next; 

    partition(head, pivot, left, right, numeric);

    left = qsort(left, numeric);
    right = qsort(right, numeric);

    pivot->next = right;

    return concatenate(left, pivot);
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {

    bool (*comp)(const Node *, const Node *) = numeric ? node_number_compare : node_string_compare;
    
    Node * curLeft = nullptr, * curRight = nullptr;
    Node * current = head;

    while (current != nullptr) {

        Node * next = current->next;
        current->next = nullptr;

        if (comp(current, pivot)) {     // left
            if (left == nullptr) {
                left = current;
                curLeft = left;
            } else {
                curLeft->next = current;
                curLeft = curLeft->next;
            }
        } 
        
        else {                        // right
            if (right == nullptr) {
                right = current;
                curRight = right;
            } else {
                curRight->next = current;
                curRight = curRight->next;
            }
        }

        current = next;

    }

    if (curLeft != nullptr) curLeft->next = nullptr;
    if (curRight != nullptr) curRight->next = nullptr;

}

Node *concatenate(Node *left, Node *right) {
    if (left == nullptr) return right;

    Node * current = left;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = right;

    return left;
}
