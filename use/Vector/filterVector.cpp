#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
std::vector<T> filterVector(std::vector<T> array, bool(&predicate)(T)) {
	std::vector<T> new_array;

	for (T a : array) {
		if (predicate(a)) {
			new_array.push_back(a);
		}
	}

	return new_array;
}

bool isEven(int x) {
	return x % 2 == 0;
}

int main() {
	std::vector<int> vec = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> filtered = filterVector(vec, isEven);

	for (int i = 0; i < filtered.size(); i++) {
		std::cout << filtered[i] << " ";
	}

	assert(filtered.size() == 3);
	assert(filtered[0] == 2);
	assert(filtered[1] == 4);
	assert(filtered[2] == 6);


	std::vector<int> emptyVector;
	std::vector<int> emptyFiltered = filterVector(emptyVector, isEven);

	assert(emptyFiltered.empty());


	std::vector<int> oneElement = { 8 };
	std::vector<int> oneElementFiltered = filterVector(oneElement, isEven);

	assert(oneElementFiltered.size() == 1);
	assert(oneElementFiltered[0] == 8);


	std::vector<int> oneOddElement = { 7 };
	std::vector<int> oneOddFiltered = filterVector(oneOddElement, isEven);

	assert(oneOddFiltered.empty());


	std::vector<int> repeatedValues = { 2, 2, 3, 4, 4, 5, 6, 6 };
	std::vector<int> repeatedFiltered = filterVector(repeatedValues, isEven);

	assert(repeatedFiltered.size() == 6);
	assert(repeatedFiltered[0] == 2);
	assert(repeatedFiltered[1] == 2);
	assert(repeatedFiltered[2] == 4);
	assert(repeatedFiltered[3] == 4);
	assert(repeatedFiltered[4] == 6);
	assert(repeatedFiltered[5] == 6);


	std::vector<int> noEven = { 1, 3, 5, 7 };
	std::vector<int> noEvenFiltered = filterVector(noEven, isEven);

	assert(noEvenFiltered.empty());

	return 0;
}