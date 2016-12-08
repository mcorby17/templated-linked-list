#include <iostream>
#include "linkedList.h"
using namespace std;

template <class T>
linkedList<T>::linkedList(){
	a.data = 0;
	a.next = nullptr;
	head = tail = temp = nullptr;
}

template <class T>
void linkedList<T>::insertNode() {
	T d;
	cin >> d;
	temp = new node;
	temp->data = d;
	temp->next = nullptr;
	if (head == nullptr) {		// If there's no nodes
		head = temp;
		tail = temp;
	}
	else {						// If there are, attach to end of list
		tail->next = temp;		// Connects new node to linked list
		tail = temp;
	}
}

template <class T>
void linkedList<T>::deleteNode() {
	T d;
	cin >> d;
	int count = 0;										// Used to make prev point to the node before temp
	node *nodeToLink, *prev;							// Needed to save address of node ahead of deleted node
	prev = nodeToLink = head;									// Start temp pointer at beginning of list
	temp = head;
	int listLength = this->listLength();

	
	if (temp == nullptr)								// If there's 0 nodes in the list
		cout << "There's no nodes to delete.\n";
	else if (listLength == 1) {						// If there's 1 node in the list
		delete temp;
		head = nullptr;
	}
	else {											// More than 1 node in the list
		while (temp->data != d) {					// Go through list until you find node with same data in it
			temp = temp->next;
			count++;
		}
		if (temp != tail)						// If the node isn't the last in the list
			nodeToLink = temp->next;				// Set a pointer to the next node
		if (count == 0) {							// If the first node in the list will be deleted
			delete temp;
			head = nodeToLink;
		}
		else {
			for (int i = 0; i < count-1; i++)		// Set the prev pointer to point at the node before the node temp is pointing to
				prev = prev->next;
			if (temp == tail) {						// If the node is the last in the list
				tail = prev;						// Reset tail to the previous node in the list
				prev->next = nullptr;
			}										
			else                                    
				prev->next = nodeToLink;            // Otherwise, make prev point to the node after the deleted node
			delete temp;
			
		}
	}
}

template <class T>
void linkedList<T>::printList() {
	if (head == nullptr)
		cout << "There are no nodes.";
	else {
		temp = head;
		while (temp != nullptr) {
			if (temp->next == nullptr)
				cout << temp->data;
			else
				cout << temp->data << " -> ";
			temp = temp->next;
		}
	}
	cout << endl;
}

template <class T>
int linkedList<T>::listLength() {
	node *ptr = head;
	int numOfNodes = 0;
	while (ptr != nullptr) {
		numOfNodes++;
		ptr = ptr->next;
	}
	return numOfNodes;
}