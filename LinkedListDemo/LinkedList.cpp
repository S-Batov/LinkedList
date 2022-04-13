#include "LinkedList.h"
#include <assert.h>

/*
LinkedList::Node::Node() {
	data = 0;
	next = nullptr;
}
*/

LinkedList::Node::Node(int dataVal){
	data = dataVal;
	next = nullptr;
}

LinkedList::LinkedList() {
	this->head = nullptr;
	len = 0;
}

int LinkedList::length() const
{
	return len;
}

void LinkedList::addFront(int dataVal)
{
	len++;
	Node* newNode = new Node(dataVal);

	if (head == nullptr) {
		head = newNode;
		return;
	}
	newNode->next = head;
	head = newNode;
}

void LinkedList::addBack(int dataVal) {
	len++;
	Node* newNode = new Node(dataVal);

	if (head == nullptr) {
		head = newNode;
		return;
	}

	Node* curr = head;
	while (curr->next != nullptr) {
		curr = curr->next;
	}
	curr->next = newNode;
	newNode->data = dataVal;
	newNode->next = nullptr;
}

void LinkedList::addAt(int index, int dataVal)
{
	assert(index < len && index >= 0);
	len++;
	Node* newNode = new Node(dataVal);

	if (index == 0) {
		newNode->next = head;
		head = newNode;
		return;
	}
	int counter = 0;
	Node* curr = head;
	while (curr->next != nullptr && counter < index - 1) {
		curr = curr->next;
		counter++;
	}
	Node* temp = curr->next;
	curr->next = newNode;
	newNode->next = temp;
}

void LinkedList::dropHead()
{
	assert(head != nullptr);
	Node* temp = head;
	head = head->next;
	delete temp;
	len--;
}

void LinkedList::dropTail()
{
	deleteAt(len - 1);
}

void LinkedList::deleteAt(int index)
{
	assert(index < len && index >= 0);
	Node* temp = head;
	if (index == 0) {
		head = head->next;
		delete temp;
		len--;
		return;
	}
	int counter = 0;
	while (counter < index - 1) {
		temp = temp->next;
		counter++;
	}
	Node* old = temp;
	temp = temp->next;
	Node* newNext = temp->next;
	delete temp;
	old->next = newNext;
	len--;
	return;
}

void LinkedList::deleteFromTo(int index1, int index2)
{
	assert(index1 < len && index1 >= 0);
	assert(index2 < len && index2 >= 0);
	assert(index1 != index2);
	if (index1 > index2) {
		int temp = index1;
		index1 = index2;
		index2 = temp;
	}

	int counter = 0;
	Node* curr = head;
	Node* prev = nullptr;
	Node* end = nullptr;

	if (index1 == 0) {
		while (counter <= index2) {
			prev = curr;
			curr = curr->next;
			delete prev;
			len--;
			counter++;
		}
		this->head = curr;
		return;
	}

	while (counter < index1){
		prev = curr;
		curr = curr->next;
		counter++;
	}
	end = prev;
	while (counter <= index2) {
		prev = curr;
		curr = curr->next;
		delete prev;
		len--;
		counter++;
	}
	end->next = curr;
}

void LinkedList::deleteLength(int index, int len_)
{
	assert(index < len && index >= 0);
	assert(len_ > 0);
	assert(index + len_ < len);
}

void LinkedList::deleteAll()
{
}
