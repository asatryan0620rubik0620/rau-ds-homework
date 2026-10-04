#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
void resizeVector(std::vector<T>& array, int new_size, int value) {
	std::cout << "before: ";
	for (T a : array) {
		std::cout << a << " ";
	}

	array.resize(new_size, value);

	std::cout << "\nafter: ";
	for (T a : array) {
		std::cout << a << " ";
	}
}

int main() {
	std::vector<int> v = { 1, 2, 3 };
	resizeVector(v, 5, 42);

	assert(v.size() == 5);
	assert(v[0] == 1);
	assert(v[1] == 2);
	assert(v[2] == 3);
	assert(v[3] == 42);
	assert(v[4] == 42);


	std::vector<int> empty;
	resizeVector(empty, 3, 10);

	assert(empty.size() == 3);
	assert(empty[0] == 10);
	assert(empty[1] == 10);
	assert(empty[2] == 10);


	std::vector<int> oneElement = { 7 };
	resizeVector(oneElement, 1, 100);

	assert(oneElement.size() == 1);
	assert(oneElement[0] == 7);


	std::vector<int> repeatedValues = { 5, 5, 5 };
	resizeVector(repeatedValues, 5, 5);

	assert(repeatedValues.size() == 5);
	assert(repeatedValues[0] == 5);
	assert(repeatedValues[1] == 5);
	assert(repeatedValues[2] == 5);
	assert(repeatedValues[3] == 5);
	assert(repeatedValues[4] == 5);


	std::vector<int> smaller = { 1, 2, 3, 4, 5 };
	resizeVector(smaller, 2, 100);

	assert(smaller.size() == 2);
	assert(smaller[0] == 1);
	assert(smaller[1] == 2);


	std::vector<int> toEmpty = { 1, 2, 3 };
	resizeVector(toEmpty, 0, 100);

	assert(toEmpty.empty());


	std::vector<double> doubles = { 1.5, 2.5 };
	resizeVector(doubles, 4, 3.5);

	assert(doubles.size() == 4);
	assert(doubles[0] == 1.5);
	assert(doubles[1] == 2.5);
	assert(doubles[2] == 3.5);
	assert(doubles[3] == 3.5);

	return 0;
}