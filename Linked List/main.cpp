#include <iostream>
#include "linkedList.cpp"
using namespace std;

int main() {
	linkedList <int> list;
	char choice;

	/*
	cout << "What type of data would you like to enter?/n";
	cout << "I - Integers\n";
	cout << "D - Doubles\n";
	cout << "C - Characters\n";
	cin >> choice;
	*/

	do {
	    cout << "A - Add node\n";										//Prompt
		cout << "D - Delete node\n";
		cout << "P - Print list\n";
		cout << "L - Print list length\n";
		cout << "Q - quit\n";
		cout << "Enter a command: ";
		cin >> choice;

		if (choice == 'A' || choice == 'a') {							//Add node
			cout << "Enter a value to put in the linked list: ";
			list.insertNode();
			cout << endl;
		}
		else if (choice == 'D' || choice == 'd') {						//Remove node
			cout << "Enter a value to remove\n";
			list.deleteNode();
			cout << endl;
		}
		else if (choice == 'P' || choice == 'p') {						//Print list
			cout << endl;
			list.printList();
			cout << endl;
		}
		else if (choice == 'L' || choice == 'l') {
			cout << "There are " << list.listLength() << " nodes.\n";
		}
		else {															//Error
			cerr << "Invalid command\n";
			exit(1);
		}
	} while (choice != 'Q' || choice != 'q');

	return 0;
}