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
	test.addBack(6);
	test.addBack(7);
	test.deleteFromTo(0, 1);

	int i = 0;
	return 0;
}
