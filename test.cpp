#define CATCH_CONFIG_MAIN

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

#include "counting_sort.hpp"
#include "catch.hpp"

// ============================================================================

TEST_CASE("EMPTY VECTOR") {

	SECTION("SHORT") {
		std::vector<short> v;
		erikdac::counting_sort(v);
		REQUIRE(v.size() == 0);
	}

	SECTION("INT") {
		std::vector<int> v;
		erikdac::counting_sort(v);
		REQUIRE(v.size() == 0);
	}

	SECTION("LONG") {
		std::vector<long> v;
		erikdac::counting_sort(v);
		REQUIRE(v.size() == 0);
	}

	SECTION("LONG LONG") {
		std::vector<long long> v;
		erikdac::counting_sort(v);
		REQUIRE(v.size() == 0);
	}

	SECTION("UNSIGNED SHORT") {
		std::vector<unsigned short> v;
		erikdac::counting_sort(v);
		REQUIRE(v.size() == 0);
	}

	SECTION("UNSIGNED INT") {
		std::vector<unsigned int> v;
		erikdac::counting_sort(v);
		REQUIRE(v.size() == 0);
	}

	SECTION("UNSIGNED LONG") {
		std::vector<unsigned long> v;
		erikdac::counting_sort(v);
		REQUIRE(v.size() == 0);
	}

	SECTION("UNSIGNED LONG LONG") {
		std::vector<unsigned long long> v;
		erikdac::counting_sort(v);
		REQUIRE(v.size() == 0);
	}
}

// ============================================================================

#define RANGE 10

TEST_CASE("TIME COMPARISSON") {
	std::vector<int> v;
	for(int i = -RANGE; i < RANGE; ++i) {
		v.push_back(-i/5);
	}
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(-2);

	std::vector<int> first = v;

	clock_t begin = clock();

	erikdac::counting_sort(first);
	
	clock_t end = clock();
	double counting_time = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Counting sort: \t" << counting_time << std::endl;



	std::vector<int> second = v;

	begin = clock();

	erikdac::counting_sort(second);
	
	end = clock();
	double std_time = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Std sort: \t" << std_time << std::endl;


/*
	for(int i = 0; i < v.size(); ++i) {
		std::cout << v[i] << std::endl;;
	}
	std::cout << std::endl;
*/

}
