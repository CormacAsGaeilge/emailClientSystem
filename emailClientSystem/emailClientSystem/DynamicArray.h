#pragma once

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
			cout << pArray[i] << ",";
		cout << pArray[length - 1] << endl;
	};
	int Count();

private:

	void Grow();

	T *pArray;
	int length;
	int count;
};

/*
In this example we simply move the code from the CPP to the template class.
Unlike with TemplatePair where we used an INL include.
See the comment block at the top of Main for more on this.
*/

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

	//make new array 150% original size
	T* tempPArray = new T[newLength];

	//copy contents
	for (int i = 0; i < length; i++)
	{
		tempPArray[i] = pArray[i];
	}

	//free RAM from old array
	delete[] DynamicArray::pArray;

	//make old pointer, now point to the new array
	DynamicArray::pArray = tempPArray;

	//reset tempPArray address since its no longer in use
	tempPArray = nullptr;

	//remember to set the new length
	length = newLength;

	//blank any new spaces after the data
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

