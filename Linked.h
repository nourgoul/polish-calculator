#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"
#include "Iterator.h"
using namespace std;

class Iterator;

class Linked {
public:
    // Default constructor
    Linked();

    // Copy constructor
    Linked(const Linked& source);

    // Destructor
    ~Linked();

    // Copy assignment operator - copies every node into existing list
    Linked& operator=(const Linked& source);

    // Returns whether list is empty
    bool isEmpty() const;

    // Empties all nodes except head and tail
    void makeEmpty();

    // Returns an iterator pointing to first node after head
    Iterator first();

    // Returns an iterator pointing to last node before tail
    Iterator last();

    // Insert node after current position
    void insertAfter(int x, Iterator position);

    // Insert node before current position
    void insertBefore(int x, Iterator position);

    // Insert node at tail of list
    void insertAtTail(int x);

    // Finds first occurrence of node
    Iterator find(int x);

    // Removes the first occurrence of node
    void remove(int x);

    // Returns the number of elements in the list
    int size() const;

private:
    Node* head;
    Node* tail;
    int count;
};

// Prints list forwards when true, backward when false
void printList(Linked& source, bool forward);

#endif