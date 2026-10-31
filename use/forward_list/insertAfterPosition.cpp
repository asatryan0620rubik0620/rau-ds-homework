
#include <iostream>
#include <forward_list>
#include <cassert>

bool insertAfterPosition(std::forward_list<int>& list, int pos, int value) {
    if (pos < 0) {
        return false;
    }

    auto it = list.begin();

    for (int i = 0; i < pos && it != list.end(); i++)
    {
        it++;
    }
    if (it == list.end()) {
        return false;
    }

    list.insert_after(it, value);
    return true;
}

void test_insertAfterPosition() {
    std::forward_list<int> list1 = { 1, 2, 3, 4 };

    assert(insertAfterPosition(list1, 1, 99));

    int expected1[] = { 1, 2, 99, 3, 4 };
    int index = 0;

    for (int x : list1) 
    {
        assert(x == expected1[index]);
        index++;
    }

    assert(index == 5);

    std::forward_list<int> list2 = { 10 };
    assert(insertAfterPosition(list2, 0, 20));
    assert(list2.front() == 10);

    auto it = list2.begin();
    ++it;
    assert(*it == 20);

    std::forward_list<int> list3;
    assert(!insertAfterPosition(list3, 0, 50));

    std::forward_list<int> list4 = { 1, 2, 3 };

    assert(!insertAfterPosition(list4, 3, 50));
    assert(!insertAfterPosition(list4, -1, 50));

    std::forward_list<int> list5 = { 1, 2, 3 };

    assert(insertAfterPosition(list5, 2, 3));


    int expected5[] = { 1, 2, 3, 3 };
    index = 0;

    for (int x : list5){
        assert(x == expected5[index]);
        index++;
    }

    assert(index == 4);
     
    std::cout << "tested " << std::endl;
}


int main() {
    test_insertAfterPosition();
    return 0;
}
