/*
 * main.cpp
 *
 *  Created on: 10/09/2015
 *      Author: pperezm
 */
#include <iostream>
#include "unit.h"
#include "recursion.h"

class RecursionTest : public UnitTest {
public:
	void runTest() {
		int a1[] = {0, 1, 2, 3, 4, 5, 6, 10, 6, 5, 4, 3};
		int a2[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};
		int size = 12;
		UnitTest::total_test = 19;

		/* TEST 1 */
		std::cout << "Test 1...";
		ASSERT_TRUE(sum_seq(100) == 5050);
		std::cout << "PASSED.\nTest 2...";

		/* TEST 2 */
		ASSERT_TRUE(sum_rec(100) == 5050);
		std::cout << "PASSED.\nTest 3...";

		/* TEST 3 */
		ASSERT_TRUE(fact_seq(7) == 5040);
		std::cout << "PASSED.\nTest 4...";

		/* TEST 4 */
		ASSERT_TRUE(fact_rec(7) == 5040);
		std::cout << "PASSED.\nTest 5...";

		/* TEST 5 */
		ASSERT_TRUE(fib_seq(10) == 55);
		std::cout << "PASSED.\nTest 6...";

		/* TEST 6 */
		ASSERT_TRUE(fib_rec(10) == 55);
		std::cout << "PASSED.\nTest 7...";

		/* TEST 7 */
		ASSERT_TRUE(gcd_seq(10, 22) == 2);
		std::cout << "PASSED.\nTest 8...";

		/* TEST 8 */
		ASSERT_TRUE(gcd_seq(13, 23) == 1);
		std::cout << "PASSED.\nTest 9...";

		/* TEST 9 */
		ASSERT_TRUE(gcd_rec(10, 22) == 2);
		std::cout << "PASSED.\nTest 10...";

		/* TEST 10 */
		ASSERT_TRUE(gcd_rec(13, 23) == 1);
		std::cout << "PASSED.\nTest 11...";

		/* TEST 11 */
		ASSERT_TRUE(find_seq(a1, size,  6) ==  true);
		std::cout << "PASSED.\nTest 12...";

		/* TEST 12 */
		ASSERT_TRUE(find_seq(a1, size, 11) == false);
		std::cout << "PASSED.\nTest 13...";

		/* TEST 13 */
		ASSERT_TRUE(find_rec(a1, 0, size - 1,  6) ==  true);
		std::cout << "PASSED.\nTest 14...";

		/* TEST 14 */
		ASSERT_TRUE(find_rec(a1, 0, size - 1, 11) == false);
		std::cout << "PASSED.\nTest 15...";

		/* TEST 15 */
		ASSERT_TRUE(max_seq(a1, size) ==  10);
		std::cout << "PASSED.\nTest 16...";

		/* TEST 16 */
		ASSERT_TRUE(max_rec(a1, 0, size - 1) == 10);
		std::cout << "PASSED.\nTest 17...";

		/* TEST 17 */
		ASSERT_TRUE(unimodal_seq(a1, size) == 7);
		std::cout << "PASSED.\nTest 18...";

		/* TEST 18 */
		ASSERT_TRUE(unimodal_rec(a1, size) == 7);
		std::cout << "PASSED.\nTest 19...";

	}
};

int main(int argc, char* argv[]) {
	RecursionTest test;

	test.runTest();
	std::cout << "SUCCESS!\n";
	return 0;
}
