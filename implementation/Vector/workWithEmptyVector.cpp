#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> workWithEmptyVector() {
	std::vector<int> array;

	for (int i = 0; i < 10; i++) {
		array.push_back(i + 1);
		std::cout << "size: " << array.size() << "\n";
		std::cout << "capacity: " << array.capacity() << "\n";
	}

	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << " ";
	}

	return array;
}

int main() {
	std::vector<int> array = workWithEmptyVector();

	assert(array.size() == 10);
	assert(array[0] == 1);
	assert(array[1] == 2);
	assert(array[2] == 3);
	assert(array[3] == 4);
	assert(array[4] == 5);
	assert(array[5] == 6);
	assert(array[6] == 7);
	assert(array[7] == 8);
	assert(array[8] == 9);
	assert(array[9] == 10);

	std::vector<int> oneElement;
	oneElement.push_back(1);

	assert(oneElement.size() == 1);
	assert(oneElement[0] == 1);

	std::vector<int> repeatedValues;
	repeatedValues.push_back(5);
	repeatedValues.push_back(5);
	repeatedValues.push_back(5);

	assert(repeatedValues.size() == 3);
	assert(repeatedValues[0] == 5);
	assert(repeatedValues[1] == 5);
	assert(repeatedValues[2] == 5);

	return 0;
}