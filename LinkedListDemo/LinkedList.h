#pragma once

class LinkedList {	
public:
	class Node {
	public:
		Node();
		Node(int dataVal);
		int data;
		Node* next;
	};

private:
	Node* head;
public:
	LinkedList();
	void addNewNode(int dataVal);
	void deleteNode(int index);
};

