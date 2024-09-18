// quick.cpp

#include "volsort.h"

#include <cstdlib>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    // run recursive sort
    l.head = qsort(l.head, numeric);

}

Node *qsort(Node *head, bool numeric) {
    // base case
    if (head == nullptr || head->next == nullptr) return head;

    // save pivot and move head to next value
    Node *left = nullptr, *right = nullptr;
    Node *pivot = head;     // pivot is first Node in list
    head = head->next; 

    partition(head, pivot, left, right, numeric);

    // recursively sort left and right
    left = qsort(left, numeric);
    right = qsort(right, numeric);

    // start right with pivot
    pivot->next = right;

    return concatenate(left, pivot);
}

// splits list given with head into two lists about pivot
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {

    // select comparison func
    bool (*comp)(const Node *, const Node *) = numeric ? node_number_compare : node_string_compare;
    
    Node * curLeft = nullptr, * curRight = nullptr;
    Node * current = head;  // for traversals

    while (current != nullptr) {

        if (comp(current, pivot)) { // add to left list
            if (left == nullptr) {      // initialize left if not already done
                left = current;
                curLeft = left;
            } else {                    
                curLeft->next = current;
                curLeft = curLeft->next;
            }
        } 
        
        else {                      // add to right list
            if (right == nullptr) {     // initialize right if not already done
                right = current;
                curRight = right;
            } else {
                curRight->next = current;
                curRight = curRight->next;
            }
        }

        // move to next Node
        current = current->next;

    }

    // ensure that final node points to null
    if (curLeft != nullptr) curLeft->next = nullptr;
    if (curRight != nullptr) curRight->next = nullptr;

}

// combines two lists and returns new head
Node *concatenate(Node *left, Node *right) {

    // if left list is empty, ignore it
    if (left == nullptr) return right;  

    // find end of left list
    Node * current = left;
    while (current->next != nullptr) {
        current = current->next;
    }

    // add right list to left
    current->next = right;

    return left;

}
