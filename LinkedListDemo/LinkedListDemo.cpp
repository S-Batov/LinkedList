#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList test;

	test.addBack(4);
	test.addBack(3);
	test.addBack(2);
	test.addBack(1);
	test.addBack(8);

	int i = test.getIndexOf(0);
	bool b = test.isInList(4);

	return 0;
}
