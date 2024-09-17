// merge.cpp

#include "volsort.h"



Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);



// helper for msort
void merge_sort(List &l, bool numeric) {

    l.head = msort(l.head, numeric);

}

// recursive sorting function
Node *msort(Node *head, bool numeric) {

    // base case
    if (head->next == nullptr) return head;

    // split list in half
    Node *left_head, *right_head;
    split(head, left_head, right_head);

    // recursively sort left and right
    left_head = msort(left_head, numeric);
    right_head = msort(right_head, numeric);

    // recombine
    return merge(left_head, right_head, numeric);

}

// splits a given list (head) in half, then stores the new heads in left and right
void split(Node *head, Node *&left, Node *&right) {

    // edge case for size 0 or 1 list
    if (head == nullptr || head->next == nullptr) {
        left = head;
        right = nullptr;
        return;
    }

    Node * slowPointer = head;
    Node * fastPointer = head;

    while (true) {
        
        // increment fast by 2 for every 1 slow increment
        fastPointer = fastPointer->next;
        if (fastPointer == nullptr || fastPointer->next == nullptr)
            break;
        fastPointer = fastPointer->next;
        
        slowPointer = slowPointer->next;

    }

    left = head;
    right = slowPointer->next;  // right list starts just right of midpoint
    slowPointer->next = nullptr;

}

// merges two given lists into a new list and returns its head
Node *merge(Node *left, Node *right, bool numeric) {

    // chooses a comparison function for numeric or string
    bool (*comp)(const Node *a, const Node *b) = numeric ? node_number_compare : node_string_compare;

    Node * head;    // head of the new list

    // initialize head as the smaller of the two starting nums
    if (comp(left, right)) {
        head = left;
        left = left->next;  // increment left
    } else {
        head = right;
        right = right->next;    // increment right
    }

    Node * currentNode = head;      // use currentNode to build the list

    // loops until one list is empty
    while (left != nullptr && right != nullptr) {

        if (comp(left, right)) {    // if left num is smaller than right num
            currentNode->next = left;       // add left to list
            left = left->next;
            currentNode = currentNode->next;
        } else {    // if right num is smaller than left num
            currentNode->next = right;      // add right to list
            right = right->next;
            currentNode = currentNode->next;
        }

    }

    // add remaining (non-null) list to main list
    if (left != nullptr)
        currentNode->next = left;
    else if (right != nullptr)
        currentNode->next = right;

    return head;

}
