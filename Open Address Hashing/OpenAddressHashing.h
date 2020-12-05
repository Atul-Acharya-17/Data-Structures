#pragma once
#ifndef OPENADDRESSHASHING_H
#define OPENADDRESSHASHING_H
#define MAX_SIZE 10
class OpenAddressHashing {
private:
	int* table;
	int* tombstone;
	int size;
	int hash(int);
	int doubleHash(int);
public:
	OpenAddressHashing();
	void insert(int);
	void remove(int);
	void traverse();
	bool search(int);
	~OpenAddressHashing();
};

#endif // !OPENADDRESSHASHING_H