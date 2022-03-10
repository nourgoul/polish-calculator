#include "Calculator.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
	Calculator calculator;
	string s;

	while (cin >> s) {
		if (s == "+") {
			calculator.addition();
		} 
		else if (s == "-") {
			calculator.subtraction();
		} 
		else if (s == "*") {
			calculator.multiplication();
		} 
		else if (s == "/") {
			calculator.division();
		} 
		else if (s == "~") {
			calculator.unary_negation();
		} 
		else {
			int digit = stoi(s);
			calculator.push(digit);
			calculator.top();
		}
	}
	cout << calculator.top() << endl;
	return 0;
}