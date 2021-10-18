#pragma once
#include "node.h"
#ifndef TRIE_H
#define TRIE_H

#include<string>

using namespace std;

class Trie {
private:
	Node* root;
public:

	Trie();
    void insert(string word);
    void remove(string word);
    void traverse();
    bool search(string word);
    void recursiveRemove(Node *ptr, string word, int idx);
    void recursiveTraverse(Node *ptr, string word);
    void recursiveDelete(Node *ptr);

    int countChildren(Node *ptr);
	~Trie();
};

#endif // !TRIE_H