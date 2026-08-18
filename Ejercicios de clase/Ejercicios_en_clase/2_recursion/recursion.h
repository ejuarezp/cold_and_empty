/*
 * recursion.h
 *
 *  Created on: 10/09/2015
 *      Author: pperezm, edjuarezp
 */

#ifndef RECURSION_H_
#define RECURSION_H_

#include "exception.h"
#include <iostream>

long sum_seq(int n) { // O(n)
	long result = 0; // O(1)
	for (int i = 1; i <= n; i++) { // O(n)
		result = result + i; // O(1)
	}
	return result; // O(1)
}

long sum_rec(int n) { // O(n)
	if (n <= 1) { // O(1)
		return 1; // O(1)
	}
	return n + sum_rec(n - 1); // O(n)
}

long fact_seq(int n) { // O(n)
	long result = 1; // O(1)
	for (int i = 1; i <= n; i++) { // O(n)
		result = result * i; // O(1)
	}
	return result; // O(1)
}

long fact_rec(int n) { // O(n)
	if (n <= 1) { // O(1)
		return 1; // O(1)
	}
	return n * fact_rec(n - 1); // O(n)
}

long fib_seq(int n) { // O(n)
	if (n == 1) { // O(1)
		return 1; // O(1)
	}
	if (n <= 0) { // O(1)
		return 0; // O(1)
	}

	long result = 0; // O(1)
	long ant_1 = 1; // O(1)
	long ant_2 = 0; // O(1)
	for(int i = 2; i <= n; i++) { // O(n)
		result = ant_1 + ant_2; // O(1)
		ant_2 = ant_1; // O(1)
		ant_1 = result; // O(1)
	}
	return result; // O(1)
}

long fib_rec(int n) {
	if (n == 0) { // O(1)
		return 0; // O(1)
	}
	if (n == 1) { // O(1)
		return 1; // O(1)
	}
	return fib_rec(n - 2) + fib_rec(n - 1); // O(2exp(n))
}

long gcd_seq(long a, long b) { // O(log(n))
	while (b != 0) { // O(log(n))
		long aux = b; // O(1)
		b = a % b; // O(1)
		a = aux; // O(1)
	}
	return a; // O(1)
}

long gcd_rec(long a, long b) {
	if (b == 0) { // O(1)
		return a; // O(1)
	}
	return gcd_rec(b, a % b); // O(log(n))
}

// Mejor caso: O(1)
// Caso promedio: O(n)
// Peor caso: O(n)
bool find_seq(int arr[], int size, int val) { // O(n)
	for (int i = 0; i < size; i++) { // O(n)
		if (arr[i] == val) { // O(1)
			return true; // O(1)
		}
	}
	return false; // O(1)
}

bool find_rec(int arr[], int low, int high, int val) { // O(n)
	if (arr[low] == val || arr[high] == val) { // O(1)
		return true; // O(1)
	}
	
	if (low > high) { // O(1)
		return false; // O(1)
	}
	
	return find_rec(arr, low + 1, high - 1, val); // O(n)
}

int max_seq(int arr[], int size) { // O(n)
	int max = arr[0]; // O(1)
	for (int i = 0; i < size; i++) { // O(n)
		if (arr[i] > max) { // O(1)
			max = arr[i]; // O(1)
		}
	}

	return max; // O(1)
}

int max_rec(int arr[], int low, int high) {
	
	
	return 0;
}

int unimodal_seq(int arr[], int size) {
	
	return 0;
}

int unimodal_rec(int arr[], int low, int high) {
	
	return 0;
}

int unimodal_rec(int arr[], int size) {
	return 0;
}

#endif /* RECURSION_H_ */
