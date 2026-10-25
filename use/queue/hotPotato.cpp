#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cassert>

std::string hotPotato(std::vector<std::string> players, int k) {
    std::queue<std::string> q;

    for (std::string player : players) {
        q.push(player);
    }

    while (q.size() > 1)
    {
        for (int i = 0; i < k; i++)
        {
            q.push(q.front());
            q.pop();
        }

        q.pop();
    }

    return q.front();
}


void test_hotPotato() {
    assert(hotPotato({ "Alice", "Bob", "Charlie" }, 1) == "Charlie");
    assert(hotPotato({ "Alice" }, 3) == "Alice");
    assert(hotPotato({ "Alice", "Bob" }, 0) == "Bob");
    assert(hotPotato({ "Alice", "Bob", "Charlie", "David" }, 7) == "Charlie");
    assert(hotPotato({ "A", "B", "C", "D", "E" }, 2) == "D");

    std::cout << "tested " << std::endl;
}

int main() {
    test_hotPotato();

    return 0;
}
