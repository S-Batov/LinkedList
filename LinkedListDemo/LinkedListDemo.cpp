#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList test;

	test.addBack(0);
	test.addBack(1);
	test.addBack(2);
	test.addBack(3);
	test.addBack(4);
	test.addBack(5);
	test.addBack(4);
	test.addBack(5);

	LinkedList test2 = test.createSubList(0, 5);

	test.removeDuplicates();

	bool b = test.isInList(0);

	return 0;
}
