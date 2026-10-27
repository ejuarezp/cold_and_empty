/*
 * heap.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

template <class T>
class Heap {
private:
	T *data;
	unsigned int size;
	unsigned int count;

	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);

public:
	Heap(unsigned int) ;
	~Heap();
	bool empty() const;
	bool full() const;
	void add(T) ;
	T remove() ;
	void clear();
	std::string toString() const;
};

template <class T>
Heap<T>::Heap(unsigned int sze)  {
	data = new T[sze];
	if (data == NULL) {
		throw OutOfMemory();
	}
	size = sze;
	count = 0;
}

template <class T>
Heap<T>::~Heap() {
	delete data;
	data = NULL;
	size = 0;
	count = 0;
}

template <class T>
bool Heap<T>::empty() const {
	return count == 0;
}

template <class T>
bool Heap<T>::full() const {
	return count == size;
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos - 1) / 2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return 2 * pos + 1;
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return 2 * pos + 2;
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
	if (pos > 0) {
		if (data[pos] < data[parent(pos)]) {
			swap(pos, parent(pos));
			heapify(parent(pos));
		}
	}
}

template <class T>
void Heap<T>::add(T val)  {
	if (full()) {
		throw Overflow();
	}
	data[count] = val;
	heapify(count);
	count++;	
}

template <class T>
T Heap<T>::remove()  {
	if (count == 0) {
		throw NoSuchElement();
	}
	T aux = data[0];
	count--;
	data[0] = data[count];
	
	int pos = 0;
	bool continuar = 1;
	while(left(pos) < count && continuar) {
		continuar = 0;
		if (data[pos] > data[left(pos)]) {
			swap(pos, left(pos));
			pos = left(pos);
			continuar = 1;
		}
		if (right(pos) < count) {
			if (data[pos] > data[right(pos)]) {
				swap(pos, right(pos));
				pos = right(pos);
				continuar = 1;
			}
		}
	}
	
	return aux;
}

template <class T>
void Heap<T>::clear() {
	count = 0;
}


template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;

	aux << "[";
	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
		aux << data[i];
	}
	aux << "]";
	return aux.str();
}
#endif /* HASH_H_ */
