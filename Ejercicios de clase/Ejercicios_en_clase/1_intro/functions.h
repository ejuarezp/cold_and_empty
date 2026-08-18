/*
 * intro.h
 *  Created on: 10/09/2015
 *      Author: pperezm
 *  Mofified on: 17/08/2026
 *      Author: edjuarezp
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

unsigned long fact(int n) { // O(n)
	if (n <= 0) { // O(1)
		return 0; // O(1)
	}

	unsigned long result = 1; // O(1)
	for (int i = 1; i <= n; i++) { // O(n)
		result = result * i; // O(1)
	}
	return result; // O(1)
}

bool isPrime(int n) { // O(n)
	if (n <= 1) { // O(1)
		return false; // O(1)
	}
	for (int i = 2; i < n; i++) { // O(n)
		if (n % i == 0) { // O(1)
			return false; // O(1)
		}
	}
	return true; // O(1)
}

unsigned long sum(int arr[], int size) { // O(n)
	unsigned long result = 0; // O(1)
	for (int i = 0; i < size; i++) { // O(n)
		result = result + arr[i]; // O(1)
	}
	return result; // O(1)
}

void reverse(int arr[], int size) { // O(n)
	int fin = size - 1; // O(1)
	for (int inicio = 0; inicio < size / 2; inicio++) { // O(n)
		int temp = arr[inicio]; // O(1)
		arr[inicio] = arr[fin]; // O(1)
		arr[fin] = temp; // O(1)
		fin--; // O(1)
	}
}

#endif /* FUNCTIONS_H_ */
