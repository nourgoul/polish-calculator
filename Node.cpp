#include <iostream>
#include "Node.h"
#include "Linked.h"
#include "Iterator.h"
using namespace std;


Node::Node() {
	value = 0;
	next = NULL;
	previous = NULL;
}