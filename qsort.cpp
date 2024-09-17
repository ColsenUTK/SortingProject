// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>
#include <vector>

// reference for comparisons from https://www.geeksforgeeks.org/c-qsort-vs-c-sort/
int node_number_compare(const void *a, const void *b);
int node_string_compare(const void *a, const void *b);

void qsort_sort(List &l, bool numeric) {
    int size = l.size;
    Node * current = l.head;
    Node * arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = current;
        current = current->next;
    }

    // this is not copied. I was interested in funtion pointers, so I learned the syntax with help from Geeks4Geeks.
    // https://www.geeksforgeeks.org/function-pointer-in-cpp/ 
    int (*comp)(const Node *a, const Node *b) = numeric ? node_number_compare : node_string_compare;

    // std::sort(arr.begin(), arr.end(), comp);
    qsort(arr, l.size, sizeof(Node), comp);

    for (size_t i = 0; i < arr.size() - 1; i++) {
        arr[i]->next = arr[i+1];
    }

    arr[arr.size() - 1]->next = nullptr;

    l.head = arr[0];

    // qsort(arr, N, sizeof(int), compare);
}

int node_number_compare(const void *a, const void *b) {
    //
}
int node_string_compare(const void *a, const void *b) {
    //
}
