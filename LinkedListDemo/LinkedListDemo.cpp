#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList test;

	test.addBack(4);
	test.addBack(3);
	test.addBack(2);
	test.addBack(1);
	test.addBack(0);


	int i = test.length();
	return 0;
}
