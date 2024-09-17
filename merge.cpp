// merge.cpp

#include "volsort.h"

#include <cstddef>
#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

// helper for msort
void merge_sort(List &l, bool numeric) {

    l.head = msort(l.head, numeric);

}

// needs to be recursive
Node *msort(Node *head, bool numeric) {

    if (head->next == nullptr) return head;

    Node *left_head, *right_head;
    split(head, left_head, right_head);

    left_head = msort(left_head, numeric);
    right_head = msort(right_head, numeric);

    return merge(left_head, right_head, numeric);

}

void split(Node *head, Node *&left, Node *&right) {

    if (head == nullptr || head->next == nullptr) {
        left = head;
        right = nullptr;
        return;
    }

    Node * current_left = head;
    Node * current_right = head;

    while (true) {
        
        current_right = current_right->next;
        if (current_right == nullptr || current_right->next == nullptr)
            break;
        current_right = current_right->next;
        
        current_left = current_left->next;

    }

    left = head;
    right = current_left->next;
    current_left->next = nullptr;

}

Node *merge(Node *left, Node *right, bool numeric) {

    bool (*comp)(const Node *a, const Node *b) = numeric ? node_number_compare : node_string_compare;

    Node * new_head;

    if (comp(left, right)) {
        new_head = left;
        left = left->next;
    } else {
        new_head = right;
        right = right->next;
    }

    Node * currentNode = new_head;

    while (left != nullptr && right != nullptr) {

        if (comp(left, right)) {
            currentNode->next = left;
            left = left->next;
            currentNode = currentNode->next;
        } else {
            currentNode->next = right;
            right = right->next;
            currentNode = currentNode->next;
        }

    }

    if (left != nullptr)
        currentNode->next = left;

    else if (right != nullptr)
        currentNode->next = right;

    return new_head;

}
