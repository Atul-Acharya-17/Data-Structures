#include <iostream>
#include "Node.h"
#include "Stack.h"

using namespace std;

int main() {
	int choice = -1;
	int element;
	Stack stack;
	bool found;

	do
	{
		cout << "Enter your choice" << "\n";
		cout << "1.Push" << "\n";
		cout << "2.Pop" << "\n";
		cout << "3.Traverse" << "\n";
		cout << "4.Peek" << "\n";
		cout << "5.Search" << '\n';

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the value to be inserted" << "\n";
			cin >> element;
			stack.push(element);
			break;
		case 2:
			element = stack.peek();
			stack.pop();
			cout << element << " was popped from the stack" << "\n";
			break;
		case 3:
			stack.traverse();
			break;
		case 4:
			element = stack.peek();
			cout << element << " is at the top of the stack" << "\n";
			break;
		case 5:
			cout << "Enter the element to search for" << "\n";
			cin >> element;
			found = stack.search(element);
			if (found)
			{
				cout << "Element exists in the stack" << "\n";
			}
			else
			{
				cout << "Element does not exist in the stack" << "\n";
			}
			break;
		default:
			break;
		}


	} while (choice != 0);
}