#pragma once
#include "Node.h"

#ifndef CHAINEDHASH_H
#define CHAINEDHASH_H
class ChainedHash
{
public:
	ChainedHash();
	void insert(int);
	void remove(int);
	bool search(int);
	void traverse();
	~ChainedHash();
private:
	Node* keys[7];
	int hash(int);
};

#endif // !CHAINEDHASH
