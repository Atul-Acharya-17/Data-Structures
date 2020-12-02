#pragma once

#ifndef CIRCULARLINKEDLIST
#define CIRCULARLINKEDLIST
#include "Node.h"

class CircularLinkedList
{
public:
	CircularLinkedList();
	void add(int, int);
	void remove(int);
	void traverse();
	bool search(int);
	~CircularLinkedList();

private:
	Node* tail;
	int size;
};

#endif // !CIRCULARLINKEDLIST
