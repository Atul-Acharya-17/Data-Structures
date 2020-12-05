#include <iostream>
#include "Node.h"
#include "BinarySearchTree.h"

using namespace std;

int main() {
	int choice = -1;
	int element;
	BinarySearchTree bst;
	bool found;

	do
	{
		cout << "\n";
		cout << "Enter your choice" << "\n";
		cout << "1.Insert" << "\n";
		cout << "2.Delete" << "\n";
		cout << "3.Pre Order Traversal" << "\n";
		cout << "4.In Order Traversal" << "\n";
		cout << "5.Post Order Traversal" << '\n';
		cout << "6.Level Order Traversal" << '\n';
		cout << "7.Search" << "\n";
		cout << "0.Exit" << "\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the value to be inserted" << "\n";
			cin >> element;
			bst.insert(bst.getRoot(), element);
			break;
		case 2:
			cout << "Enter the value to be removed" << "\n";
			cin >> element;
			bst.remove(element);
			break;
		case 3:
			if (bst.getRoot() == NULL)
			{
				cout << "Tree is empty" << "\n";
			}
			else
			{
				bst.preOrder(bst.getRoot());
				cout << "\n";
			}
			break;
		case 4:
			if (bst.getRoot() == NULL)
			{
				cout << "Tree is empty" << "\n";
			}
			else
			{
				bst.inOrder(bst.getRoot());
				cout << "\n";
			}
			break;
		case 5:
			if (bst.getRoot() == NULL)
			{
				cout << "Tree is empty" << "\n";
			}
			else
			{
				bst.postOrder(bst.getRoot());
				cout << "\n";
			}
			break;
		case 6:
			if (bst.getRoot() == NULL)
			{
				cout << "Tree is empty" << "\n";
			}
			else
			{
				bst.levelOrder();
				cout << "\n";
			}
			break;
		case 7:
			cout << "Enter the element to search for" << "\n";
			cin >> element;
			found = bst.search(element);
			if (found)
			{
				cout << "Element exists in the tree" << "\n";
			}
			else
			{
				cout << "Element does not exist in the tree" << "\n";
			}
			break;
		default:
			break;
		}


	} while (choice != 0);

	return 0;
}