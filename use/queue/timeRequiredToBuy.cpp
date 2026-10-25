#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cassert>

int timeRequiredToBuy(std::vector<int> tickets, int k) {
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < tickets.size(); i++) {
        q.push({ i, tickets[i] });
    }

    int time = 0;

    while (!q.empty())
    {
        int index = q.front().first;
        int remain = q.front().second;
        q.pop();

        remain--;
        time++;

        if (index == k && remain == 0) {
            return time;
        }

        if (remain > 0) {
            q.push({ index, remain });
        }
    }

    return time;
}

void test_timeRequiredToBuy() {
    assert(timeRequiredToBuy({ 2, 3, 2 }, 2) == 6);
    assert(timeRequiredToBuy({ 5, 1, 1, 1 }, 0) == 8);
    assert(timeRequiredToBuy({ 1 }, 0) == 1);
    assert(timeRequiredToBuy({ 1, 2, 3 }, 0) == 1);
    assert(timeRequiredToBuy({ 1, 2, 3 }, 2) == 6);
    assert(timeRequiredToBuy({ 3, 3, 3 }, 1) == 8);

    std::cout << "tested " << std::endl;
}

int main() {
    test_timeRequiredToBuy();
    return 0;
}
