#include <iostream>
#include "Node.h"
#include "Queue.h"

using namespace std;

Queue::Queue() {
    head = NULL;
    tail = NULL;
}

void Queue::enqueue(int element) {
    Node* newNode = new Node;
    newNode->value = element;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }

    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::dequeue() {
    Node* ptr = head;
    if (ptr == NULL)
        return;
    else if (head == tail)
    {
        head = tail = NULL;
        delete ptr;
    }
    else
    {
        head = head->next;
        delete ptr;
    }
}

int Queue::peek(){
    return head->value;
}

void Queue::traverse() {
    Node* ptr = head;
    cout << "head";
    while (ptr!=NULL)
    {
        cout << "->" << ptr->value;
        ptr = ptr->next;
    }
    cout << "->tail" << "\n";
}

bool Queue::search(int element) {
    Node* ptr = head;
    while (ptr != NULL)
    {
        if (ptr->value == element)
            return true;
        ptr = ptr->next;
    }
}

Queue::~Queue() {
    while (head!=NULL)
    {
        Node* ptr = head;
        head = head->next;
        delete ptr;
    }
    tail = NULL;
}