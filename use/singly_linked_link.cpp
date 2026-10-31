#include <forward_list>
#include <iostream>
#include <cassert>
#include <iterator>

const int* findMiddle(const std::forward_list<int>& list) {
    auto slow = list.begin();
    auto fast = list.begin();

    while (fast != list.end() && std::next(fast) != list.end()) {
        ++fast;
        ++slow;
        ++fast;
    }

    if (slow == list.end()) {
        return nullptr;
    }

    return &(*slow);
}

void test_findMiddle() {
    std::forward_list<int> list1 = { 1, 2, 3, 4, 5 };
    assert(*findMiddle(list1) == 3);

    std::forward_list<int> list23 = { 1, 2, 3, 4, 5, 6 };
    assert(*findMiddle(list23) == 4);

    std::forward_list<int> list3 = { 1 };
    assert(*findMiddle(list3) == 1);

    std::forward_list<int> list4 = { 1, 2 };
    assert(*findMiddle(list4) == 2);

    std::forward_list<int> list5;
    assert(findMiddle(list5) == nullptr);

    std::forward_list<int> list6 = { 5, 5, 5, 5, 5 };
    assert(*findMiddle(list6) == 5);

    std::cout << "tested " << std::endl;
}


int main() {
    test_findMiddle();

    return 0;
}
