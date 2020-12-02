#include <iostream>
#include "Node.h"
#include "CircularLinkedList.h"

using namespace std;

int main() {
	int choice = -1;
	int index;
	int element;
	CircularLinkedList cll;
	bool found;

	do
	{
		cout << "\n";
		cout << "Enter your choice" << "\n";
		cout << "1.Add" << "\n";
		cout << "2.Remove" << "\n";
		cout << "3.Traverse" << "\n";
		cout << "4.Search" << "\n";
		cout << "0.Exit" << "\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the value to be inserted" << "\n";
			cin >> element;
			cout << "Enter the position of the element" << "\n";
			cin >> index;
			cll.add(element, index);
			break;
		case 2:
			cout << "Enter the index of the element to remove" << "\n";
			cin >> index;
			cll.remove(index);
			break;
		case 3:
			cll.traverse();
			break;
		case 4:
			cout << "Enter the element to search for" << "\n";
			cin >> element;
			found = cll.search(element);
			if (found)
			{
				cout << "Element exists in the circular linked list" << "\n";
			}
			else
			{
				cout << "Element does not exist in the circular linked list" << "\n";
			}
			break;
		default:
			break;
		}


	} while (choice != 0);
	return 0;
}
