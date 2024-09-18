// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <vector>

void stl_sort(List &l, bool numeric) {
    int size = l.size;
    Node * current = l.head;
    std::vector<Node *> arr(size);  
    
    // store all nodes in a vector
    for (int i = 0; i < size; i++) {
        arr[i] = current;
        current = current->next;
    }

    // this is not copied. I was interested in funtion pointers, so I learned the syntax with help from Geeks4Geeks.
    // https://www.geeksforgeeks.org/function-pointer-in-cpp/ 
    bool (*comp)(const Node *a, const Node *b) = numeric ? node_number_compare : node_string_compare;

    std::sort(arr.begin(), arr.end(), comp);

    // set each node to link to the one ahead of it in the vector
    for (size_t i = 0; i < arr.size() - 1; i++)
        arr[i]->next = arr[i+1];

    arr[arr.size() - 1]->next = nullptr;

    // set head to new head
    l.head = arr[0];
}

