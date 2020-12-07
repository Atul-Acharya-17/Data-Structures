#pragma once
 
#ifndef BINARYHEAP_H
#define BINARYHEAP_H

class BinaryHeap {
private:
	int* heap;
	int k;
	int last;
	void heapifyUpwards(int);
	void heapifyDownwards(int);
	void increaseSize();
public:
	BinaryHeap();
	void insert(int);
	int extract();
	int peek();
	bool search(int);
	void traverse();
	~BinaryHeap();


};


#endif // !BINARYHEAP_H
