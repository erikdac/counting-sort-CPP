#include <iostream>
#include <vector>
#include "counting_sort.hpp"

int main() {
	std::vector<long> v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);

	counting_sort(v);
}
