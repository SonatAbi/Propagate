#ifndef _DYNAMIC_ARRAY_LIST_H_
#define _DYNAMIC_ARRAY_LIST_H_

#include "abstract_list.h"

template<typename T>
class DynamicArrayList :public AbstractList<T> {
public:
	DynamicArrayList();

	DynamicArrayList(DynamicArrayList<T> &x);

	DynamicArrayList & operator=(DynamicArrayList<T> &x);

	void swap(DynamicArrayList<T> &x, DynamicArrayList<T> &y);

	virtual ~DynamicArrayList();

	bool isEmpty();

	std::size_t getLength();

	void insert(std::size_t position, const T& item);

	void remove(std::size_t position);

	void clear();

	T getEntry(std::size_t position);

	void setEntry(std::size_t position, const T& newValue);

	void grow(T *&storage, std::size_t &size);
private:
	std::size_t capacity;
	std::size_t count;

	T *data;
};

#include "dynamic_array_list.txx"

#endif
