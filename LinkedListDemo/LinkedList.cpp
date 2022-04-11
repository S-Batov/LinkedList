#include "LinkedList.h"


LinkedList::Node::Node() {
	data = 0;
	next = nullptr;
}

LinkedList::Node::Node(int dataVal){
	data = dataVal;
	next = nullptr;
}

LinkedList::LinkedList() {
	this->head = new Node;
}
void LinkedList::addNewNode(int dataVal) {
	Node* newNode = new Node(dataVal);

	if (head->next == nullptr) {
		head->data = dataVal;
		head->next = nullptr;
		delete newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
		if (temp->next == nullptr) {
			temp->next = newNode;
			newNode->data = dataVal;
			newNode->next = nullptr;
			return;
		}
	}
}

void LinkedList::deleteNode(int index)
{
	int counter = 0;
	Node* temp = head->next;
	while (temp != nullptr) {
		
	}
}
