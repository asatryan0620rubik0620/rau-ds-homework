#include <iostream>
#include <string>
#include <cassert>

template <typename T>
void printElement(T n) {
	std::cout << n << std::endl;
}

int main()
{
	int a = 15;
	assert(a == 15);
	printElement(a);

	double b = 3.14;
	assert(b == 3.14);
	printElement(b);

	std::string c = "hello";
	assert(c == "hello");
	printElement(c);


	int zero = 0;
	assert(zero == 0);
	printElement(zero);


	std::string empty = "";
	assert(empty.empty());
	printElement(empty);

	return 0;
}