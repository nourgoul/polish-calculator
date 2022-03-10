#ifndef STACK_H 
#define STACK_H
#include "Linked.h"
#include "Node.h"
#include "Iterator.h"

class Stack {
public:
	// Constructor
	Stack();
	// Destructor
	~Stack(); 
	// Returns whether stack is empty
	bool empty() const; 
	// Adds element to the top of the stack
	void push(int value); 
	// Removes element on the top of the stack (doesn't return)
	void pop();
	// Returns element on the top of the stack
	int top() const;
private:
	Linked* stack; // my stack!
	int count;
};

#endif