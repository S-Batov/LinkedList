#pragma once
#include <vector>

class LinkedList {	
public:
	class Node {
	public:
		Node(int dataVal);
		int data;
		Node* next;
	};
public:
	LinkedList();

	int length() const;
	bool isEmpty() const;
	bool isInList(int val) const;
	int countRepetitions(int value) const;
	int getMinValue() const;
	int getMaxValue() const;
	int getValueAt(int index) const;
	int getIndexOfMin() const;
	int getIndeOfMax() const;
	int getIndexOf(int value) const;
	
	void addFront(int dataVal);
	void addBack(int dataVal);
	void addAt(int index, int dataVal);

	void dropHead();
	void dropTail();
	void deleteAt(int index);
	void deleteFromTo(int fromIndex, int toIndex);
	void deleteLength(int index, int len);
	void deleteAll();

	void swapNodes(int index1, int index2);
	void reverse();
	void sort();
	void removeDuplicates();
	void removeValue(int value);

	void appendList(LinkedList lst);
	void addValuesFrom(LinkedList lst);
	void addValuesFrom(LinkedList lst, int toIndex);
	void addValuesFrom(LinkedList lst, int fromIndex, int toIndex);
	LinkedList createSubList(int fromIndex, int toIndex);

private:
	void splitList(Node* source, Node** front, Node** back);
	void mergeSort(Node** thead);
	LinkedList* mergeSortedList(Node* lst1, Node* lst2);

	bool isDup(int value, std::vector<int> values);

private:
	Node* head;
	int len;
};
