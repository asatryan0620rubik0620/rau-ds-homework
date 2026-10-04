#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createAndFillVector(int N) {
	std::vector<int> array(N);

	for (int i = 0; i < array.size(); i++) {
		array[i] = i + 1;
	}

	for (int i = 0; i < array.size(); i++) {
		std::cout << array[i] << " ";
	}

	std::cout << "\n" << "size: " << array.size();
	std::cout << "\n" << "capacity: " << array.capacity();

	return array;
}

int main() {
	std::vector<int> array1 = createAndFillVector(7);

	assert(array1.size() == 7);
	assert(array1[0] == 1);
	assert(array1[1] == 2);
	assert(array1[6] == 7);

	std::vector<int> array2 = createAndFillVector(0);

	assert(array2.empty());
	assert(array2.size() == 0);

	std::vector<int> array3 = createAndFillVector(1);

	assert(array3.size() == 1);
	assert(array3[0] == 1);

	std::vector<int> array4 = createAndFillVector(5);

	assert(array4.size() == 5);
	assert(array4[0] == 1);
	assert(array4[1] == 2);
	assert(array4[2] == 3);
	assert(array4[3] == 4);
	assert(array4[4] == 5);

	return 0;
}
