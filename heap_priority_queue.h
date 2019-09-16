#ifndef HEAP_PRIORITY_QUEUE_H
#define HEAP_PRIORITY_QUEUE_H

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"

template<typename T>
class HeapPriorityQueue : public AbstractPriorityQueue<T> {
public:
	HeapPriorityQueue();

	bool isEmpty();

	void add(const T& item);

	void remove();

	T peek();

private:
	DynamicArrayList<T> list;
	int heapsize;
};

#include "heap_priority_queue.txx"

#endif