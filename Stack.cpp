#include <iostream>
#include "Linked.h"
#include "Stack.h"
using namespace std;

Stack::Stack() { 
	stack = new Linked(); 
	count = 0;
}

Stack::~Stack() {
	delete stack;
}

bool Stack::empty() const {
	if (count == 0) { 
		return true;
	} else {
		return false;
	}
}

void Stack::push(int value) {
	stack -> insertAtTail(value);
	count++;
}

void Stack::pop() { 
	Iterator element = stack -> last();
	stack -> remove(element.retrieve());
	count--;
}

int Stack::top() const {
	Iterator element = stack -> last();
	return element.retrieve();
}