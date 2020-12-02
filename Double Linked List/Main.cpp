#include <iostream>
#include "Node.h"
#include "DoublyLinkedList.h"

using namespace std;

int main() {
	int choice = -1;
	int index;
	int element;
	DoublyLinkedList dll;
	bool found;

	do
	{
		cout << "\n";
		cout << "Enter your choice" << "\n";
		cout << "1.Add" << "\n";
		cout << "2.Remove" << "\n";
		cout << "3.Traverse forward" << "\n";
		cout << "4.Traverse backward" << "\n";
		cout << "5.Search" << "\n";
		cout << "0.Exit" << "\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the value to be inserted" << "\n";
			cin >> element;
			cout << "Enter the position of the element" << "\n";
			cin >> index;
			dll.insert(element, index);
			break;
		case 2:
			cout << "Enter the index of the element to remove" << "\n";
			cin >> index;
			dll.remove(index);
			break;
		case 3:
			dll.traverseForward();
			break;
		case 4:
			dll.traverseBackward();
			break;
		case 5:
			cout << "Enter the element to search for" << "\n";
			cin >> element;
			found = dll.search(element);
			if (found)
			{
				cout << "Element exists in the doubly linked list" << "\n";
			}
			else
			{
				cout << "Element does not exist in the doubly linked list" << "\n";
			}
			break;
		default:
			break;
		}


	} while (choice != 0);
	return 0;
}