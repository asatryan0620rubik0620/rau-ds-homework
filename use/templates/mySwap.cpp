#include <iostream>
#include <string>
#include <cassert>

template <typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;

	std::cout << a << " " << b << std::endl;
}

int main() {
	int a1 = 10;
	int b1 = 20;
	mySwap(a1, b1);

	assert(a1 == 20);
	assert(b1 == 10);


	double a2 = 3.14;
	double b2 = 7.5;
	mySwap(a2, b2);

	assert(a2 == 7.5);
	assert(b2 == 3.14);


	std::string a3 = "hello";
	std::string b3 = "world";
	mySwap(a3, b3);

	assert(a3 == "world");
	assert(b3 == "hello");


	int a4 = 5;
	int b4 = 5;
	mySwap(a4, b4);

	assert(a4 == 5);
	assert(b4 == 5);


	int a5 = -10;
	int b5 = 25;
	mySwap(a5, b5);

	assert(a5 == 25);
	assert(b5 == -10);

	return 0;
}