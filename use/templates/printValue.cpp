#include <iostream>
#include <cassert>

template <typename T>
void printValue(T a) {
	std::cout << a << std::endl;
}

void printValue(bool a) {
	if (a) std::cout << true << std::endl;
	else std::cout << false << std::endl;
}

void printValue(char* a) {
	int i = 0;
	std::cout << "[";
	while (*(a + i) != '\0') {
		std::cout << *(a + i);
		i++;
	}
	std::cout << "]";
	std::cout << std::endl;
}

int main() {
	int a = 15;
	assert(a == 15);
	printValue(a);

	double b = 3.14;
	assert(b == 3.14);
	printValue(b);

	bool c = true;
	assert(c == true);
	printValue(c);

	char text[] = "abhdabfuha";
	assert(text[0] == 'a');
	printValue(text);

	int zero = 0;
	assert(zero == 0);
	printValue(zero);

	bool falseValue = false;
	assert(falseValue == false);
	printValue(falseValue);

	char emptyText[] = "";
	assert(emptyText[0] == '\0');
	printValue(emptyText);

	return 0;
}