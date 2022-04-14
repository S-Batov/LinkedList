#include "LinkedList.h"
#include <assert.h>
#include <vector>

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

void LinkedList::deleteFromTo(int fromIndex, int toIndex)
{
	assert(fromIndex < len && fromIndex >= 0);
	assert(toIndex < len && toIndex >= 0);
	assert(fromIndex != toIndex);
	if (fromIndex > toIndex) {
		int temp = fromIndex;
		fromIndex = toIndex;
		toIndex = temp;
	}

	int counter = 0;
	Node* curr = head;
	Node* prev = nullptr;
	Node* end = nullptr;

	if (fromIndex == 0) {
		while (counter <= toIndex) {
			prev = curr;
			curr = curr->next;
			delete prev;
			len--;
			counter++;
		}
		head = curr;
		return;
	}
	while (counter < fromIndex){
		prev = curr;
		curr = curr->next;
		counter++;
	}
	end = prev;
	while (counter <= toIndex) {
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

void LinkedList::swapNodes(int fromIndex, int toIndex)
{
	assert(head != nullptr);
	assert(fromIndex >= 0 && fromIndex < len);
	assert(toIndex >= 0 && toIndex < len);

	if (fromIndex == toIndex) {
		return;
	}

	if (fromIndex > toIndex) {
		int temp = fromIndex;
		fromIndex = toIndex;
		toIndex = temp;
	}

	int counter = 0;
	Node* curr = head;
	Node* prev = nullptr;
	while (counter < fromIndex) {
		prev = curr;
		curr = curr->next;
		counter++;
	}
	Node* n1 = curr;
	Node* n1p = prev;

	while (counter < toIndex) {
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
	mergeSort(&head);

}

void LinkedList::removeDuplicates()
{
	assert(head != nullptr);
	std::vector<int> values;
	Node* curr = head;
	Node* prev = nullptr;
	while (curr != nullptr) {
		if ( isDup(curr->data, values) ) {
			Node* temp = curr->next;
			delete curr;
			curr = temp;
			prev->next = curr;
			len--;
		}
		else {
			values.push_back(curr->data);
			prev = curr;
			curr = curr->next;
		}	
	}
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

void LinkedList::appendList(LinkedList lst)
{
	Node* curr = this->head;
	while (curr->next != nullptr) {
		curr = curr->next;
	}
	curr->next = lst.head;
	len += lst.len;
}

void LinkedList::addValuesFrom(LinkedList lst)
{
	assert(this->head != nullptr);
	assert(lst.head != nullptr);
	Node* curr = lst.head;
	while (curr != nullptr) {
		this->addBack(curr->data);
		curr = curr->next;
	}
}

void LinkedList::addValuesFrom(LinkedList lst, int toIndex)
{
	assert(this->head != nullptr);
	assert(lst.head != nullptr);
	assert(toIndex >= 0 && toIndex < lst.len);

	int counter = 0;
	Node* curr = lst.head;
	while (curr != nullptr && counter <= toIndex) {
		this->addBack(curr->data);
		curr = curr->next;
		counter++;
	}
}

void LinkedList::addValuesFrom(LinkedList lst, int fromIndex, int toIndex)
{
	assert(this->head != nullptr);
	assert(lst.head != nullptr);
	assert(fromIndex >= 0 && fromIndex < lst.len);
	assert(toIndex >= 0 && toIndex < lst.len);
	assert(fromIndex < toIndex);

	int counter = 0;
	Node* curr = lst.head;
	while (curr != nullptr && counter <= toIndex) {
		if (counter >= fromIndex) {
			this->addBack(curr->data);
		}
		curr = curr->next;
		counter++;
	}
}

LinkedList LinkedList::createSubList(int fromIndex, int toIndex)
{
	assert(head != nullptr);
	assert(fromIndex >= 0 && fromIndex < len);
	assert(toIndex >= 0 && toIndex < len);
	assert(toIndex > fromIndex);

	LinkedList* newLst = new LinkedList;

	Node* curr = this->head;
	int counter = 0;

	while (counter < fromIndex) {
		curr = curr->next;
		counter++;
	}
	while (counter <= toIndex) {
		newLst->addBack(curr->data);
		curr = curr->next;
		counter++;
	}

	return *newLst;
}

void LinkedList::splitList(Node* source, Node** front, Node** back)
{
	Node* ptr2 = source;
	Node* ptr1 = source->next;
	while (ptr1 != nullptr) {
		ptr1 = ptr1->next;
		if (ptr1 != nullptr) {
			ptr2 = ptr2->next;
			ptr1 = ptr1->next;
		}
	}
	*front = source;
	*back = ptr2->next;
	ptr2->next = nullptr;
}
void LinkedList::mergeSort(Node** thead)
{
	Node* head = *thead;
	Node* ptr1;
	Node* ptr2;

	// Base Case
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	// Splitting list
	splitList(head, &ptr1, &ptr2);

	// Recursively sorting two lists.
	mergeSort(&ptr1);
	mergeSort(&ptr2);

	// Sorted List.
	LinkedList* temp = mergeSortedList(ptr1, ptr2);
	*thead = temp->head;
}

LinkedList* LinkedList::mergeSortedList(Node* lst1, Node* lst2)
{
	return nullptr;
}
bool LinkedList::isDup(int value, std::vector<int> values)
{
	for (int i = 0; i < values.size(); i++) {
		if (value == values[i]) {
			return true;
		}
	}
	return false;
}
/*

// Merging two sorted lists.
node* MergeSortedList(node* lst1, node* lst2)
{
	node* result = NULL;

	// Base Cases
	if (lst1 == NULL)
		return (lst2);
	else if (lst2 == NULL)
		return (lst1);

	// recursively merging two lists
	if (lst1->data <= lst2->data) {
		result = lst1;
		result->next = MergeSortedList(lst1->next, lst2);
	}
	else {
		result = lst2;
		result->next = MergeSortedList(lst1, lst2->next);
	}
	return result;
}

// Splitting two into halves.
// If the size of the list is odd, then extra element goes in the first list.
void SplitList(node* source, node** front, node** back)
{
	node* ptr1;
	node* ptr2;
	ptr2 = source;
	ptr1 = source->next;

	// ptr1 is incrmented twice and ptr2 is icremented once.
	while (ptr1 != NULL) {
		ptr1 = ptr1->next;
		if (ptr1 != NULL) {
			ptr2 = ptr2->next;
			ptr1 = ptr1->next;
		}
	}

	// ptr2 is at the midpoint.
	*front = source;
	*back = ptr2->next;
	ptr2->next = NULL;
}


// Merge Sort
void MergeSort(node** thead)
{
	node* head = *thead;
	node* ptr1;
	node* ptr2;

  // Base Case
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	// Splitting list
	SplitList(head, &ptr1, &ptr2);

	// Recursively sorting two lists.
	MergeSort(&ptr1);
	MergeSort(&ptr2);

	// Sorted List.
	*thead = MergeSortedList(ptr1, ptr2);
}
*/