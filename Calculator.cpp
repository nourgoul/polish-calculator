#include "Calculator.h"
#include "Stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Calculator::Calculator() {
	stack = new Stack(); 
}

int Calculator::addition() {
	if (!(stack -> empty() == true)) {
	int num1 = stack -> top();
	stack -> pop();
	int num2 = stack -> top(); // num1 -> previous
	stack -> pop();
	int result = num1 + num2;
	stack -> push(result);
	return result;
	} else {
		return 0;
	}
}

int Calculator::subtraction() {
	if (!(stack -> empty() == true)) {
		int num1 = stack -> top();
		stack -> pop();
		int num2 = stack -> top(); 
		stack -> pop();
		int result = num2 - num1;
		stack -> push(result);
		return result;
	} else {
		exit(-1);
	}
}

int Calculator::multiplication() {
	if (!(stack -> empty() == true)) {
		int num1 = stack -> top();
		stack -> pop();
		int num2 = stack -> top(); 
		stack -> pop();
		int result = num1 * num2;
		stack -> push(result);
		return result;
	} else { 
		exit(-1);
	}
}

int Calculator::division() {
	if (!(stack -> empty() == true)) {
		int num1 = stack -> top();
		stack -> pop();
		int num2 = stack -> top(); 
		stack -> pop();
		int result = num2 / num1;
		stack -> push(result);
		return result;		
	} else { 
		exit(-1);
	}
}

int Calculator::unary_negation() {
	if (!(stack -> empty() == true)) {
		int num1 = stack -> top();
		stack -> pop();
		int result = -num1;
		stack -> push(result);
		return result;
	} else { 
		exit(-1);
	}
}

int Calculator::top() {
	if (!stack -> empty()) {
		return stack -> top();
	} else {
		exit(-1);
	}
}

void Calculator::push(int x) {
	stack -> push(x);
}