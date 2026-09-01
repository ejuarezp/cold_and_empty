/*
 * recursion.h
 *
 *  Created on: 10/09/2015
 *      Author: pperezm, edjuarezp
 */

#ifndef BUSQUEDAS_H_
#define BUSQUEDAS_H_

#include "exception.h"
#include <iostream>


int bs_seq(int arr[], int size, int val) {
	
	int inicio = 0;
	int fin = size - 1;
	int mitad = (inicio + fin) / 2;
	while (inicio < fin) {
		if (arr[mitad] == val) {
			return mitad;
		}

		if (val < arr[mitad]) {
			fin = mitad - 1;
		} else {
			inicio = mitad + 1;
		}
		mitad = (inicio + fin) / 2;
	}

	return mitad;
}

int bs_aux(int arr[], int low, int high, int val) {
	int mitad = (low + high) / 2;

	if (low > high) {
		return low;
	} else	if (arr[mitad] == val) {
		return mitad;
	} else if (val < arr[mitad]) {
		return bs_aux(arr, low, mitad - 1, val);
	} else {
		return bs_aux(arr, mitad + 1, high, val);
	}
}

int bs_rec(int arr[], int size, int val) {
	return bs_aux(arr, 0, size - 1, val);
}
#endif
