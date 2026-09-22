/*
 * rational.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm, edjuarezp
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "exception.h"
#include <string>
#include <sstream>
#include <iostream>

class Rational {
private:
	int numerator;
	int denominator;

	void normalize();

public:
	Rational();
	Rational(int);
	Rational(int, int);
	Rational(const Rational&);

	int getNumerator() const;
	int getDenominator() const;
	std::string toString() const;

	void operator=   (const Rational&);
	void operator+=  (const Rational&);

	operator double () const;
};

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int num){
    numerator = num;
    denominator = 1;
}

Rational::Rational(int num, int dem){
    if (dem == 0) {
        throw RangeError();
    } else {
        numerator = num;
        denominator = dem;
    }

	normalize();

	if (denominator < 0) {
		numerator = numerator * -1;
		denominator = denominator * -1;
	}
}

int Rational::getNumerator() const {
	return numerator;
}

int Rational::getDenominator() const {
	return denominator;
}

std::string Rational::toString() const {
	std::stringstream aux;

	aux << numerator << "/" << denominator;
	return aux.str();
}

void Rational::operator= (const Rational &right) {
	numerator = right.getNumerator();
	denominator = right.getDenominator();
}

void Rational::operator+= (const Rational &right) {
	numerator = denominator * right.getNumerator() + right.getDenominator() * numerator;
	denominator = denominator * right.getDenominator();
	normalize();
}

Rational::operator double () const {
	return (double) numerator / (double) denominator;
}

int gcd(int a, int b) {
	int aux;

	while (b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

void Rational::normalize() {
	int valor_gcd = gcd(numerator, denominator);
	numerator = numerator / valor_gcd;
	denominator = denominator / valor_gcd;
}

Rational operator+ (const Rational &left, const Rational &right) {
	return Rational(
		left.getDenominator() * right.getNumerator() + right.getDenominator() * left.getNumerator(),
		left.getDenominator() * right.getDenominator()
	);
}

Rational operator- (const Rational &left, const Rational &right) {
	return Rational(
		right.getDenominator() * left.getNumerator() - left.getDenominator() * right.getNumerator(),
		left.getDenominator() * right.getDenominator()
	);
}

Rational operator- (const Rational &right) {
	return Rational(-right.getNumerator(), right.getDenominator());
}

bool operator== (const Rational &left, const Rational &right) {
	return (double) left == (double) right;
}

bool operator<  (const Rational &left, const Rational &right) {
	return (double) left < (double) right;
}

#endif /* RATIONAL_H_ */
