#pragma once

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
	void deleteFromTo(int index1, int index2);
	void deleteLength(int index, int len);
	void deleteAll();

private:
	Node* head;
	int len;
};

/*
sortMinMax()
sortMaxMin()

swapNodes(int index1, int index2)

appendList(LinkedList lst)
getSublist(int index1, int index2)
*/