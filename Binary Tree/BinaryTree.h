#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"

class BinaryTree {
private:
	Node* root;
public:
	BinaryTree();
	void insert(int element);
	void remove(int element);
	int peek();
	void preOrderTraversal(Node* );
	void inOrderTraversal(Node* );
	void postOrderTraversal(Node* );
	void levelOrderTraversal();
	bool search(int element);
	void postOrderDelete(Node*);
	bool isEmpty();
	~BinaryTree();
	Node* getRoot() {
		return root;
	}
};

#endif // !BINARYTREE_H
