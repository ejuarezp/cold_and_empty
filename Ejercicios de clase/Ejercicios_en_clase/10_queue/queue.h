/*
 * queue.h
 *
 *  Created on: 09/10/2015
 *      Author: clase
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "exception.h"
#include <list>
#include <string>
#include <sstream>
#include <iostream>

template <class T>
class Queue {
public:
	virtual void enqueue(T) = 0;
	virtual void dequeue()  = 0 ;
	virtual T front() const  = 0 ;
	virtual bool empty() const = 0;
	virtual void clear() = 0;
	virtual std::string toString() const = 0;
};

template <class T>
class QueueVector : public Queue<T> {
private:
	T *data;
	int head, tail, size, counter;

public:
	QueueVector(int) ;
	~QueueVector();
	void enqueue(T) ;
	void dequeue() ;
	T front() const ;
	bool empty() const;
	bool full() const;
	void clear();
	std::string toString() const;
};

template <class T>
QueueVector<T>::QueueVector(int sze)  {
	size = sze;
	data = new T[size];
	if (data == NULL) {
		throw OutOfMemory();
	}

	head = 0;
	tail = 0;  
	counter = 0;
}

template <class T>
QueueVector<T>::~QueueVector() {
	delete data;
	data = NULL;
	size = 0;
	head = 0;
	tail = 0;
	counter = 0;
}

template <class T>
bool QueueVector<T>::empty() const {
    return counter == 0;
}

template <class T>
bool QueueVector<T>::full() const {
    return counter == size;
}

template <class T>
void QueueVector<T>::enqueue(T val)  {
    if (full()) {
		throw Overflow();
	}

	data[tail] = val;
	tail = (tail + 1) % size;
	counter++;
}

template <class T>
T QueueVector<T>::front() const  {
	if (empty()) {
		throw NoSuchElement();
	}
	return data[head];
}

template <class T>
void QueueVector<T>::dequeue()  {
	if (empty()) {
		throw NoSuchElement();
	}
    
	head = (head + 1) % size;
	counter--;
}

template <class T>
void QueueVector<T>::clear() {
	head = 0;
	tail = 0;
	counter = 0;
}

template <class T>
std::string QueueVector<T>::toString() const {
	std::stringstream aux;
	int i;

	aux << "[";
	if (!empty()) {
		i = head;
		aux << data[i];
		i = (i + 1) % size;
		while (i != tail) {
			aux << ", " << data[i];
			i = (i + 1) % size;
		}
	}
	aux << "]";
	return aux.str();
}

template <class T>
class QueueList : public Queue<T> {
private:
	std::list<T> data;

public:
	void enqueue(T);
	void dequeue() ;
	T front() const ;
	bool empty() const;
	void clear();
	std::string toString() const;
};

template <class T>
void QueueList<T>::enqueue(T val) {
    data.push_back(val);
}

template <class T>
T QueueList<T>::front() const  {
	if (empty()) {
		throw NoSuchElement();
	}
	return data.front();
}

template <class T>
void QueueList<T>::dequeue()  {
	if (empty()) {
		throw NoSuchElement();
	}
	data.pop_front();
}

template <class T>
bool QueueList<T>::empty() const {
    return data.empty();
}

template <class T>
void QueueList<T>::clear() {
    data.clear();
}

template <class T>
std::string QueueList<T>::toString() const {
	std::stringstream aux;
	typename std::list<T>::const_iterator itr = data.begin();

	aux << "[";
	if (!data.empty()) {
		aux << (*itr);
		itr++;
		while (itr != data.end()) {
			aux << ", " << (*itr);
			itr++;
		}
	}
	aux << "]";
	return aux.str();
}

#endif /* QUEUE_H_ */
