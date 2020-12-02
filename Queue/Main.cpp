#include<iostream>
#include"Node.h"
#include"Queue.h"

using namespace std;

int main() {
	int choice = -1;
	int element;
	Queue queue;
	bool found;

	do
	{
		cout << "\n";
		cout << "Enter your choice" << "\n";
		cout << "1.Enqueue" << "\n";
		cout << "2.Dequeue" << "\n";
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
			queue.enqueue(element);
			break;
		case 2:
			queue.dequeue();
			break;
		case 3:
			queue.traverse();
			break;
		case 4:
			element = queue.peek();
			if (element == NULL)
			{
				cout << "Queue is empty" << "\n";
			}
			else
			{
				cout << element << " is at the head of the queue" << "\n";
			}
			break;
		case 5:
			cout << "Enter the element to search for" << "\n";
			cin >> element;
			found = queue.search(element);
			if (found)
			{
				cout << "Element exists in the queue" << "\n";
			}
			else
			{
				cout << "Element does not exist in the queue" << "\n";
			}
			break;
		default:
			break;
		}


	} while (choice != 0);
	return 0;
}
