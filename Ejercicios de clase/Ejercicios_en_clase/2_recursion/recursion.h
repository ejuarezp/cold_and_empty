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

long sum_seq(int n) {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = result + i;
	}
	return result;
}

long sum_rec(int n) {
	if (n == 0) {
		return 0;
	}
	return n + sum_rec(n - 1);
}

long fact_seq(int n) {
	int result = 1;
	for (int i = 2; i <= n; i++) {
		result = result * i;
	}
	return result;
}

long fact_rec(int n) {
	if (n == 0) {
		return 1;
	}
	return n * fact_rec(n - 1);
}

long fib_seq(int n) {
	int resultado = 0;
	int anterior_1 = 1;
	int anterior_2 = 0;
	for (int i = 1; i < n; i++) {
		resultado = anterior_1 + anterior_2;
		anterior_2 = anterior_1;
		anterior_1 = resultado;
	}
	return resultado;
}

long fib_rec(int n) {
	if (n == 0) {
		return 0;
	} 
	if (n == 1) {
		return 1;
	}
	return fib_rec(n-2) + fib_rec(n-1);
}

long gcd_seq(long a, long b) {
	while (b != 0) {
		long aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

long gcd_rec(long a, long b) {
	if (b == 0) {
		return a;
	}
	return gcd_rec(b, a % b);
}

bool find_seq(int arr[], int size, int val) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == val) {
			return true;
		}
	}
	return false;
}

bool find_rec(int arr[], int low, int high, int val) {
	if (arr[low] == val) {
		return true;
	}

	if (low > high) {
		return false;
	}
	
	return find_rec(arr, low + 1, high, val);
}

int max_seq(int arr[], int size) {
	return 0;
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
