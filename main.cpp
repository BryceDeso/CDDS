#pragma once
#include <iostream>
#include "ShopKeep.h"

template<typename T>
void bubbleSort(T array[], int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		for (int j = lenght - 1; j > i; j--)
		{
			if (array[j] < array[i])
			{
				T temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}
}

template<typename T>
T add(T lhs, T rhs)
{
	return lhs + rhs;
}

int main()
{
	int testArray[5] = { 2, 4, 1, 5, 3 };

	std::cout << "Before sort: ";
	std::cout << testArray[0] << ", " << testArray[1] << ", " << testArray[2] << ", " << testArray[3] << ", " << testArray[4] << std::endl;

	bubbleSort(testArray, 5);

	std::cout << "After sort: ";
	std::cout << testArray[0] << ", " << testArray[1] << ", " << testArray[2] << ", " << testArray[3] << ", " << testArray[4] << std::endl;

	ShopKeep<int, 5> potionSeller = ShopKeep<int, 5>();

	return 0;
}