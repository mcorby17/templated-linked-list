#pragma once
template <class T>
class linkedList {
private:
	struct node {
		T data;
		node *next;
	};
	node a;
	node *head, *tail, *temp;

public:
	linkedList();
	void insertNode();
	void deleteNode();
	void printList();
	int listLength();
};
