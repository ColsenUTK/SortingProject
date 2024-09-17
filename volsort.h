// volsort.h

#ifndef VOLSORT_H
#define VOLSORT_H

#include <cstddef>
#include <string>
#include <iostream>

struct Node {
    std::string string;
    int         number;
    Node       *next;
};

struct List {
    Node       *head;
    size_t      size;

    List(); 					// define in list.cpp
    ~List();					// define in list.cpp

    void push_front(const std::string &s) {
        Node *newNode = new Node;
        newNode->string = s;
        newNode->number = stoi(s);
        newNode->next = head;

        head = newNode;

        size++;
    }	//define below

    void dump_node(Node *n) {
        while (n != nullptr) {
            std::cout << "String:  " << n->string << ",  Num:  " << n->number << '\n';
            n = n->next;
        }
    }
};


// Functions -------------------------------------------------------------------

bool node_number_compare(const Node *a, const Node *b); 	//implement in list.cpp to avoid compile-time issues, used by quick, merge and stl
bool node_string_compare(const Node *a, const Node *b);		//implement in list.cpp to avoid compile-time issues, merge and stl

// void dump_node(Node *n);					// implement in this file (volsort.h) to make it easier for TAs to grade

void stl_sort(List &l, bool numeric);	// define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric);	// define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric);	// define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric);	// define in quick.cpp - your implementation


#endif
