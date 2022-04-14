#include "LinkedList.h"
#include <assert.h>

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

bool LinkedList::isEmpty() const
{
	return (head == nullptr) ? true : false;
}

bool LinkedList::isInList(int val) const
{
	assert(head != nullptr);
	int dataVal = head->data;
	Node* curr = head;
	while (curr != nullptr) {
		if (curr->data == val)
			return true;
		curr = curr->next;
	}
	return false;
}

int LinkedList::countRepetitions(int value) const
{
	assert(head != nullptr);
	int reps = 0;
	Node* curr = head;
	while (curr != nullptr) {
		if (curr->data == value)
			reps++;
		curr = curr->next;
	}
	return reps;
}

int LinkedList::getMinValue() const
{
	assert(head != nullptr);
	Node* curr = head;
	int min = curr->data;
	while (curr != nullptr) {
		if (curr->data < min)
			min = curr->data;
		curr = curr->next;
	}
	return min;
}

int LinkedList::getMaxValue() const
{
	assert(head != nullptr);
	Node* curr = head;
	int max = curr->data;
	while (curr != nullptr) {
		if (curr->data > max)
			max = curr->data;
		curr = curr->next;
	}
	return max;
}

int LinkedList::getValueAt(int index) const
{
	assert(head != nullptr);
	assert(index >= 0 && index < len);
	int counter = 0;
	Node* curr = head;
	while (counter < index) {
		curr = curr->next;
		counter++;
	}
	return curr->data;
}

int LinkedList::getIndexOfMin() const
{
	assert(head != nullptr);
	Node* curr = head;
	int index = 0;
	int counter = 0;
	int min = head->data;
	while (curr != nullptr) {
		if (curr->data < min) {
			min = curr->data;
			index = counter;
		}
		curr = curr->next;
		counter++;
	}
	return index;
}

int LinkedList::getIndeOfMax() const
{
	assert(head != nullptr);
	Node* curr = head;
	int index = 0;
	int counter = 0;
	int max = head->data;
	while (curr != nullptr) {
		if (curr->data > max) {
			max = curr->data;
			index = counter;
		}
		curr = curr->next;
		counter++;
	}
	return index;
}

int LinkedList::getIndexOf(int value) const
{
	assert(head != nullptr);
	Node* curr = head;
	int index = 0;
	while (curr != nullptr) {
		if (curr->data == value) {
			return index;
		}
		curr = curr->next;
		index++;
	}
	return -1;
}

void LinkedList::addFront(int dataVal)
{
	len++;
	Node* newNode = new Node(dataVal);
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
}

void LinkedList::addAt(int index, int dataVal)
{
	assert(index <= len && index >= 0);
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
	Node* curr = head;
	Node* prev = nullptr;
	if (index == 0) {
		head = head->next;
		delete curr;
		len--;
		return;
	}
	int counter = 0;
	while (counter < index) {
		prev = curr;
		curr = curr->next;
		counter++;
	}
	Node* newNext = curr->next;
	delete curr;
	prev->next = newNext;
	len--;
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
		head = curr;
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
	assert(index + len_ <= len);

	Node* curr = head;
	Node* prev = nullptr;
	int counter = 0;
	if (index == 0) {
		while (counter < len_) {
			prev = curr;
			curr = curr->next;
			head = curr;
			delete prev;
			counter++;
			len--;
		}
		return;
	}
	while (counter < index) {
		prev = curr;
		curr = curr->next;
		counter++;
	}
	Node* end = prev;
	counter = 0;
	while (counter < len_) {
		prev = curr;
		curr = curr->next;
		delete prev;
		counter++;
		len--;
	}
	end->next = curr;
}

void LinkedList::deleteAll()
{
	Node* curr = head;
	Node* prev = nullptr;
	while (curr != nullptr) {
		prev = curr;
		curr = curr->next;
		delete prev;
		len--;
	}
}

void LinkedList::swapNodes(int index1, int index2)
{
	assert(head != nullptr);
	assert(index1 >= 0 && index1 < len);
	assert(index2 >= 0 && index2 < len);

	if (index1 == index2) {
		return;
	}

	if (index1 > index2) {
		int temp = index1;
		index1 = index2;
		index2 = temp;
	}

	int counter = 0;
	Node* curr = head;
	Node* prev = nullptr;
	while (counter < index1) {
		prev = curr;
		curr = curr->next;
		counter++;
	}
	Node* n1 = curr;
	Node* n1p = prev;

	while (counter < index2) {
		prev = curr;
		curr = curr->next;
		counter++;
	}
	Node* n2 = curr;
	Node* n2p = prev;

	if (n1p != nullptr) {
		n1p->next = n2;
	}
	else {
		head = n2;
	}
	n2p->next = n1;
	Node* temp = n2->next;
	n2->next = n1->next;
	n1->next = temp;
}

void LinkedList::reverse()
{
	assert(head != nullptr);
	Node* curr = head;
	Node* prev = nullptr;
	Node* temp = nullptr;
	while (curr != nullptr) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
}

void LinkedList::sort()
{
	//https://www.educative.io/edpresso/how-to-sort-a-linked-list-using-merge-sort
	assert(head != nullptr);

}

void LinkedList::removeDuplicates()
{
}

void LinkedList::removeValue(int value)
{
	assert(head != nullptr);
	Node* curr = head;
	Node* prev = nullptr;
	while (curr != nullptr) {
		if (curr->data == value) {
			if (prev == nullptr) {
				head = head->next;
				delete curr;
				curr = head;
			}
			else {
				Node* newNext = curr->next;
				prev->next = curr->next;
				delete curr;
				curr = newNext;
			}
			len--;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
}

