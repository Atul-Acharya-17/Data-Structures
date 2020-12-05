#pragma once
#include "Node.h"
#ifndef BST_H
#define BST_H

class BinarySearchTree {
private:
	Node* root;
public:
	Node* getRoot() {
		return root;
	}

	BinarySearchTree();
	void insert(Node* currentNode, int element);
	void remove(int element);
	bool search(int element);
	void preOrder(Node* root);
	void postOrder(Node* root);
	void inOrder(Node* root);
	void levelOrder();
	void postOrderDelete(Node*);
	~BinarySearchTree();
};

#endif // !BST_H

