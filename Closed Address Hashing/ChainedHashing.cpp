#include <iostream>
#include "Node.h"
#include "ChainedHashing.h"
#define mod %

using namespace std;

ChainedHash::ChainedHash() {
    for (int i = 0; i < 7; ++i) {
        keys[i] = NULL;
    }
}

int ChainedHash::hash(int x) {
    int result = x >= 0 ? x mod 7 : -((-x) mod 7 - 7);
    result = result == 7 ? 0 : result;
    return result;
}

void ChainedHash::insert(int element) {
    int key = hash(element);
    Node* newNode = new Node;
    newNode->value = element;
    newNode->next = NULL;

    if (keys[key] == NULL) {
        keys[key] = newNode;
    }
    else
    {
        Node* ptr = keys[key];
        while (ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void ChainedHash::remove(int element) {
    int key = hash(element);
    Node* ptr = keys[key];
    if (ptr == NULL)
    {
        cout << "Element does not exist" << "\n";
        return;
    }

    if (ptr->value == element)
    {
        Node* delNode = keys[key];
        keys[key] = keys[key]->next;
        delete delNode;
        cout << "Element deleted from the table" << "\n";
        return;
    }

    while (ptr->next != NULL)
    {
        
        if (ptr->next->value == element)
        {
            Node* delNode = ptr->next;
            ptr->next = ptr->next->next;
            delete delNode;
            cout << "Element deleted from the table" << "\n";
            return;
        }
        ptr = ptr->next;
    }
    cout << "Element does not exist" << "\n";
}

bool ChainedHash::search(int element) {
    int key = hash(element);
    Node* ptr = keys[key];
    while (ptr!=NULL){
        if (ptr->value == element)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

void ChainedHash::traverse() {
    for (int i = 0; i < 7; i++)
    {
        Node* ptr = keys[i];
        cout << i << " : ";
        while (ptr != NULL)
        {
            cout << ptr->value << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
    cout << "\n";
}

ChainedHash::~ChainedHash() {
    for (int i = 0; i < 7; i++)
    {
        while (keys[i] != NULL)
        {
            Node* ptr = keys[i];
            keys[i] = keys[i]->next;
            delete ptr;
        }
    }
}

