#include <iostream>
#include <vector>
#include <cassert>

int removeElementsGreaterThan(std::vector<int>& array, int n) {
	int count = 0;
	while (!array.empty() && array.back() > n) {
		array.pop_back();
		count++;
	}

	return count;
}

int main() {
	std::vector<int> v = { 1, 3, 5, 7, 9 };
	int removed = removeElementsGreaterThan(v, 5);
	std::cout << removed << std::endl;

	assert(removed == 2);
	assert(v.size() == 3);
	assert(v[0] == 1);
	assert(v[1] == 3);
	assert(v[2] == 5);


	std::vector<int> empty;
	removed = removeElementsGreaterThan(empty, 5);

	assert(removed == 0);
	assert(empty.empty());


	std::vector<int> oneElement = { 10 };
	removed = removeElementsGreaterThan(oneElement, 5);

	assert(removed == 1);
	assert(oneElement.empty());


	std::vector<int> oneElementNotGreater = { 5 };
	removed = removeElementsGreaterThan(oneElementNotGreater, 5);

	assert(removed == 0);
	assert(oneElementNotGreater.size() == 1);
	assert(oneElementNotGreater[0] == 5);


	std::vector<int> repeatedValues = { 1, 2, 3, 6, 6, 6 };
	removed = removeElementsGreaterThan(repeatedValues, 5);

	assert(removed == 3);
	assert(repeatedValues.size() == 3);
	assert(repeatedValues[0] == 1);
	assert(repeatedValues[1] == 2);
	assert(repeatedValues[2] == 3);


	std::vector<int> noRemoval = { 1, 2, 3, 4, 5 };
	removed = removeElementsGreaterThan(noRemoval, 5);

	assert(removed == 0);
	assert(noRemoval.size() == 5);
	assert(noRemoval[0] == 1);
	assert(noRemoval[4] == 5);


	std::vector<int> allGreater = { 10, 20, 30, 40 };
	removed = removeElementsGreaterThan(allGreater, 5);

	assert(removed == 4);
	assert(allGreater.empty());

	return 0;
}