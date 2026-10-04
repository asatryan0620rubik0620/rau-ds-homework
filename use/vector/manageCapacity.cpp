#include <iostream>
#include <vector>
#include <cassert>

void manageCapacity(std::vector<int>& array) {
	std::cout << "before size: " << array.size() << std::endl;
	std::cout << "before capacity: " << array.capacity() << std::endl;

	array.reserve(500);
	for (int i = 1; i <= 500; i++) {
		array.push_back(i);
	}

	std::cout << "after size: " << array.size() << std::endl;
	std::cout << "after capacity: " << array.capacity() << std::endl;
}

int main() {
	std::vector<int> array;
	manageCapacity(array);

	assert(array.size() == 500);
	assert(array.capacity() >= 500);
	assert(array[0] == 1);
	assert(array[499] == 500);


	std::vector<int> oneElement = { 10 };
	manageCapacity(oneElement);

	assert(oneElement.size() == 501);
	assert(oneElement[0] == 10);
	assert(oneElement[1] == 1);
	assert(oneElement[500] == 500);
	assert(oneElement.capacity() >= 500);


	std::vector<int> repeatedValues = { 5, 5, 5 };
	manageCapacity(repeatedValues);

	assert(repeatedValues.size() == 503);
	assert(repeatedValues[0] == 5);
	assert(repeatedValues[1] == 5);
	assert(repeatedValues[2] == 5);
	assert(repeatedValues[3] == 1);
	assert(repeatedValues[502] == 500);
	assert(repeatedValues.capacity() >= 500);

	return 0;
}