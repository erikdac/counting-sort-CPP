#include <vector>
#include <type_traits>

namespace erikdac {

	template <
		typename T, 
		typename = typename std::enable_if<std::is_integral<T>::value, T>::type
	>
	void counting_sort(std::vector<T> & v) {
		if(v.size() <= 1)
			return;

		T min = v[0];
		T max = v[0];
		for(int i = 1; i < v.size(); ++i) {
			if(v[i] < min)
				min = v[i];
			if(v[i] > max)
				max = v[i];
		}

		T * count = new T[max-min+1];
		for(int i = 0; i <= max-min; ++i)
			count[i] = 0;

		for(int i = 0; i < v.size(); ++i)
			++count[v[i]-min];


		T total = 0;
		for(int i = 0; i <= max-min+1; ++i) {
			T oldCount = count[i];
			count[i] = total;
			total += oldCount;
		}

		std::vector<T> out(v.size());
		for(int i = 0; i < out.size(); ++i) {
			out[count[v[i]-min]] = v[i];
			++count[v[i]-min];
		}
		delete [] count;

		v = out;
	}
}
