#include "heap_priority_queue.h"

template<typename T>
HeapPriorityQueue<T>::HeapPriorityQueue()
{
	T x;
	list.insert(0, x);
	heapsize = 0;
}

template<typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
	if (heapsize == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
void HeapPriorityQueue<T>::add(const T & item)
{
	int i = heapsize + 1;
	int j = i >> 1;
	while ((j >= 1) && (list.getEntry(j) < item)) {
		if (i == heapsize + 1) {
			list.insert(i, list.getEntry(j));
		}
		else {
			list.setEntry(i, list.getEntry(j));
		}
	
		i = j;
		j = j >> 1;
	}
	if (i > heapsize) {
		list.insert(i, item);
	}
	else {
		list.setEntry(i, item);
	}
	heapsize = heapsize + 1;
}

template<typename T>
void HeapPriorityQueue<T>::remove()
{
	if (!isEmpty()) {
		list.setEntry(1, list.getEntry(heapsize));
		heapsize = heapsize - 1;
		int i = 1;
		int j = 2;
		while (j <= heapsize) {
			if ((j < heapsize) && (list.getEntry(j)<list.getEntry(j + 1))) {
				j = j + 1;
			}
			if (list.getEntry(i)<list.getEntry(j)) {
				T copy1 = list.getEntry(i);
				T copy2 = list.getEntry(j);
				list.setEntry(i, copy2);
				list.setEntry(j, copy1);
			}
			else {
				break;
			}
			i = j;
			j = j << 1;
		}
	}
	else {
		throw std::logic_error("Logic Error");
	}
}

template<typename T>
T HeapPriorityQueue<T>::peek()
{
	if (!isEmpty()) {
		return list.getEntry(1);
	}
	else {
		throw std::logic_error("Logic Error");
	}
}

