#include "Node.h"
#include "BinarySearchTree.h"

#include <iostream>
#include <vector>

using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

void BinarySearchTree::insert(Node* curr, int element) {
	if (root == NULL)
	{
		Node* newNode = new Node;
		newNode->value = element;
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
		cout << "Element inserted successfully" << "\n";
		return;
	}

	if (curr->value < element)
	{
		if (curr->right == NULL)
		{
			Node* newNode = new Node;
			newNode->value = element;
			newNode->left = NULL;
			newNode->right = NULL;
			curr->right = newNode;
			cout << "Element inserted successfully" << "\n";
			return;
		}
		else
		{
			insert(curr->right, element);
		}
	}
	else
	{
		if (curr->left == NULL)
		{
			Node* newNode = new Node;
			newNode->value = element;
			newNode->left = NULL;
			newNode->right = NULL;
			curr->left = newNode;
			cout << "Element inserted successfully" << "\n";
			return;
		}
		else
		{
			insert(curr->left, element);
		}
	}
}

void BinarySearchTree::remove(int element) {
	if (this->root == NULL)
	{
		cout << "Element does not exist" << "\n";
		return;
	}
	
	Node* parent = this->root;
	Node* ptr = this->root;

	while (true) {
		if (ptr == NULL)
		{
			cout << "Element does not exist" << "\n";
			return;
		}
		if (element < ptr->value)
		{
			parent = ptr;
			ptr = ptr->left;
		}

		else if (element > ptr->value)
		{
			parent = ptr;
			ptr = ptr->right;
		}

		else {
			if (ptr->left == NULL && ptr->right == NULL) // Node to be deleted is a leaf node
			{
				if (parent->left == ptr)
				{
					parent->left = NULL;
				}
				else if (parent->right == ptr)
				{
					parent->right = NULL;
				}

				if (ptr == this->root)
				{
					root = NULL;
				}
				cout << "Element deleted successfully" << "\n";
				delete ptr;
				return;
			}

			else if (ptr->left != NULL && ptr->right != NULL) // Node to be deleted has 2 children
			{
				Node* successor = ptr->right;
				Node* parentSuccessor = ptr;

				while (successor->left != NULL)
				{
					parentSuccessor = successor;
					successor = successor->left;
				}
				ptr->value = successor->value;

				if (successor->right == NULL) // Successor node is a leaf node
				{
					if (parentSuccessor->left == successor)
					{
						parentSuccessor->left = NULL;
					}
					else
					{
						parentSuccessor->right = NULL;
					}
					cout << "Element deleted successfully" << "\n";
					delete successor;
					return;
				}

				else  // Successor node has a right child
				{
					if (parentSuccessor->left == successor)
					{
						parentSuccessor->left = successor->right;
					}
					else
					{
						parentSuccessor->right = successor->right;
					}
					cout << "Element deleted successfully" << "\n";
					delete successor;
					return;
				}
			}

			else if (ptr->left != NULL)  // Node to be deleted has only a left child
			{
				if (root == ptr)
				{
					root = ptr->left;
				}

				if (parent->left == ptr)
				{
					parent->left = ptr->left;
				}

				else
				{
					parent->right = ptr->left;
				}
				cout << "Element deleted successfully" << "\n";
				delete ptr;
				return;
			}

			else if (ptr->right != NULL) // Node to be deleted has only a right child
			{
				if (root == ptr)
				{
					root = ptr->right;
				}

				if (parent->left == ptr)
				{
					parent->left = ptr->right;
				}

				else
				{
					parent->right = ptr->right;
				}
				cout << "Element deleted successfully" << "\n";
				delete ptr;
				return;
			}
		}
	}
}

bool BinarySearchTree::search(int element) {

	if (root == NULL)
	{
		return false;
	}

	vector<Node*> queue;

	queue.push_back(root);

	while (queue.size() > 0 )
	{
		Node* ptr = queue.front();
		queue.erase(queue.begin());
		if (ptr->value == element)
		{
			return true;
		}

		else if (element < ptr->value)
		{
			if (ptr->left != NULL)
			{
				queue.push_back(ptr->left);
			}
			else
			{
				return false;
			}
		}

		else
		{
			if (ptr->right != NULL)
			{
				queue.push_back(ptr->right);
			}
			else
			{
				return false;
			}
		}
	}

}

void BinarySearchTree::preOrder(Node* root) {
	if (root == NULL)
	{
		return;
	}

	cout << root->value << ", ";
	preOrder(root->left);
	preOrder(root->right);
}

void BinarySearchTree::inOrder(Node* root) {
	if (root == NULL)
	{
		return;
	}

	inOrder(root->left);
	cout << root->value << ", ";
	inOrder(root->right);
}

void BinarySearchTree::postOrder(Node* root) {
	if (root == NULL)
	{
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout << root->value << ",";

}

void BinarySearchTree::levelOrder() {
	if (root == NULL)
	{
		return;
	}

	vector<Node*> queue;
	queue.push_back(root);

	while (queue.size() > 0)
	{
		Node* ptr = queue.front();
		queue.erase(queue.begin());

		cout << ptr->value << ", ";
		if (ptr->left != NULL)
		{
			queue.push_back(ptr->left);
		}
		if (ptr->right != NULL)
		{
			queue.push_back(ptr->right);
		}
	}
}

void BinarySearchTree::postOrderDelete(Node* parent) {
	if (parent == NULL)
	{
		return;
	}
	else
	{
		postOrderDelete(parent->left);
		parent->left = NULL;
		postOrderDelete(parent->right);
		parent->right = NULL;
		delete parent;
	}
}

BinarySearchTree::~BinarySearchTree() {
	postOrderDelete(root);
	root = NULL;
}
