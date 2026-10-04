#include <iostream>
#include <vector>
#include <cassert>

int findSubsequence(std::vector<int> main, std::vector<int> sub) {
	if (sub.size() > main.size()) {
		return -1;
	}

	for (int i = 0; i <= main.size() - sub.size(); i++) {
		bool found = true;

		for (int j = 0; j < sub.size(); j++) {
			if (main[i + j] != sub[j]) {
				found = false;
				break;
			}
		}

		if (found) {
			return i;
		}
	}

	return -1;
}

int main() {
	std::vector<int> main_vec = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> sub_vec = { 3, 4, 5 };
	int index = findSubsequence(main_vec, sub_vec);

	std::cout << index;

	assert(findSubsequence(main_vec, sub_vec) == 2);


	std::vector<int> emptySub;
	assert(findSubsequence(main_vec, emptySub) == 0);


	std::vector<int> oneElement = { 4 };
	assert(findSubsequence(main_vec, oneElement) == 3);


	std::vector<int> repeatedMain = { 1, 2, 2, 3, 2, 2, 4 };
	std::vector<int> repeatedSub = { 2, 2 };

	assert(findSubsequence(repeatedMain, repeatedSub) == 1);


	std::vector<int> notFound = { 7, 8 };
	assert(findSubsequence(main_vec, notFound) == -1);


	std::vector<int> longerSub = { 1, 2, 3, 4, 5, 6, 7 };
	assert(findSubsequence(main_vec, longerSub) == -1);


	std::vector<int> sameVector = { 1, 2, 3 };
	assert(findSubsequence(sameVector, sameVector) == 0);

	return 0;
}