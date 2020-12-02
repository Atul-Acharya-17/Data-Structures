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
		cout << "\n";
		cout << "Enter your choice" << "\n";
		cout << "1.Push" << "\n";
		cout << "2.Pop" << "\n";
		cout << "3.Traverse" << "\n";
		cout << "4.Peek" << "\n";
		cout << "5.Search" << "\n";
		cout << "0.Exit" << "\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the value to be inserted" << "\n";
			cin >> element;
			stack.push(element);
			break;
		case 2:
			stack.pop();
			break;
		case 3:
			stack.traverse();
			break;
		case 4:
			element = stack.peek();
			if (element == NULL)
			{
				cout << "Stack is empty" << "\n";
			}
			else
			{
				cout << element << " is at the top of the stack" << "\n";
			}
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
	return 0;
}
