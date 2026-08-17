/*
 * intro.h
 *  Created on: 10/09/2015
 *      Author: pperezm
 *  Mofified on: 17/08/2026
 *      Author: edjuarezp
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

unsigned long fact(int n) {
	if (n <= 0) {
		return 0;
	}

	unsigned long result = 1;
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	return result;
}

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

unsigned long sum(int arr[], int size) {
	unsigned long result = 0;
	for (int i = 0; i < size; i++) {
		result = result + arr[i];
	}
	return result;
}

void reverse(int arr[], int size) {
	int fin = size - 1;
	for (int inicio = 0; inicio < size / 2; inicio++) {
		int temp = arr[inicio];
		arr[inicio] = arr[fin];
		arr[fin] = temp;
		fin--;
	}
}

#endif /* FUNCTIONS_H_ */
