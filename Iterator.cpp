#include <iostream>
#include "Iterator.h"
#include "Linked.h"
using namespace std;

// Constructors
Iterator::Iterator() {
	current = NULL;
}

Iterator::Iterator(Node* theNode) {
	current = theNode;
}

// Returns whether iterator is at the tail node
bool Iterator::isPastEnd() const {
	if (current -> next == NULL) // if there's nothing past current
		return true; // we're at the end!
	else
		return false; // we are not
}

// Returns whether iterator is at the head node 
bool Iterator::isPastBeginning() const {
	if (current -> previous == NULL)
		return true;
	else
		return false;
}

// Moves forward
void Iterator::moveForward() {
	if(!isPastEnd())
		current = current -> next; // i do not think this is right
}

// Moves backward
void Iterator::moveBackward() {
	if (!isPastBeginning())
		current = current -> previous;
}

// Returns value of current node
int Iterator::retrieve() const {
	return current -> value;
}