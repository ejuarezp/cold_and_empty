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
	long result = 0;
	for (int i = 1; i <= n; i++) {
		result = result + i;
	}
	return result;
}

long sum_rec(int n) {
	if (n <= 1) {
		return 1;
	}
	return n + sum_rec(n - 1);
}

long fact_seq(int n) {
	long result = 1;
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	return result;
}

long fact_rec(int n) {
	if (n <= 1) {
		return 1;
	}
	return n * fact_rec(n - 1);
}

long fib_seq(int n) {
	if (n == 1) {
		return 1;
	}
	if (n <= 0) {
		return 0;
	}

	long result = 0;
	long ant_1 = 1;
	long ant_2 = 0;
	for(int i = 2; i <= n; i++) {
		result = ant_1 + ant_2;
		ant_2 = ant_1;
		ant_1 = result;
	}
	return result;
}

long fib_rec(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return fib_rec(n - 2) + fib_rec(n - 1);
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
	
	return 0;
}

bool find_rec(int arr[], int low, int high, int val) {
	
	
	return 0;
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
