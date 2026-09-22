/*
 * main.cpp
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */
#include <iostream>
#include <cstring>
#include "unit.h"
#include "rational.h"

class RationalTest : public UnitTest {
public:
	void runTest() {
		Rational r;
		UnitTest::total_test = 29;

		/* TEST 1 */
		std::cout << "Test 1...";
		ASSERT_TRUE(!strcmp("0/1", Rational().toString().c_str()));
		std::cout << " PASSED\n Test 2...";

		/* TEST 2 */
		std::cout << "mi resultado" << Rational(10).toString().c_str() << "\n";
		ASSERT_TRUE(!strcmp("10/1", Rational(10).toString().c_str()));
		std::cout << " PASSED\n Test 3...";

		/* TEST 3 */

		std::cout << "mi resultado" << Rational(2,4).toString().c_str() << "\n";
		ASSERT_TRUE(!strcmp("1/2", Rational(2,4).toString().c_str()));
		std::cout << " PASSED\n Test 4...";

		/* TEST 4 */
		ASSERT_TRUE(!strcmp("3/11", Rational(3,11).toString().c_str()));
		std::cout << " PASSED\n Test 5...";

		/* TEST 5 */
		ASSERT_TRUE(!strcmp("1/512", Rational(4,2048).toString().c_str()));
		std::cout << " PASSED\n Test 6...";

		/* TEST 6 */
		std::cout <<  "\n" << Rational(1,-2).toString().c_str() << std::endl;
		ASSERT_TRUE(!strcmp("-1/2", Rational(1,-2).toString().c_str()));
		std::cout << " PASSED\n Test 7...";

		/* TEST 7 */
		ASSERT_TRUE(!strcmp("-1/2", Rational(-1,2).toString().c_str()));
		std::cout << " PASSED\n Test 8...";

		/* TEST 8 */
		ASSERT_TRUE(!strcmp("1/2", Rational(-1,-2).toString().c_str()));
		std::cout << " PASSED\n Test 9...";

		/* TEST 9 */
		try {
			Rational(1,0);
			FAIL("RangeError not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("RangeError", e.what()));
			std::cout << " PASSED\n Test 10...";
		}

		/* TEST 10 */
		r = Rational(1, 3);
		ASSERT_TRUE(!strcmp("1/3", r.toString().c_str()));
		std::cout << " PASSED\n Test 11...";

		/* TEST 11 */
		r += Rational(2, 3);
		ASSERT_TRUE(!strcmp("1/1", r.toString().c_str()));
		std::cout << " PASSED\n Test 12...";

		/* TEST 12 */
		r = Rational(2, 3);
		r += Rational(5, 8);
		ASSERT_TRUE(!strcmp("31/24", r.toString().c_str()));
		std::cout << " PASSED\n Test 13...";

		/* TEST 13 */
		ASSERT_TRUE(0.5 == ((double) Rational(1,2)));
		std::cout << " PASSED\n Test 14...";

		/* TEST 14 */
		ASSERT_TRUE(0.625 == ((double) Rational(5,8)));
		std::cout << " PASSED\n Test 15...";

		/* TEST 15 */
		ASSERT_TRUE(0 == ((double) Rational()));
		std::cout << " PASSED\n Test 16...";

		/* TEST 16 */
		r = Rational(1,3) + Rational(2,3);
		ASSERT_TRUE(!strcmp("1/1", r.toString().c_str()));
		std::cout << " PASSED\n Test 17...";

		/* TEST 17 */
		r = Rational(2,3) + Rational(5,8);
		ASSERT_TRUE(!strcmp("31/24", r.toString().c_str()));
		std::cout << " PASSED\n Test 18...";

		/* TEST 18 */
		r = -Rational(1,3);
		ASSERT_TRUE(!strcmp("-1/3", r.toString().c_str()));
		std::cout << " PASSED\n Test 19...";

		/* TEST 19 */
		r = -Rational(-1,3);
		ASSERT_TRUE(!strcmp("1/3", r.toString().c_str()));
		std::cout << " PASSED\n Test 20...";

		/* TEST 20 */
		r = -Rational(-1,-3);
		ASSERT_TRUE(!strcmp("-1/3", r.toString().c_str()));
		std::cout << " PASSED\n Test 21...";

		/* TEST 21 */
		r = Rational(1, 3) - Rational(2, 3);
		ASSERT_TRUE(!strcmp("-1/3", r.toString().c_str()));
		std::cout << " PASSED\n Test 22...";

		/* TEST 22 */
		r = Rational(2, 3) - Rational(1, 3);
		ASSERT_TRUE(!strcmp("1/3", r.toString().c_str()));
		std::cout << " PASSED\n Test 23...";

		/* TEST 23 */
		r = Rational(5, 8) - Rational(2, 3);
		ASSERT_TRUE(!strcmp("-1/24", r.toString().c_str()));
		std::cout << " PASSED\n Test 24...";

		/* TEST 24 */
		r = Rational(2, 3) - Rational(5, 8);
		ASSERT_TRUE(!strcmp("1/24", r.toString().c_str()));
		std::cout << " PASSED\n Test 25...";

		/* TEST 25 */
		ASSERT_TRUE(Rational(1, 512) == Rational(4, 2048));
		std::cout << " PASSED\n Test 26...";

		/* TEST 26 */
		ASSERT_FALSE(Rational(2, 3) == Rational(5, 8));
		std::cout << " PASSED\n Test 27...";

		/* TEST 27 */
		ASSERT_TRUE(Rational(5, 8) < Rational(2, 3));
		std::cout << " PASSED\n Test 28...";

		/* TEST 28 */
		ASSERT_FALSE(Rational(2, 3) < Rational(5, 8));
		std::cout << " PASSED\n Test 29...";

		/* TEST 29 */
		ASSERT_FALSE(Rational(2, 3) < Rational(2, 3));
		std::cout << " PASSED\n";
	}
};

int main(int argc, char* argv[]) {
	RationalTest test;

	test.runTest();
	std::cout << "SUCCESS!\n";
	return 0;
}
