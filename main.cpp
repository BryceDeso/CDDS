#pragma once
#include "ShopKeep.h"
#include "DynamicArray.h"

template<typename T>
T add(T lhs, T rhs)
{
	return lhs + rhs;
}

int main()
{
	DynamicArray<int> test = DynamicArray<int>();

	test.addItem(3);
	test.addItem(4);
	test.addItem(2);
	test.addItem(5);
	test.addItem(1);
	test.addItem(9);
	test.addItem(7);
	test.addItem(10);
	test.addItem(6);
	test.addItem(8);
	test.addItem(13);
	test.addItem(15);
	test.addItem(11);
	test.addItem(12);
	test.addItem(14);

	test.bubbleSort();

	test.print();

	return 0;
}