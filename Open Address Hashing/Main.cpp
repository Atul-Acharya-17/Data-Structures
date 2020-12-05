#include <iostream>
#include "OpenAddressHashing.h"

using namespace std;

int main() {
	int choice = -1;
	int element;
	OpenAddressHashing oh;
	bool found;

	do
	{
		cout << "Enter your choice" << "\n";
		cout << "1.Insert" << "\n";
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
			oh.insert(element);
			break;
		case 2:
			cout << "Enter the value to be deleted" << "\n";
			cin >> element;
			oh.remove(element);
			break;
		case 3:
			oh.traverse();
			break;
		case 4:
			cout << "Enter the element to search for" << "\n";
			cin >> element;
			found = oh.search(element);
			if (found)
			{
				cout << "Element exists in the table" << "\n";
			}
			else
			{
				cout << "Element does not exist in the table" << "\n";
			}
			break;
		default:
			break;
		}


	} while (choice != 0);

	return 0;
}