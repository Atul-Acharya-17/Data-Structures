#pragma once

#ifndef STACK_H
#define STACK_H
#include "Node.h"

class Stack {
private:
	Node* top;
public:
	Stack();
	void push(int element);
	void pop();
	int peek();
	void traverse();
	bool search(int element);
	~Stack();

};

#endif // !STACK_H