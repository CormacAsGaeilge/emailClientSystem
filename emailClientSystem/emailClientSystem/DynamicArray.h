#pragma once
#include <stdexcept>
#include <iostream>
template <typename T>
class DynamicArray
{
public:
	DynamicArray(int length);
	~DynamicArray();

	void Initialize();
	T& operator[](const int index);
	void Add(const T data, int index);
	void Remove(int index);
	void AddLast(const T data);
	void Print() {
		for (int i = 0; i < length - 1; i++)
			std::cout << pArray[i] << ",";
		std::cout << pArray[length - 1] << std::endl;
	};
	int Count();

private:

	void Grow();

	T *pArray;
	int length;
	int count;
};

template <typename T>
DynamicArray<T>::DynamicArray(int length)
{
	DynamicArray::length = (length > 0) ? length : 10;
	pArray = new T[length];
}

template <typename T>
void DynamicArray<T>::Initialize()
{
	for (int i = 0; i < length; i++)
		pArray[i] = T();
}

template <typename T>
void DynamicArray<T>::Grow()
{
	int newLength = static_cast<int>(round(length * 1.5));
	T* tempPArray = new T[newLength];
	for (int i = 0; i < length; i++)
	{
		tempPArray[i] = pArray[i];
	}
	delete[] DynamicArray::pArray;
	DynamicArray::pArray = tempPArray;
	tempPArray = nullptr;
	length = newLength;
	for (int i = count; i < length; i++)
		pArray[i] = T();
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] pArray;
	pArray = nullptr;
}

template <class T>
T& DynamicArray<T>::operator[](const int index)
{
	//NEEDS TO BE FIXED
	/*if (index < 0 || index > length - 1)
		throw out_of_range("Array index of of bounds exception!");
*/
	return pArray[index];
}

template <typename T>
void DynamicArray<T>::Add(const T data, int index)
{
	if (count < length)
	{
		pArray[index] = data;
		count++;
	}
	else
	{
		Grow();
		Add(data, index);
	}
}

template<typename T>
void DynamicArray<T>::Remove(int index)
{
	this[index] = T();
	count--;
}

template <typename T>
void DynamicArray<T>::AddLast(const T data)
{
	Add(data, length - 1);
}

template<typename T>
int DynamicArray<T>::Count()
{
	return count;
}

