#include <iostream>
#include <forward_list>
#include <cassert>

void mergeSortedLists(std::forward_list<int>& fl1, std::forward_list<int>& fl2) {
    auto it1 = fl1.before_begin();
    auto it2 = fl1.begin();

    for (auto it = fl2.begin(); it != fl2.end(); ++it) {
        while (it2 != fl1.end() && *it2 <= *it) {
            ++it1;
            ++it2;
        }


        it1 = fl1.insert_after(it1, *it);
        it2 = std::next(it1);
    }
    fl2.clear();
}

void test_mergeSortedLists() {
    std::forward_list<int> fl1 = { 1, 3, 5 };
    std::forward_list<int> fl2 = { 2, 4, 6 };

    mergeSortedLists(fl1, fl2);

    assert(fl1 == std::forward_list<int>({ 1, 2, 3, 4, 5, 6 }));
    assert(fl2.empty());

    std::forward_list<int> empty1;
    std::forward_list<int> list2 = { 1, 2, 3 };

    mergeSortedLists(empty1, list2);

    assert(empty1 == std::forward_list<int>({ 1, 2, 3 }));
    assert(list2.empty());
    std::forward_list<int> list3 = { 1, 2, 3 };
    std::forward_list<int> empty2;

    mergeSortedLists(list3, empty2);

    assert(list3 == std::forward_list<int>({ 1, 2, 3 }));
    assert(empty2.empty());

    std::forward_list<int> list4 = { 5 };
    std::forward_list<int> list5 = { 1 };
    mergeSortedLists(list4, list5);

    assert(list4 == std::forward_list<int>({ 1, 5 }));
    assert(list5.empty());

    std::forward_list<int> list6 = { 1, 2, 2, 4 };
    std::forward_list<int> list7 = { 2, 2, 3, 4 };

    mergeSortedLists(list6, list7);
    assert(list6 == std::forward_list<int>({ 1, 2, 2, 2, 2, 3, 4, 4 }));
    assert(list7.empty());

    std::forward_list<int> empty3;
    std::forward_list<int> empty4;

    mergeSortedLists(empty3, empty4);

    assert(empty3.empty());
    assert(empty4.empty());

    std::forward_list<int> list8 = { 1, 2, 3 };
    std::forward_list<int> list9 = { 4, 5, 6 };

    mergeSortedLists(list8, list9);

    assert(list8 == std::forward_list<int>({ 1, 2, 3, 4, 5, 6 }));
    assert(list9.empty());

    std::cout << "tested " << std::endl;
}

int main() {
    test_mergeSortedLists();

    return 0;
}
