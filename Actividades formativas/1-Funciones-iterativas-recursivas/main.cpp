/*
 * main.cpp
 *
 *  Created on: 07/10/2020
 *      Author: bvaldesa
 */

#include <iostream>
#include "funciones.h"

using namespace std;

int main(int argc, char* argv[]) {
	Funciones fun;
	int i = 0;

	cout << "\n" << i++ <<".- respuesta esperada " << 36 << " programa " << fun.sumaIterativa(8) << "\n";
	cout << " " << ((36 == fun.sumaIterativa(8)) ? "success\n" : "fail\n");

	cout << "\n" << i++ <<".- respuesta esperada " << 36 << " programa " << fun.sumaRecursiva(8) << "\n";
	cout << " " << ((36 == fun.sumaRecursiva(8)) ? "success\n" : "fail\n");

	cout << "\n" << i++ <<".- respuesta esperada " << 36 << " programa " << fun.sumaDirecta(8) << "\n";
	cout << " " << ((36 == fun.sumaDirecta(8)) ? "success\n" : "fail\n");

	cout << "\n" << i++ <<".- respuesta esperada " << 0 << " programa " << fun.sumaIterativa(0) << "\n";
	cout << " " << ((0 == fun.sumaIterativa(0)) ? "success\n" : "fail\n");

	cout << "\n" << i++ <<".- respuesta esperada " << 0 << " programa " << fun.sumaRecursiva(0) << "\n";
	cout << " " << ((0 == fun.sumaRecursiva(0)) ? "success\n" : "fail\n");

	cout << "\n" << i++ <<".- respuesta esperada " << 0 << " programa " << fun.sumaDirecta(0) << "\n";
	cout << " " << ((0 == fun.sumaDirecta(0)) ? "success\n" : "fail\n");

	cout << "\n" << i++ <<".- respuesta esperada " << 1 << " programa " << fun.sumaIterativa(1) << "\n";
	cout << " " << ((1 == fun.sumaIterativa(1)) ? "success\n" : "fail\n");

	cout << "\n" << i++ <<".- respuesta esperada " << 1 << " programa " << fun.sumaRecursiva(1) << "\n";
	cout << " " << ((1 == fun.sumaRecursiva(1)) ? "success\n" : "fail\n");

	cout << "\n" << i++ <<".- respuesta esperada " << 1 << " programa " << fun.sumaDirecta(1) << "\n";
	cout << " " << ((1 == fun.sumaDirecta(1)) ? "success\n" : "fail\n");

	
}
