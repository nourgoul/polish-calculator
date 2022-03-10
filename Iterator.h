#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"
#include "Linked.h"

class Iterator {
public:
    // Constructors
    Iterator();
    Iterator(Node* theNode);

    // Returns whether iterator is at the tail node
    bool isPastEnd() const;

    // Returns whether iterator is at the head node 
    bool isPastBeginning() const;

    // Moves forward 
    void moveForward();

    // Moves back
    void moveBackward();

    // Returns value of current node
    int retrieve() const;

private:
    Node* current; // current node
    friend class Linked; 
};

#endif