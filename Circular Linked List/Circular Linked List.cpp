#include <iostream>
#include "Node.h"
#include "CircularLinkedList.h"

using namespace std;

CircularLinkedList::CircularLinkedList() {
	tail = NULL;
	size = 0;
}

void CircularLinkedList::add(int element, int position) {
	Node* newNode = new Node;
	newNode->value = element;
	if (tail == NULL)
	{
		if (position > 0)
		{
			cout << "Position out of range, the element will be inserted at the end" << "\n";
		}
		tail = newNode;
		newNode->next = newNode;
	}
	else if (position >= size || position < 0)
	{
		if (position > size || position < 0)
		{
			cout << "Position out of range, the element will be inserted at the end" << "\n";
		}
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;

	}
	else if (position == 0)
	{
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = tail->next;
		tail->next = newNode;
	}
	else
	{
		Node* ptr = tail->next;
		int index = 0;
		for (index = 0; index < position - 1; index++)
		{
			ptr = ptr->next;
		}
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
	size++;
}

void CircularLinkedList::traverse() {
	if (tail == NULL)
	{
		cout << "List is empty" << "\n";
		return;
	}
	Node* ptr = tail->next;
	cout << "head";
	do
	{
		cout << "->" << ptr->value;
		ptr = ptr->next;
	} while (ptr!=tail->next);
	cout << "\n";
}

bool CircularLinkedList::search(int element) {
	if (tail == NULL) {
		cout << "List is empty" << "\n";
		return false;
	}

	Node* ptr = tail->next;
	do
	{
		if (ptr->value == element)
			return true;
		ptr = ptr->next;
	} while (ptr != tail->next);
	return false;
}

void CircularLinkedList::remove(int index) {
	if (index >= size)
	{
		cout << "Invalid index" << "\n";
		return;
	}
	if (tail == NULL)
	{
		cout << "List is empty" << "\n";
		return;
	}

	if (index == 0)
	{
		Node* ptr = tail->next;
		if (size == 1)
		{
			tail = NULL;
		}
		else
		{
			tail->next = tail->next->next;
		}
		int element = ptr->value;
		cout << element << " was removed from the list" << "\n";
		delete ptr;
	}

	else {
		int pos = 0;
		Node* ptr = tail->next;
		while (pos < index - 1)
		{
			pos++;
			ptr = ptr->next;
		}
		if (ptr->next == NULL || index < 0)
		{
			cout << "Invalid index" << "\n";
			return;
		}
		Node* delNode = ptr->next;
		int element = ptr->next->value;
		cout << element << " was removed from the list" << "\n";
		if (delNode == tail)
			tail = ptr;
		ptr->next = ptr->next->next;
		delete delNode;
	}
	size--;
}

CircularLinkedList::~CircularLinkedList() {
	Node* head = tail->next;
	tail->next = NULL;
	while (head != NULL) {
		Node* ptr = head;
		head = head->next;
		delete ptr;
	}
	tail = NULL;
}

