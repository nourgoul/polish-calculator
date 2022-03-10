#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
public:
    // Constructor
    Node();         

private:
    int value;          
    Node* next;     
    Node* previous; 

    friend class Linked;
    friend class Iterator;
};

#endif