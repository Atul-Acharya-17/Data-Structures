#include <iostream>
#include <math.h>
#include "BinaryHeap.h"

using namespace std;

int main() {
	int choice = -1;
	int element;
	BinaryHeap minHeap;
	bool found;

	do
	{
		cout << "\n";
		cout << "Enter your choice" << "\n";
		cout << "1.Insert" << "\n";
		cout << "2.Extract" << "\n";
		cout << "3.Traverse" << "\n";
		cout << "4.Peek" << "\n";
		cout << "5.Search" << '\n';
		cout << "0.Exit" << "\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the value to be inserted" << "\n";
			cin >> element;
			minHeap.insert(element);
			break;
		case 2:
			element = minHeap.extract();
			if (element == NULL)
			{
				cout << "0 (or NULL) was extracted from the heap" << "\n";
			}
			else
			{
				cout << element << " was extracted from the heap" << "\n";
			}
			break;
		case 3:
			minHeap.traverse();
			break;
		case 4:
			element = minHeap.peek();
			if (element == NULL)
			{
				cout << "0 (or NULL) is the smallest element in the heap" << "\n";
			}
			else
			{
				cout << element << " is the smallest element in the heap" << "\n";
			}
			break;
		case 5:
			cout << "Enter the element to search for" << "\n";
			cin >> element;
			found = minHeap.search(element);
			if (found)
			{
				cout << "Element exists in the heap" << "\n";
			}
			else
			{
				cout << "Element does not exist in the heap" << "\n";
			}
			break;
		default:
			break;
		}


	} while (choice != 0);
	return 0;
}