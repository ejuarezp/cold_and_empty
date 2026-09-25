/*
 * linkedlist.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
	friend class ListIterator<T>;
};

template <class T>
Link<T>::Link(T val) {
	value = val;
	next = NULL;
}

template <class T>
Link<T>::Link(T val, Link* nxt) {
	value = val;
	next = nxt;
}

template <class T>
Link<T>::Link(const Link<T> &source) {
	value = source.value;
	next = source.next;
}

template <class T>
class List {
public:
	List();
	List(const List<T>&) ;
	~List();

	void addFirst(T) ;
	void add(T) ;
	T    getFirst() const ;
	T    removeFirst() ;
	int  length() const;
	T    get(int) const  ;
	bool contains(T) const;
	bool empty() const;
	void clear();
	std::string toString() const;
	void operator= (const List&) ;

	void addBefore(ListIterator<T>&, T)  ;
	void addAfter(ListIterator<T>&, T)  ;
	T    removeCurrent(ListIterator<T>&)  ;

	bool set(int, T) ;
	int  indexOf(T) const;
	int  lastIndexOf(T) const;
	T    remove(int) ;
	bool removeFirstOcurrence(T);
	bool removeLastOcurrence(T);

private:
	Link<T> *head;
	int 	size;

	friend class ListIterator<T>;
};

template <class T>
List<T>::List(){
	head = NULL;
	size = 0;
}

template <class T>
List<T>::~List() {
	clear();
	head = NULL;
	size = 0;
}

template <class T>
bool List<T>::empty() const {
	return size == 0;
	//alternativa: return head == NULL;
}

template <class T>
int List<T>::length() const {
	return size;
}

template <class T>
bool List<T>::contains(T val) const {
	return false;
}

template <class T>
T List<T>::getFirst() const  {
	return 0;
}

template <class T>
void List<T>::addFirst(T val)  {

	//Crear el nuevo nodo
	Link<T> * nuevo_nodo = new Link<T>(val);

	//Validar que se creó el nuevo nodo
	if (nuevo_nodo == NULL) {
		throw OutOfMemory();
	}

	//Si la lista está vacía
	if (empty()) {
		head = nuevo_nodo;
	//Si la lista no está vacía
	} else {
		nuevo_nodo->next = head;
		head = nuevo_nodo;
	}

	size++;
}

template <class T>
void List<T>::add(T val)  {
}

template <class T>
T List<T>::removeFirst()  {
	return 0;
}

template <class T>
T List<T>::get(int index) const   {
	return 0;
}

template <class T>
void List<T>::clear() {
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
List<T>::List(const List<T> &source)  {
}

template <class T>
void List<T>::operator=(const List<T> &source)  {
}

template <class T>
void List<T>::addBefore(ListIterator<T> &itr, T val)   {
}

template <class T>
void List<T>::addAfter(ListIterator<T> &itr, T val)   {
}

template <class T>
T List<T>::removeCurrent(ListIterator<T> &itr)   {
	return 0;
}

template <class T>
bool List<T>::set(int index, T val)  {
	return false;
}

template <class T>
int List<T>::indexOf(T val) const {
	return -1;
}

template <class T>
int List<T>::lastIndexOf(T val) const {
	return -1;
}

template <class T>
T List<T>::remove(int index)  {
	return 0;
}

template <class T>
bool List<T>::removeFirstOcurrence(T val) {
	return false;
}

template <class T>
bool List<T>::removeLastOcurrence(T val) {
	return false;
}

template <class T>
class ListIterator {
public:
	ListIterator(List<T>*);
	ListIterator(const ListIterator<T>&);

	bool begin();
	bool end();
	T&   operator() () ;
	bool operator++ ();
	void operator= (T) ;

private:
	Link<T> *current;
	Link<T> *previous;
	List<T> *theList;

	friend class List<T>;
};

template <class T>
ListIterator<T>::ListIterator(List<T> *aList) : theList(aList) {
	begin();
}

template <class T>
ListIterator<T>::ListIterator(const ListIterator<T> &source) : theList(source.theList) {
	begin();
}

template <class T>
bool ListIterator<T>::begin() {
	previous = 0;
	current = theList->head;
	return (current != 0);
}

template <class T>
T& ListIterator<T>::operator() ()  {
	if (current == 0) {
		throw NoSuchElement();
	}
	return current->value;
}

template <class T>
bool ListIterator<T>::end() {
	if (current == 0) {
		if (previous != 0) {
			current = previous->next;
		}
	}
	return (current == 0);
}

template <class T>
bool ListIterator<T>::operator++ () {
	if (current == 0) {
		if (previous == 0) {
			current = theList->head;
		} else {
			current = previous->next;
		}
	} else {
		previous = current;
		current = current->next;
	}
	return (current != 0);
}

template <class T>
void ListIterator<T>::operator= (T val)  {
	if (current == 0) {
		throw NoSuchElement();
	}
	current->value = val;
}

#endif /* LINKEDLIST_H_ */
