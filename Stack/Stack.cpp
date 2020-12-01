#include "Node.h"
#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack() {
    top = NULL;
}

void Stack::push(int element) {
    Node* newNode = new Node;
    newNode->value = element;
    newNode->next = top;
    top = newNode;
}

void Stack::traverse() {
    Node* ptr = top;
    cout << "top";
    while (ptr != NULL) {
        cout << "->" << ptr->value;
        ptr = ptr->next;
    }
    cout << "\n";
}

void Stack::pop() {
    if (isEmpty())
    {
        cout << "Underflow" << "\n";
        return;

    }
    int element = peek();
    cout << element << " was popped from the stack" << "\n";
    Node* topNode = top;
    top = top->next;
    delete topNode;

}

int Stack::peek() {
    if (isEmpty())
    {
        return NULL;
    }
    return top->value;
}

bool Stack::isEmpty() {
    return top == NULL;
}

bool Stack::search(int element) {
    Node* ptr = top;
    while (ptr != NULL) {
        if (ptr->value == element) {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

Stack::~Stack() {
    while (top != NULL) {
        Node* ptr = top;
        top = top->next;
        delete ptr;
    }
}
