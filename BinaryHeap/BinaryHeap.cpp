// BinaryHeap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include "BinaryHeap.h"

using namespace std;

BinaryHeap::BinaryHeap() {
    this->k = 4;
    this->last = -1;
    this->heap = new int[(int)pow(2, k) - 1];
}

void BinaryHeap::insert(int element) {
    if (last + 1 >= (int)pow(2, k) - 1)
    {
        this->increaseSize();
    }
    heap[++this->last] = element;
    this->heapifyUpwards(this->last);
}

void BinaryHeap::increaseSize() {
    int* ptr = this->heap;
    this->k += 1;
    this->heap = new int[(int)pow(2, k) - 1];
    for (int i = 0; i <= this->last; i++)
    {
        this->heap[i] = ptr[i];  // Copy original contents to larger heap
    }
    delete ptr;
}

int BinaryHeap::extract() {
    if (last == -1)
    {
        return NULL;
    }

    int temp = this->heap[0];
    this->heap[0] = this->heap[this->last];
    this->heap[this->last] = temp;

    this->last--;
    heapifyDownwards(0);
    return temp;
}

int BinaryHeap::peek() {
    if (this->last == -1)
    {
        return NULL;
    }
    else
    {
        return this->heap[0];
    }
}

void BinaryHeap::traverse() {
    cout << "Min Heap: ";
    for (int i = 0; i <= this->last; ++i) {
        cout << this->heap[i] << ", ";
    }
    cout << "\n";
}

bool BinaryHeap::search(int element) {
    for (int i = 0; i <= this->last; ++i) {
        if (this->heap[i] == element){
            return true;
        }
    }
    return false;
}

void BinaryHeap::heapifyUpwards(int i) {
    if (i == 0)
    {
        return;
    }
    int parent = i / 2;
    if (this->heap[parent] > this->heap[i])
    {
        int temp = this->heap[parent];
        this->heap[parent] = this->heap[i];
        this->heap[i] = temp;
        this->heapifyUpwards(parent);
    }

    return;
}

void BinaryHeap::heapifyDownwards(int i) {
    i += 1; // Starts from i = 0;

    int leftChild = 2 * i - 1;
    int rightChild = 2 * i;

    if (leftChild > this->last)
    {
        return;
    }

    int smallerChild;
    if (rightChild > last)
    {
        smallerChild = leftChild;
    }

    else
    {
        smallerChild = this->heap[leftChild] < this->heap[rightChild] ? leftChild : rightChild;
    }

    if (this->heap[smallerChild] < this->heap[i - 1])
    {
        int temp = this->heap[smallerChild];
        this->heap[smallerChild] = this->heap[i - 1];
        this->heap[i - 1] = temp;

        this->heapifyDownwards(smallerChild);
    }

    return;

    
}

BinaryHeap::~BinaryHeap() {
    delete[] this->heap;
    this->heap = NULL;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
