/*
 * recursion.h
 *
 *  Created on: 10/09/2015
 *      Author: pperezm
 */

#ifndef BUSQUEDAS_H_
#define BUSQUEDAS_H_

#include "exception.h"
#include <iostream>


int bs_seq(int arr[], int size, int val) { // O(log(n))
	int inicio = 0; // O(1)
	int fin = size - 1; // O(1)

	while (inicio < fin) { // O(log(n))
		int mitad = (inicio + fin) / 2; // O(1)
		
		if (arr[mitad] == val) { // O(1)
			return mitad; // O(1)
		}

		if (val < arr[mitad]) { // O(1)
			fin = mitad - 1; // O(1)
		} else {
			inicio = mitad + 1; // O(1)
		}
	}

	return (inicio + fin) / 2; // O(1)
}

// Búsqueda binaria recursiva
int bs_aux(int arr[], int low, int high, int val) { // O (log (n))
	int mitad = (low + high) / 2; // O (1)
	
	if (val == arr[mitad]) {  // O (1)
		return mitad;	 // O (1)
	}

	if (low < high) { // O (log (n))
		if (val < arr[mitad]) { // O (log (n))
			return bs_aux(arr, low, mitad - 1, val);  // O (log (n))
		} 
		return bs_aux(arr, mitad + 1, high, val);  // O (log (n))
	}

	// Si no se encontró
	return mitad;  // O (1)

}

// Función contenedora para invocar la función recursiva.
int bs_rec(int arr[], int size, int val) {
	return bs_aux(arr, 0, size - 1, val);
}

#endif
