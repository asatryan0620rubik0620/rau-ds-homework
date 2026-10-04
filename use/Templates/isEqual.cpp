#include <iostream>
#include <cstring>
#include <string>
#include <cassert>

template <typename T>
bool isEqual(T a, T b) {
	return a == b;
}

bool isEqual(const char* a, const char* b) {
	return strcmp(a, b) == 0;
}

int main() {
	char a[] = "hello";
	char b[] = "hello";

	std::cout << isEqual(5, 5) << std::endl;
	std::cout << isEqual(34636.555, 667.88) << std::endl;
	std::cout << isEqual(a, b) << std::endl;

	assert(isEqual(5, 5) == true);
	assert(isEqual(5, 10) == false);

	assert(isEqual(3.14, 3.14) == true);
	assert(isEqual(3.14, 2.71) == false);

	assert(isEqual(a, b) == true);

	char c[] = "hello";
	char d[] = "world";

	assert(isEqual(c, d) == false);

	char empty1[] = "";
	char empty2[] = "";

	assert(isEqual(empty1, empty2) == true);

	std::string str1 = "hello";
	std::string str2 = "hello";
	std::string str3 = "world";

	assert(isEqual(str1, str2) == true);
	assert(isEqual(str1, str3) == false);

	return 0;
}