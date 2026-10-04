#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
int linearSearch(std::vector<T> array, T target) {
	for (int i = 0; i < array.size(); i++) {
		if (array[i] == target) {
			return i;
		}
	}

	return -1;
}

int main() {
	int target1 = 2;
	double target2 = 4.54;
	std::string target3 = "ch";

	std::vector<int> arr1 = {1, 2, 3, 4, 5};
	std::vector<double> arr2 = {1.323, 2.43, 4.54, 3.22, 33.43};
	std::vector<std::string> arr3 = {"ha", "bh", "ch", "dh", "eh"};


	std::cout << linearSearch(arr1, target1) << std::endl;
	std::cout << linearSearch(arr2, target2) << std::endl;
	std::cout << linearSearch(arr3, target3) << std::endl;

	assert(linearSearch(arr1, 2) == 1);
	assert(linearSearch(arr2, 4.54) == 2);
	assert(linearSearch(arr3, "ch") == 2);


	assert(linearSearch(arr1, 10) == -1);
	assert(linearSearch(arr2, 10.5) == -1);
	assert(linearSearch(arr3, "xx") == -1);


	std::vector<int> emptyArray;
	assert(linearSearch(emptyArray, 5) == -1);


	std::vector<int> oneElement = {7};
	assert(linearSearch(oneElement, 7) == 0);
	assert(linearSearch(oneElement, 3) == -1);


	std::vector<int> repeatedValues = {2, 2, 2, 5, 5};
	assert(linearSearch(repeatedValues, 2) == 0);
	assert(linearSearch(repeatedValues, 5) == 3);

	return 0;
}