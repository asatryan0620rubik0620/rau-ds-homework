#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cassert>

std::vector<std::string> generateBinaryNumbers(int n) {
    std::vector<std::string> result;
    std::queue<std::string> q;

    if (n <= 0) {
        return result;
    }

    q.push("1");

    for (int i = 0; i < n; i++) {
        std::string current = q.front();
        q.pop();

        result.push_back(current);

        q.push(current + "0");
        q.push(current + "1");
    }

    return result;
}

void test_generateBinaryNumbers() {
    assert(generateBinaryNumbers(1) == std::vector<std::string>{"1"});

    assert(generateBinaryNumbers(3) ==
        (std::vector<std::string>{"1", "10", "11"}));

    assert(generateBinaryNumbers(5) ==
        (std::vector<std::string>{"1", "10", "11", "100", "101"}));

    assert(generateBinaryNumbers(0) == std::vector<std::string>{});

    assert(generateBinaryNumbers(-2) == std::vector<std::string>{});

    std::cout << "tested " << std::endl;
}

int main() {
    test_generateBinaryNumbers();

    return 0;
}
