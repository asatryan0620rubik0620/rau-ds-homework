#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

template <typename T>
T sumArray(T* array, int size) {
	T sum = T();
	for (int i = 0; i < size; i++) {
		sum += *(array + i);
	}

	return sum;
}

int main() {
	int size = 5;
	int* arr1 = new int[size]{ 1, 2, 3, 4, 5 };
	double* arr2 = new double[size]{ 1.908, 2.222, 3.56867, 4.56, 5.87 };
	std::string* arr3 = new std::string[size]{ "ha", "hb", "hc", "hd", "he" };

	std::cout << sumArray(arr1, size) << std::endl;
	std::cout << sumArray(arr2, size) << std::endl;
	std::cout << sumArray(arr3, size) << std::endl;

	assert(sumArray(arr1, size) == 15);
	assert(std::abs(sumArray(arr2, size) - 18.12867) < 0.000001);
	assert(sumArray(arr3, size) == "hahbhchdhe");

	int emptySize = 0;
	int* emptyArray = new int[emptySize];
	assert(sumArray(emptyArray, emptySize) == 0);

	int oneElement[] = { 42 };
	assert(sumArray(oneElement, 1) == 42);

	int repeatedValues[] = { 5, 5, 5, 5, 5 };
	assert(sumArray(repeatedValues, 5) == 25);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] emptyArray;

	return 0;
}