/*
 * hash.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef HASH_H_
#define HASH_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class Key, class Value>
class HashTable {
private:
	unsigned int (*func) (const Key);
	unsigned int size;
	unsigned int count;

	Key *keys;
	Key initialValue;
	Value *values;

	long indexOf(const Key) const;

public:
	HashTable(unsigned int, Key, unsigned int (*f) (const Key)) ;
	~HashTable();
	bool full() const;
	bool put(Key, Value);
	bool contains(const Key) const;
	Value get(const Key) ;
	void clear();
	std::string toString() const;
};

template <class Key, class Value>
HashTable<Key, Value>::HashTable(unsigned int sze, Key init, unsigned int (*f) (const Key))  {
	func = f;
	size = sze;
	count = 0;

	keys = new Key[size];
	if (keys == NULL) {
		throw OutOfMemory();
	}

	initialValue = init;
	
	values = new Value[size];
	if (values == NULL) {
		throw OutOfMemory();
	}

	for (int i = 0; i < size; i++) {
		keys[i] = initialValue;
	}

	for (int i = 0; i < size; i++) {
		values[i] = 0;
	}
}

template <class Key, class Value>
HashTable<Key, Value>::~HashTable() {
	func = NULL;
	size = 0;
	count = 0;

	delete [] keys;
	keys = NULL;
	delete [] values;
	values = NULL;
}

template <class Key, class Value>
bool HashTable<Key, Value>::full() const {
	return count == size;
}

template <class Key, class Value>
long HashTable<Key, Value>::indexOf(const Key k) const {
	//Utilizar la función de hash para calcular el valor de hash
	int valor_hash = func(k);
	//Sacar el módulo con el tamaño de la tabla de hash
	valor_hash = valor_hash % size;
	//Si la localidad de valor_hash es igal a k, devolver el valor hash
	if (keys[valor_hash] == k) {
		return valor_hash;
	}

	
	if (keys[valor_hash] == initialValue) {
		return -1;
	}

	//Si no es igual, buscar el índice por sondeo lineal
	//Si se encuentra un indice vacío en el sondeo, devolver -1
	for(int i = 0; i < size; i++) {
		if (keys[valor_hash] == k) {
			return i;
		}
		if (keys[valor_hash] == initialValue) {
			return -1;
		}
		valor_hash = (valor_hash + 1) % size;
	}

	return -1;
}

template <class Key, class Value>
bool HashTable<Key, Value>::put(Key k, Value v) {
	if (contains(k)) {
		values[indexOf(k)] = v;
		return true;
	}

	if (full()) {
		throw Overflow();
	}

	int valor_hash = func(k) % size;
	if (keys[valor_hash] == initialValue) {
		keys[valor_hash] = k;
		values[valor_hash] = v;
		count++;
		return true;
	}

	//Sondeo lineal
	for(int i = 0; i < size; i++) {
		if (keys[valor_hash] == initialValue) {
			keys[valor_hash] = k;
			values[valor_hash] = v;
			count++;
			return true;
		}
		valor_hash = (valor_hash + 1) % size;
	}

	return false;
}

template <class Key, class Value>
bool HashTable<Key, Value>::contains(const Key k) const {
	int index = indexOf(k);
	if (index == -1) {
		return false;
	} else {
		return true;
	}
}

template <class Key, class Value>
Value HashTable<Key, Value>::get(const Key k)  {
	if (contains(k)) {
		return values[indexOf(k)];
	} else {
		throw NoSuchElement();
	}
	
}

template <class Key, class Value>
void HashTable<Key, Value>::clear() {
	for (int i = 0; i < size; i++) {
		keys[i] = initialValue;
	}
	count = 0;
}

template <class Key, class Value>
std::string HashTable<Key, Value>::toString() const {
	std::stringstream aux;

	for (unsigned int i = 0; i < size; i++) {
		aux << "[ " << i << ", " << keys[i] << ", " << values[i] << "]\n";
	}
	return aux.str();
}
#endif /* HASH_H_ */
