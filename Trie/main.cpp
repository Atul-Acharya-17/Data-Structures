#include <iostream>
#include "Node.h"
#include "Trie.h"

using namespace std;

int main() {
	int choice = -1;
	string word;
	Trie trie;
	bool found;

	do
	{
		cout << "\n";
		cout << "Enter your choice" << "\n";
		cout << "1.Insert" << "\n";
		cout << "2.Delete" << "\n";
		cout << "3.Traverse" << "\n";
		cout << "4.Search" << "\n";
		cout << "0.Exit" << "\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the word to be inserted" << "\n";
			cin >> word;
			trie.insert(word);
			break;
		case 2:
			cout << "Enter the value to be removed" << "\n";
			cin >> word;
			trie.remove(word);
			break;
		case 3:
            trie.traverse();
            cout << "\n";
            break;
		case 4:
            cout << "Enter the word to be searched" << "\n";
            cin >> word;
            found = trie.search(word);
            if (found) cout << "Word found!" <<"\n";
            else cout << "Word not found :(" <<"\n";
            break;
		default:
			break;
		}

	} while (choice != 0);

	return 0;
}