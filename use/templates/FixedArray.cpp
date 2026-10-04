#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

template <typename T, int N>
class FixedArray {
	T* array;
public:
	FixedArray() {
		array = new T[N];
	}

	void set(int index, T value) {
		*(array + index) = value;
	}

	T get(int index) {
		return *(array + index);
	}

	int size() {
		return N;
	}

	~FixedArray() {
		delete[] array;
	}
};

int main() {
	FixedArray<int, 4> array1;

	array1.set(3, 45);
	array1.set(1, 45);
	std::cout << array1.get(1) << std::endl;
	std::cout << array1.size() << std::endl;

	assert(array1.get(1) == 45);
	assert(array1.get(3) == 45);
	assert(array1.size() == 4);


	FixedArray<int, 2> array2;

	array2.set(0, 78);
	array2.set(1, 4);
	std::cout << array2.get(1) << std::endl;
	std::cout << array2.size() << std::endl;

	assert(array2.get(0) == 78);
	assert(array2.get(1) == 4);
	assert(array2.size() == 2);


	FixedArray<double, 2> array3;

	array3.set(0, 78.45);
	array3.set(1, 4.5);
	std::cout << array3.get(1) << std::endl;
	std::cout << array3.size() << std::endl;

	assert(std::abs(array3.get(0) - 78.45) < 0.000001);
	assert(std::abs(array3.get(1) - 4.5) < 0.000001);
	assert(array3.size() == 2);


	FixedArray<std::string, 3> array4;

	array4.set(0, "wwwwwwf");
	array4.set(1, "hhhhhhhhh");
	array4.set(2, "tttttttttw");
	std::cout << array4.get(1) << std::endl;
	std::cout << array4.size() << std::endl;

	assert(array4.get(0) == "wwwwwwf");
	assert(array4.get(1) == "hhhhhhhhh");
	assert(array4.get(2) == "tttttttttw");
	assert(array4.size() == 3);


	FixedArray<int, 1> array5;

	array5.set(0, 100);
	assert(array5.get(0) == 100);
	assert(array5.size() == 1);


	FixedArray<int, 5> array6;

	array6.set(0, 7);
	array6.set(1, 7);
	array6.set(2, 7);
	array6.set(3, 7);
	array6.set(4, 7);

	assert(array6.get(0) == 7);
	assert(array6.get(1) == 7);
	assert(array6.get(2) == 7);
	assert(array6.get(3) == 7);
	assert(array6.get(4) == 7);
	assert(array6.size() == 5);

	return 0;
}
