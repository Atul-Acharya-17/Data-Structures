#pragma once

#include "Node.h"
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int size;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void insert(int, int);
	void remove(int);
	void traverseForward();
	void traverseBackward();
	bool search(int);
};

#endif // !DOUBLYLINKEDLIST_H
