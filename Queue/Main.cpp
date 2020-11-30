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
		cout << "Enter your choice" << "\n";
		cout << "1.Enqueue" << "\n";
		cout << "2.Dequeue" << "\n";
		cout << "3.Traverse" << "\n";
		cout << "4.Peek" << "\n";
		cout << "5.Search" << '\n';

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the value to be inserted" << "\n";
			cin >> element;
			queue.enqueue(element);
			break;
		case 2:
			element = queue.peek();
			queue.dequeue();
			cout << element << " was dequeued" << "\n";
			break;
		case 3:
			queue.traverse();
			break;
		case 4:
			element = queue.peek();
			cout << element << " is at the head of the queue" << "\n";
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
}