#include "dynamic_array_list.h"
#include <cmath>

template<typename T>
DynamicArrayList<T>::DynamicArrayList() :capacity(50), count(0) {
	data = new T[capacity];
}

template<typename T>
DynamicArrayList<T>::DynamicArrayList(DynamicArrayList<T>& x)
{
	count = x.count;
	capacity = x.capacity;
	data = capacity ? new T[capacity] : nullptr;
	std::copy(x.data, x.data + x.capacity, data);
}

template<typename T>
DynamicArrayList<T> & DynamicArrayList<T>::operator=(DynamicArrayList<T>& x)
{
	DynamicArrayList<T> copy(x);
	swap(*this, copy);
	return *this;
}

template<typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& x, DynamicArrayList<T>& y)
{
	std::swap(x.count, y.count);
	std::swap(x.capacity, y.capacity);
	std::swap(x.data, y.data);
}

template<typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
	delete[] data;
}

template<typename T>
bool DynamicArrayList<T>::isEmpty()
{
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
std::size_t DynamicArrayList<T>::getLength()
{
	return count;
}

template<typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T & item)
{
	if (capacity == count) {
		grow(data, capacity);
	}

	if (position == count) {
		data[position] = item;
		count++;
	}
	else if (position < count) {
		for (size_t i = count; i > position; i--) {
			data[i] = data[i - 1];
		}
		data[position] = item;
		count++;
	}
	else {
		throw std::range_error("Range Error");
	}
}

template<typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
	if (position < count) {
		for (size_t i = position; i < count - 1; i++) {
			data[i] = data[i + 1];
		}
		count--;
	}
	else {
		throw std::range_error("Range Error");
	}
}

template<typename T>
void DynamicArrayList<T>::clear()
{
	delete[] data;
	count = 0;
	data = new T[capacity];
}

template<typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
	if (position < count) {
		T copy = data[position];
		return copy;
	}
	else {
		throw std::range_error("Range Error");
	}
}

template<typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T & newValue)
{
	if (position < count) {
		data[position] = newValue;
	}
	else {
		throw std::range_error("Range Error");
	}
}

template<typename T>
void DynamicArrayList<T>::grow(T *& storage, std::size_t & size)
{
	T *temp = storage;
	storage = new T[size * 2];
	for (size_t i = 0; i<size; i++)
		storage[i] = temp[i];
	delete[] temp;
	temp = nullptr;
	size = size * 2;
}
