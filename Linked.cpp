#include <iostream>
#include "Linked.h"
#include "Iterator.h"
using namespace std;

// Default constructor
Linked::Linked() { // default constructor
    head= new Node(); // should this be null or new?
    tail= new Node();
    head->next=tail;
    tail->previous=head;
    head->previous=NULL;
    tail->next=NULL;
    count=0;
}

// Copy constructor
Linked::Linked(const Linked& source) {
    head=new Node();
    tail=new Node();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    Iterator iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Destructor
Linked::~Linked() { 
	makeEmpty();
	delete head;
	delete tail;
}


// Copy assignment operator
Linked& Linked::operator=(const Linked& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        Iterator iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

// Inserts x at tail of list
void Linked::insertAtTail(int x) { // are we putting x before or after the tail??
// before: tailprev -> tail
// after: tailprev -> x -> tail
	Node *newNode = new Node(); // soon to be x
	Node *tailPrevNode = tail -> previous; // before tail
	newNode -> value = x; // int to int, value = x
	
	// tail and x
	newNode -> next = tail; // x -> tail
	tail -> previous = newNode; // tail < - x	

	// tailprev and x
	tailPrevNode -> next = newNode; // before tail -> x
	newNode -> previous = tailPrevNode; // before tail -> x -> tail

	count++; // add another element to the count
}

// Returns an iterator pointing to first node after head
Iterator Linked::first() {
	if (head -> next != NULL){
		return Iterator(head -> next);
	}
	else {
		return NULL;
	}
}

// Returns an iterator pointing to last node before tail
Iterator Linked::last() {
	if (tail -> previous != NULL) {
		return Iterator(tail -> previous);
	}
	else {
		return NULL;
	}
}

// Returns the number of elements in the list
int Linked::size() const {
	return count;
}

// Returns whether list is empty
bool Linked::isEmpty() const {
	if (head -> next == NULL) {
		return true;
	}
	else {
		return false;
	}
}

// Insert node after current position
void Linked::insertAfter(int x, Iterator position) {
// put x after the current position
// before: prevNode -> currentNode
// after: prevNode -> currentNode -> x	
	Node* newNode = new Node();
	newNode -> value = x;
	Node* currentNode = position.current; // newNode should be AFTER the current position
	newNode -> next = currentNode -> next;
	currentNode -> next = newNode;
	newNode -> previous = currentNode;

	count++;
}

// Insert node before current position
void Linked::insertBefore(int x, Iterator position) {
	// sandwich x between current's previous and current
	// before: prevNode -> currentNode
	// after: prevNode -> newNode -> currentNode
	Node* newNode = new Node();
	newNode -> value = x;
	Node* currentNode = position.current;
	Node* prevNode = currentNode -> previous;

	currentNode -> previous = newNode;
	prevNode -> next = newNode;
	newNode -> next = currentNode;
	newNode -> previous = prevNode; // again redundancy

	count++;
}

// Removes the first occurrence of node
void Linked::remove(int x) {
	// before: prevNode -> currentNode -> nextNode
	// after: prevNode -> nextNode
	Iterator iter = find(x);
	Node* currentNode = iter.current;
	Node* prevNode = currentNode -> previous;
	Node* nextNode = currentNode -> next;

	prevNode -> next = nextNode; // prevNode -> nextNode
	nextNode -> previous = prevNode; // prevNode -> nextNode
	delete(currentNode);
	count--;
}

// Finds first occurrence of node
Iterator Linked::find(int x) {
   	Iterator iter = last();
    while (!iter.isPastBeginning()) {
        if (iter.current->value == x) {
            return iter;
        }
        iter.moveBackward();
    }
    return iter;
}

// Empties all nodes except head and tail
void Linked::makeEmpty() {
  	Node *newNode;
	Iterator iter = first();
 	while(!iter.isPastEnd()) {
      newNode = iter.current;
      iter.moveForward();
      delete (newNode);
    }
	head->next = tail;
  	tail->previous = head;
    count = 0;
}

// Prints list forwards when true, backward when false
void printList(Linked& source, bool forward) {// this should definitely work
	Iterator iter;
	if (forward == true) { // forward
		Iterator iter = source.first();
		while (!iter.isPastEnd()) {
			cout << iter.retrieve() << " ";
			iter.moveForward();
		}
	} else if (forward != true) { // backwards - not working
		Iterator iter = source.last();
		while (!iter.isPastBeginning()) {
			cout << iter.retrieve() << " ";
			iter.moveBackward();
		}
	} else { // null
		cout << " " << endl;
	}
	cout << endl;
}