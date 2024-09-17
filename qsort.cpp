// qsort.cpp

#include "volsort.h"
#include <cstdlib>

// reference for comparisons from https://www.geeksforgeeks.org/c-qsort-vs-c-sort/
int node_number_compare_void(const void *a, const void *b);
int node_string_compare_void(const void *a, const void *b);

void qsort_sort(List &l, bool numeric) {
    int size = l.size;
    Node * current = l.head;
    Node * arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = current;
        current = current->next;
    }

    // reference to https://www.geeksforgeeks.org/function-pointer-in-cpp/ 
    int (*comp)(const void *a, const void *b) = numeric ? node_number_compare_void : node_string_compare_void;

    qsort(arr, size, sizeof(Node*), comp);

    for (int i = 0; i < size - 1; i++) {
        arr[i]->next = arr[i+1];
    }

    arr[size - 1]->next = nullptr;

    l.head = arr[0];

}

// reference for these comparator funcs from https://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/
int node_number_compare_void(const void *a, const void *b) {
    int numA = (*(Node**)a)->number;
    int numB = (*(Node**)b)->number;
    return numA-numB;
}

int node_string_compare_void(const void *a, const void *b) {
    std::string numA = (*(Node**)a)->string;
    std::string numB = (*(Node**)b)->string;
    return stoi(numA)-stoi(numB);
}
