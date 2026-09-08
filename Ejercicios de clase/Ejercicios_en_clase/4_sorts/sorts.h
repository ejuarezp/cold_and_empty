/*
 * sorts.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm, edjuarezp
 */

#ifndef SORTS_H_
#define SORTS_H_

#include "exception.h"
#include <vector>
#include <list>

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
public:
	std::vector<T> bubbleSort(const std::vector<T>&);
	std::vector<T> selectionSort(const std::vector<T>&);
	std::vector<T> insertionSort(const std::vector<T>&);
	std::vector<T> shellSort(const std::vector<T>&);
	std::vector<T> mergeSort(const std::vector<T>&);

	std::vector<T> bucketSort(const std::vector<T>&);
	std::list<T>   mergeList(const std::list<T>&, const std::list<T>&);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
std::vector<T> Sorts<T>::bubbleSort(const std::vector<T> &source) {
	std::vector<T> v(source);

	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

template <class T>
std::vector<T> Sorts<T>::selectionSort(const std::vector<T> &source) {
	std::vector<T> v(source);

	for (int i = v.size() - 1; i >= 0; i--) {
		int pos_mayor = 0;
		for (int j = 0; j <= i; j++) {
			if (v[j] > v[pos_mayor]) {
				pos_mayor = j; 
			}
		}
		swap(v, pos_mayor, i);
	}

	return v;
}

template <class T>
std::vector<T> Sorts<T>::insertionSort(const std::vector<T> &source) {
	std::vector<T> v(source);

	for (int parte_ordenada = 1; parte_ordenada < v.size(); parte_ordenada++) {
		for (int ordenando = parte_ordenada; 
			ordenando > 0 && v[ordenando] < v[ordenando - 1]; 
			ordenando--) {
				if (v[ordenando] < v[ordenando - 1]) {
					swap(v, ordenando, ordenando - 1);
				}
		}
	}

	return v;
}

template <class T>
std::vector<T> Sorts<T>::shellSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	int intervalo_size = v.size() / 2;
	while (intervalo_size >= 1) {
		for (int i = v.size() - intervalo_size; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (v[j] > v[j + intervalo_size]) {
					swap(v, j, j + intervalo_size);
				}
			}
		}
		intervalo_size = intervalo_size / 2;
	}
	return v;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	
	int i_izquierda = low;
	int i_derecha = mid + 1;
	int i_ordenando = low;

	while (i_izquierda <= mid && i_derecha <= high) {
		if (A[i_izquierda] <= A[i_derecha]) {
			B[i_ordenando] = A[i_izquierda];
			i_izquierda++;
		} else {
			B[i_ordenando] = A[i_derecha];
			i_derecha++;
		}
		i_ordenando++;
	}

	while (i_izquierda <= mid) {
		B[i_ordenando] = A[i_izquierda];
		i_izquierda++;
		i_ordenando++;
	}

	while (i_derecha <= high) {
		B[i_ordenando] = A[i_derecha];
		i_derecha++;
		i_ordenando++;
	}

	copyArray(A, B, low, high);

}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	if (low < high) {

		int mitad = (low + high) / 2;

		//Ordenar la mitad izquierda del arreglo
		mergeSplit(A, B, low, mitad);

		//Ordenar la mitad derecha del arreglo
		mergeSplit(A, B, mitad + 1, high);

		//Mezclar en orden ambas mitades que ya están ordenadas
		mergeArray(A, B, low, mitad, high);
	}
}

template <class T>
std::vector<T> Sorts<T>::mergeSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());

	mergeSplit(v, tmp, 0, v.size() - 1);

	return v;
}

template <class T>
std::vector<T> Sorts<T>::bucketSort(const std::vector<T> &source) {
	typename  std::list<T>::iterator itr;
	std::vector<T> v;

	return v;
}

template <class T>
std::list<T> Sorts<T>::mergeList(const std::list<T> &lst1, const std::list<T> &lst2) {
	typename std::list<T>::const_iterator itr1, itr2;
	std::list<T> result;

	return result;
}

#endif /* SORTS_H_ */
