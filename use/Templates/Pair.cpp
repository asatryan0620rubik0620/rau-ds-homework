#include <iostream>
#include <string>
#include <cassert>

template <typename T1, typename T2>
class Pair {
	T1 a;
	T2 b;

public:
	Pair(T1 a, T2 b) : a(a), b(b) {}

	void printAandB();

	T1 getA() {
		return a;
	}

	T2 getB() {
		return b;
	}
};

template <typename T1, typename T2>
void Pair<T1, T2>::printAandB() {
	std::cout << a << " " << b << std::endl;
}

int main() {
	Pair<int, std::string> pair1(1340, "asfa");
	pair1.printAandB();

	assert(pair1.getA() == 1340);
	assert(pair1.getB() == "asfa");


	Pair<int, double> pair2(87, 3.4444);
	pair2.printAandB();

	assert(pair2.getA() == 87);
	assert(pair2.getB() == 3.4444);


	Pair<int, int> pair3(10, 10);
	pair3.printAandB();

	assert(pair3.getA() == 10);
	assert(pair3.getB() == 10);


	Pair<std::string, std::string> pair4("", "");
	pair4.printAandB();

	assert(pair4.getA() == "");
	assert(pair4.getB() == "");

	return 0;
}