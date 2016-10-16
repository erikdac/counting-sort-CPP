#include <vector>
#include <type_traits>

namespace erikdac {

	template <
		typename T, 
		typename = typename std::enable_if<std::is_integral<T>::value, T>::type
	>
	void counting_sort(std::vector<T> & vec) {
		if (vec.size() <= 1)
			return;

		T small = vec[0];
		T big = vec[0];
		for (std::size_t i = 1; i < vec.size(); ++i) {
			if(vec[i] < small) {
				small = vec[i];
			}
			if(vec[i] > big) {
				big = vec[i];
			}
		}

		T counter[big-small+1];
		for(int i = 0; i <= big-small; ++i) {
			counter[i] = 0;
		}

		for (std::size_t i = 0; i < vec.size(); ++i) {
			++counter[vec[i]-small];
		}

		T total = 0;
		for (int i = 0; i <= big-small+1; ++i) {
			T oldCount = counter[i];
			counter[i] = total;
			total += oldCount;
		}

		std::vector<T> out(vec.size());
		for (std::size_t i = 0; i < out.size(); ++i) {
			out[counter[vec[i]-small]] = vec[i];
			++counter[vec[i]-small];
		}

		vec = out;
	}
}
