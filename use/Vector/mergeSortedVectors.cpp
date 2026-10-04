#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> mergeSortedVectors(std::vector<int> arr1, std::vector<int> arr2) {
	std::vector<int> new_arr;
	int size = arr1.size() + arr2.size();
	int j = 0;
	int i = 0;

	while (i < arr1.size() && j < arr2.size()) {
		if (arr1[i] < arr2[j]) {
			new_arr.push_back(arr1[i]);
			i++;
		}
		else {
			new_arr.push_back(arr2[j]);
			j++;
		}
	}

	while (i < arr1.size()) {
		new_arr.push_back(arr1[i]);
		i++;
	}

	while (j < arr2.size()) {
		new_arr.push_back(arr2[j]);
		j++;
	}

	return new_arr;
}

int main() {
	std::vector<int> vec1 = { 1, 3, 5, 7 };
	std::vector<int> vec2 = { 2, 4, 6, 8, 9 };
	std::vector<int> merged = mergeSortedVectors(vec1, vec2);

	for (int i = 0; i < merged.size(); i++) {
		std::cout << merged[i] << " ";
	}

	assert(merged.size() == 9);
	assert(merged[0] == 1);
	assert(merged[1] == 2);
	assert(merged[2] == 3);
	assert(merged[3] == 4);
	assert(merged[4] == 5);
	assert(merged[5] == 6);
	assert(merged[6] == 7);
	assert(merged[7] == 8);
	assert(merged[8] == 9);


	std::vector<int> empty1;
	std::vector<int> empty2;
	std::vector<int> emptyMerged = mergeSortedVectors(empty1, empty2);

	assert(emptyMerged.empty());


	std::vector<int> one1 = { 5 };
	std::vector<int> one2 = { 10 };
	std::vector<int> oneMerged = mergeSortedVectors(one1, one2);

	assert(oneMerged.size() == 2);
	assert(oneMerged[0] == 5);
	assert(oneMerged[1] == 10);


	std::vector<int> empty = { };
	std::vector<int> normal = { 1, 2, 3 };
	std::vector<int> mergedWithEmpty = mergeSortedVectors(empty, normal);

	assert(mergedWithEmpty.size() == 3);
	assert(mergedWithEmpty[0] == 1);
	assert(mergedWithEmpty[1] == 2);
	assert(mergedWithEmpty[2] == 3);


	std::vector<int> repeated1 = { 1, 2, 2, 5 };
	std::vector<int> repeated2 = { 2, 2, 4 };
	std::vector<int> repeatedMerged = mergeSortedVectors(repeated1, repeated2);

	assert(repeatedMerged.size() == 7);
	assert(repeatedMerged[0] == 1);
	assert(repeatedMerged[1] == 2);
	assert(repeatedMerged[2] == 2);
	assert(repeatedMerged[3] == 2);
	assert(repeatedMerged[4] == 2);
	assert(repeatedMerged[5] == 4);
	assert(repeatedMerged[6] == 5);


	std::vector<int> equal1 = { 3, 3, 3 };
	std::vector<int> equal2 = { 3, 3 };
	std::vector<int> equalMerged = mergeSortedVectors(equal1, equal2);

	assert(equalMerged.size() == 5);
	assert(equalMerged[0] == 3);
	assert(equalMerged[1] == 3);
	assert(equalMerged[2] == 3);
	assert(equalMerged[3] == 3);
	assert(equalMerged[4] == 3);

	return 0;
}