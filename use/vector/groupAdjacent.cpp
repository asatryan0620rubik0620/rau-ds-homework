#include <iostream>
#include <vector>
#include <cassert>

std::vector<std::vector<int>> groupAdjacent(std::vector<int> array)
{
	std::vector<std::vector<int>> subs;

	if (array.empty()) {
		return subs;
	}

	std::vector<int> sub;
	sub.push_back(array[0]);

	for (int i = 1; i < array.size(); i++) {
		if (array[i] == array[i - 1]) {
			sub.push_back(array[i]);
		}
		else {
			subs.push_back(sub);
			sub.clear();
			sub.push_back(array[i]);
		}
	}

	subs.push_back(sub);
	return subs;
}

int main() {
	std::vector<int> vec = { 1, 1, 2, 2, 2, 3, 1, 1 };
	std::vector<std::vector<int>> subs = groupAdjacent(vec);

	for (int i = 0; i < subs.size(); i++) {
		for (int j = 0; j < subs[i].size(); j++) {
			std::cout << subs[i][j] << " ";
		}
		std::cout << "\n";
	}

	assert(subs.size() == 4);

	assert(subs[0].size() == 2);
	assert(subs[0][0] == 1);
	assert(subs[0][1] == 1);

	assert(subs[1].size() == 3);
	assert(subs[1][0] == 2);
	assert(subs[1][1] == 2);
	assert(subs[1][2] == 2);

	assert(subs[2].size() == 1);
	assert(subs[2][0] == 3);

	assert(subs[3].size() == 2);
	assert(subs[3][0] == 1);
	assert(subs[3][1] == 1);


	std::vector<int> emptyVector;
	std::vector<std::vector<int>> emptyResult = groupAdjacent(emptyVector);

	assert(emptyResult.empty());


	std::vector<int> oneElement = { 7 };
	std::vector<std::vector<int>> oneResult = groupAdjacent(oneElement);

	assert(oneResult.size() == 1);
	assert(oneResult[0].size() == 1);
	assert(oneResult[0][0] == 7);


	std::vector<int> repeatedValues = { 5, 5, 5, 5 };
	std::vector<std::vector<int>> repeatedResult = groupAdjacent(repeatedValues);

	assert(repeatedResult.size() == 1);
	assert(repeatedResult[0].size() == 4);
	assert(repeatedResult[0][0] == 5);
	assert(repeatedResult[0][1] == 5);
	assert(repeatedResult[0][2] == 5);
	assert(repeatedResult[0][3] == 5);


	std::vector<int> differentValues = { 1, 2, 3, 4 };
	std::vector<std::vector<int>> differentResult = groupAdjacent(differentValues);

	assert(differentResult.size() == 4);

	assert(differentResult[0].size() == 1);
	assert(differentResult[0][0] == 1);

	assert(differentResult[1].size() == 1);
	assert(differentResult[1][0] == 2);

	assert(differentResult[2].size() == 1);
	assert(differentResult[2][0] == 3);

	assert(differentResult[3].size() == 1);
	assert(differentResult[3][0] == 4);

	return 0;
}