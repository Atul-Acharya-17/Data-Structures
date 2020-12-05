// OpenAddressHashing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OpenAddressHashing.h"
#define mod %

using namespace std;

OpenAddressHashing::OpenAddressHashing() {
    size = 0;
    table = new int[MAX_SIZE];
    tombstone = new int[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        table[i] = NULL;
        tombstone[i] = 0;
    }
}

void OpenAddressHashing::insert(int element) {
    if (size == MAX_SIZE)
    {
        cout << "Table is full" << "\n";
        return;
    }
    int i = 0;
    while (true)
    {
        int key = (hash(element) + i * doubleHash(element)) mod MAX_SIZE;
        if (table[key] == NULL)
        {
            table[key] = element;
            tombstone[key] = 0;
            size += 1;
            return;
        }
        ++i;
    }
}

void OpenAddressHashing::remove(int element) {
    int i = 0;
    while (true)
    {
        int key = hash(element) + i * doubleHash(element);
        if (tombstone[key] == 1)
        {
            i++;
            continue;
        }
        else if (table[key] == NULL) {
            cout << "Element does not exist" << "\n";
            break;
        }
        else if (table[key] != element)
        {
            i++;
            continue;
        }
     
        else {
            table[key] = NULL;
            tombstone[key] = 1;
            size -= 1;
            cout << "Element deleted from the table" << "\n";
            break;
        }
        ++i;
    }
}

void OpenAddressHashing::traverse() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (tombstone[i] == 1)
        {
            cout << i << " : Tombstone" << "\n";
        }
        else if (table[i] == NULL) {
            cout << i << " :" << "\n";
        }
        else
        {
            cout << i << " : " << table[i] << "\n";
        }
    }
    cout << "\n";
}

bool OpenAddressHashing::search(int element) {
    int i = 0;
    while (true)
    {
        int key = hash(element) + i * doubleHash(element);
        if (tombstone[key] == 1)
        {
            i++;
            continue;
        }
        else if (table[key] == NULL) {
            return false;
        }
        else if (table[key] == element)
        {
            return true;
        }
        else
        {
            ++i;
            continue;
        }
    }
}

int OpenAddressHashing::hash(int x) {
    int result = x >= 0 ? x mod 13 : -((-x) mod 13 - 13);
    result = result == 13 ? 0 : result;
    return result;
}

int OpenAddressHashing::doubleHash(int x) {
    return 1;
}

OpenAddressHashing::~OpenAddressHashing() {
    delete[] table;
    delete[] tombstone;
}