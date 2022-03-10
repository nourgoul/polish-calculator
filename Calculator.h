#ifndef CALCULATOR_H 
#define CALCULATOR_H
#include "Stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Calculator {
public:
	Calculator(); // constructor
	int addition();
	int subtraction();
	int multiplication();
	int division();
	int unary_negation();
	int top();
	void push(int x);
private:
	Stack* stack;
};

#endif