# Reverse Polish Notation (RPN) Calculator

Reverse Polish notation (RPN), also known as Polish postfix notation or simply postfix notation, is a mathematical notation in which **operators follow their operands**. It does not need any parentheses as long as each operator has a fixed number of operands. For example, the in-fix notation <code>(4 - 3) * 7 </code> becomes <code>4 3 - 7 *</code> in post-fix notation. Values and operators are read left to right. Once an operator is read, two values are popped off the stack and one value (the result) is pushed back. In this program, I:

- Implement a RPN calculator that takes in an unlimited input
- Internally use a linked list data structure
- Implement my own stack data structure to push and pop values and operators on and off as needed

# Operations

<code>+</code>: Adds two elements <code>a</code> and <code>b</code>. <code> 1 + 2</code> = <code> 1 2 +</code>

<code>-</code>: Subtracts two elements <code>a</code> and <code>b</code>. <code>2 - 1</code> = <code>2 1 -</code>

<code>/</code>: Divides two elements <code>a</code> and <code>b</code>. <code>4 / 2</code> = <code>4 2 /</code>

<code>*</code>: Multiplies two elements <code>a</code> and <code>b</code>. <code>2 * 4</code> = <code>2 4 *</code>

<code>~</code>: Negates a number <code>a</code> and does not use a second number. <code>-3</code> = <code>3 ~</code>

# Instructions

Read in input after running (ex. <code>-2400 -12 -2 / / -4 / 1 /</code>), enter, then end the read-in loop with **^D**.

# Demo

![Inputting the string "1 2 3 4 5 + + + +" which return 15.](https://user-images.githubusercontent.com/72585332/157784873-84f5ef1f-23d0-41a6-aa3c-0ec5d4ea22f9.gif)
