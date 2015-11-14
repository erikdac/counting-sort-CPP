#include <iostream>
#include <vector>
#include <type_traits>
 
template <
	typename T, 
	typename = typename std::enable_if<std::is_integral<T>::value, T>::type
>
void sort(std::vector<T> & v) {
	if(v.size() == 0)
		return;

	T min = v[0];
	T max = v[0];
	for(int i = 1; i < v.size(); ++i) {
		if(v[i] < min)
			min = v[i];
		if(v[i] > max)
			max = v[i];
	}

	std::cout << min << "\t" << max << std::endl;

}
