#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

void DoublyLinkedList::insert(int element, int index){
    if (index < 0 || index > size)
    {
        cout << "Invalid index. The element will be inserted at the end of the list" << "\n";
    }

    Node* newNode = new Node;
    newNode->value = element;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }

    else if (index >= size || index < 0)
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    else if (index == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    else {
        int i = 0;
        Node* ptr = head;
        for (i = 0; i < index - 1; i++) {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        newNode->prev = ptr;
        ptr->next->prev = newNode;
        ptr->next = newNode;
    }

    size++;
    cout << "Element inserted" << "\n";
}

void DoublyLinkedList::remove(int index) {
    if (index < 0 || index >= size)
    {
        cout << "Invalid index" << "\n";
    }

    if (index == 0)
    {
        Node* delNode = head;
        head = head->next;
        head->prev = NULL;
        delete delNode;
        size--;
        cout << "Element deleted" << "\n";
        return;
    }

    if (index == size - 1) {
        Node* delNode = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete delNode;
        size--;
        cout << "Element deleted" << "\n";
        return;
    }


    if (index < size/2)
    {
        Node* ptr = head;
        int i = 0;
        for (i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
        }

        Node* delNode = ptr->next;
        ptr->next = ptr->next->next;
        ptr->next->prev = ptr;
        delete delNode;
        cout << "Element deleted" << "\n";
        size--;
    }

    else
    {
        Node* ptr = tail;
        int i = size - 1;
        for (; i > index + 1; i--)
        {
            ptr = ptr->prev;
        }

        Node* delNode = ptr->prev;
        ptr->prev = ptr->prev->prev;
        ptr->prev->next = ptr;
        delete delNode;
        cout << "Element deleted" << "\n";
        size--;
    }
}

void DoublyLinkedList::traverseForward() {
    if (head == NULL)
    {
        cout << "List is empty" << "\n";
        return;
    }
    cout << "head";
    Node* ptr = head;
    while (ptr != NULL)
    {
        cout << "->" << ptr->value;
        ptr = ptr->next;
    }
    cout << "\n";
}

void DoublyLinkedList::traverseBackward() {
    if (tail == NULL)
    {
        cout << "List is empty" << "\n";
        return;
    }
    cout << "tail";
    Node* ptr = tail;
    while (ptr != NULL)
    {
        cout << "->" << ptr->value;
        ptr = ptr->prev;
    }
    cout << "\n";
}

bool DoublyLinkedList::search(int element){
    Node* ptrFront = head;
    Node* ptrBack = tail;

    if (ptrFront == NULL)
    {
        return false;
    }

    int i = 0;

    while (i < size)
    {
        if (ptrFront->value == element || ptrBack->value == element)
            return true;
        ptrFront = ptrFront->next;
        ptrBack = ptrBack->prev;
        i+=2;
    }
    return false;
}

DoublyLinkedList::~DoublyLinkedList() {
    tail = NULL;
    while (head != NULL)
    {
        Node* ptr = head;
        head = head->next;
        delete ptr;
    }
}
