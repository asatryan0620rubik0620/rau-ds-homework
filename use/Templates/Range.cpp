#include <iostream>
#include <cassert>

template <typename T>
class Range {
	T start;
	T end;

public:
	Range(T start, T end) : start(start), end(end) {}

	bool contains(const T& value) {
		return (value <= end && value >= start);
	}

	T length() {
		return end - start;
	}

	void print() {
		std::cout << start << " " << end << std::endl;
	}
};

int main() {
	Range<int> range1(3, 10);
	range1.print();

	assert(range1.contains(5) == true);
	assert(range1.contains(3) == true);
	assert(range1.contains(10) == true);
	assert(range1.contains(2) == false);
	assert(range1.length() == 7);

	std::cout << range1.contains(5) << std::endl;
	std::cout << range1.length() << std::endl;


	Range<double> range2(3.22, 10.3232);
	range2.print();

	assert(range2.contains(5.5) == true);
	assert(range2.contains(3.22) == true);
	assert(range2.contains(10.3232) == true);
	assert(range2.contains(2.5) == false);
	assert(range2.length() > 7.1 && range2.length() < 7.2);

	std::cout << range2.contains(5.5) << std::endl;
	std::cout << range2.length() << std::endl;


	Range<char> range3('a', 'f');
	range3.print();

	assert(range3.contains('c') == true);
	assert(range3.contains('a') == true);
	assert(range3.contains('f') == true);
	assert(range3.contains('z') == false);
	assert(range3.length() == 5);

	std::cout << range3.contains('c') << std::endl;
	std::cout << range3.length() << std::endl;


	Range<int> range4(5, 5);
	assert(range4.contains(5) == true);
	assert(range4.length() == 0);

	Range<int> range5(1, 10);
	assert(range5.contains(1) == true);
	assert(range5.contains(10) == true);
	assert(range5.contains(0) == false);
	assert(range5.contains(11) == false);

	return 0;
}