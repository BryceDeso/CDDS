#pragma once
#include "iostream"
template<typename T>
class DynamicArray
{
public:
	DynamicArray<T>();
	~DynamicArray<T>();

	void addItem(T item);
	bool removeItem(T item);
	bool getItem(int index, T* item);
	int getLength();
	void bubbleSort();
	void print();
private:
	T* m_items;
	int m_lenght;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_items = nullptr;
	m_lenght = 0;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] m_items;

}

//Adds item to an array
template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	T* tempArray = new T[getLength() + 1];

	for (int i = 0; i < getLength(); i++)
	{
		tempArray[i] = m_items[i];
	}

	tempArray[getLength()] = item;

	m_items = tempArray;
	m_lenght++;
}

//Removes item from an array
template<typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
	bool itemRemoved = false;

	T* tempArray = new T[getLength() - 1];

	int j = 0;
	for (int i = 0; i < getLength(); i++)
	{
		if (item != m_items[i])
		{
			tempArray[j] = m_items[i];
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	}

	m_items = tempArray;
	m_lenght--;
	return itemRemoved;
}

//gets and item from an array
template<typename T>
inline bool DynamicArray<T>::getItem(int index, T* item)
{
	if (index < 0 || index >= m_lenght)
	{
		return false;
	}

	item = &m_items[index];

	return true;
}

//Gets the length of an array
template<typename T>
inline int DynamicArray<T>::getLength()
{
	return m_lenght;
}

template<typename T>
inline void DynamicArray<T>::bubbleSort()
{
	for (int i = 0; i < m_lenght; i++)
	{
		for (int j = m_lenght - 1; j > i; j--)
		{
			if (m_items[j] < m_items[j-1])
			{
				T temp = m_items[j];
				m_items[j] = m_items[j - 1];
				m_items[j - 1] = temp;
			}
		}
	}
}

template<typename T>
inline void DynamicArray<T>::print()
{
	for (int i = 0; i < getLength(); i++)
	{
		std::cout << m_items[i] << std::endl;
	}
}