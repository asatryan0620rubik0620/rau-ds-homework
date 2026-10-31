
#include <iostream>
#include <forward_list>
#include <cassert>

int removeAllOccurrences(std::forward_list<int>& list, int value) {
    int count = 0;
    auto prev = list.before_begin();
    auto curr = list.begin();

    while (curr != list.end()) 
    {
        if (*curr == value) {
            curr = list.erase_after(prev); 
            count++;
        }
        else {
            prev = curr;
            curr++;
        }
    }


    return count;
}

void test_removeAllOccurrences() {
    std::forward_list<int> list1 = { 1, 2, 3, 2, 4, 2 };

    assert(removeAllOccurrences(list1, 2) == 3);

    int expected1[] = { 1, 3, 4 };
    int index = 0;

    for (int x : list1) {
        assert(x == expected1[index]);
        index++;
    }

    assert(index == 3);

    std::forward_list<int> list2 = { 1, 1, 1 };


    assert(removeAllOccurrences(list2, 1) == 3);
    assert(list2.empty());

    std::forward_list<int> list3 = { 1, 2, 3 };

    assert(removeAllOccurrences(list3, 4) == 0);

    std::forward_list<int> list4;

    assert(removeAllOccurrences(list4, 5) == 0);

    std::forward_list<int> list5 = { 2, 2, 1, 2, 3 };

    assert(removeAllOccurrences(list5, 2) == 3);

    int expected5[] = { 1, 3 };
    index = 0;


    for (int x : list5) {
        assert(x == expected5[index]);
        index++;
    }

    assert(index == 2);

    std::cout << "tested" << std::endl;
}

int main() {
    test_removeAllOccurrences();

    return 0;
}
