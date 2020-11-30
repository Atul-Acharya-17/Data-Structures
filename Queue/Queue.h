#pragma once

#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

class Queue
{
public:
	Queue();
	void enqueue(int element);
	void dequeue();
	int peek();
	void traverse();
	bool search(int element);
	~Queue();;

private:
	Node* head;
	Node* tail;
};

#endif // !QUEUE_H
