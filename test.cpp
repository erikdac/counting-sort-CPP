#include <iostream>
#include <vector>

#include "counting_sort.hpp"

int main() {
	std::vector<int> v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(-2);

	counting_sort(v);

	for(int i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}
