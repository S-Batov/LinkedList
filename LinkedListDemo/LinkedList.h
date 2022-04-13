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
--length() const
--isEmpty() const

--addToFront(int value)
--addToBack(int value)
--insertAt(int index, int value)

--dropHead()
--dropTail()
--deleteAt(int index)
--deleteFromTo(int index1, int index2)
--deleteLength(int index, int len_)
--deleteAll()

isInList(int value)
find value(int value)
find max()
find min()
valueAt(int index)
countRepetitions(int value)

sortMinMax()
sortMaxMin()

swapNodes(int index1, int index2)

appendList(LinkedList lst)
getSublist(int index1, int index2)
*/