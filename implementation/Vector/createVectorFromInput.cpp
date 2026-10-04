#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>

std::vector<int> createVectorFromInput() {
	std::vector<int> array;
	int n;

	while (std::cin >> n && n != 0) {
		array.push_back(n);
	}

	return array;
}

int main() {
	std::istringstream input("1 2 3 4 5 0");
	std::cin.rdbuf(input.rdbuf());

	std::vector<int> array = createVectorFromInput();

	assert(array.size() == 5);
	assert(array[0] == 1);
	assert(array[1] == 2);
	assert(array[2] == 3);
	assert(array[3] == 4);
	assert(array[4] == 5);


	std::istringstream emptyInput("0");
	std::cin.rdbuf(emptyInput.rdbuf());

	std::vector<int> emptyArray = createVectorFromInput();

	assert(emptyArray.empty());
	assert(emptyArray.size() == 0);


	std::istringstream oneElementInput("42 0");
	std::cin.rdbuf(oneElementInput.rdbuf());

	std::vector<int> oneElement = createVectorFromInput();

	assert(oneElement.size() == 1);
	assert(oneElement[0] == 42);


	std::istringstream repeatedInput("5 5 5 5 0");
	std::cin.rdbuf(repeatedInput.rdbuf());

	std::vector<int> repeatedValues = createVectorFromInput();

	assert(repeatedValues.size() == 4);
	assert(repeatedValues[0] == 5);
	assert(repeatedValues[1] == 5);
	assert(repeatedValues[2] == 5);
	assert(repeatedValues[3] == 5);


	std::istringstream negativeInput("-10 -5 0");
	std::cin.rdbuf(negativeInput.rdbuf());

	std::vector<int> negativeValues = createVectorFromInput();

	assert(negativeValues.size() == 2);
	assert(negativeValues[0] == -10);
	assert(negativeValues[1] == -5);

	return 0;
}