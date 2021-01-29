#pragma once
template<typename T>
class DynamicArray
{
public:
	DynamicArray();
	void addItem(T item);
	bool removeItem(T item);
	bool getItem(int index, T* item);
	int getLenght();

private:
	T* m_items;
	int m_lenght;
};

template<typename T>
int DynamicArray<T>::getLenght()
{
	return m_lenght;
}

template<typename T>
void DynamicArray<T>::addItem(T item)
{
	T** tempArray = new DynamicArray * [m_lenght + 1];

	for (int i = 0; i < m_lenght; i++)
	{
		tempArray[i] = m_items[i];
	}
	
	tempArray[m_lenght] = item;

	m_items = tempArray;
	m_lenght++;
}

template<typename T>
bool DynamicArray<T>::removeItem(T index)
{
	if (index < 0 || index >= m_lenght)
	{
		return false;
	}

	bool itemRemoved = false;

	T** tempArray = new DynamicArray * [m_lenght - 1];

	int j = 0;
	for (int i = 0; i < m_lenght; i++)
	{
		if (i != index)
		{
			tempArray[j] = m_items[i];
			j++;
		}
		else
		{
			delete m_items[i];
			itemRemoved = true;
		}
	}

	m_items = tempArray;
	m_lenght--;
	return itemRemoved;
}


template<typename T>
bool DynamicArray<T>::getItem(int index, T* item)
{

}
