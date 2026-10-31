
#include <iostream>
#include <forward_list>
#include <cassert>

std::forward_list<int> createAndFillList(int N) {
    std::forward_list<int> list;

    for (int i = 1; i <= N; i++) 
    {
        list.push_front(i);
    }

    for (int a : list){
        std::cout << a << " ";
    }

    return list;
}

void test_createAndFillList() {
    assert(createAndFillList(0).empty());

    std::forward_list<int> list1 = createAndFillList(1);
    assert(list1.front() == 1);

    std::forward_list<int> list2 = createAndFillList(5);

    int expected[] = { 5, 4, 3, 2, 1 };
    int index = 0;

    for (int x : list2) {
        assert(x == expected[index]);
        index++;
    }

    assert(index == 5);

    std::forward_list<int> list3 = createAndFillList(3);

    expected[0] = 3;
    expected[1] = 2;
    expected[2] = 1;
    index = 0;

    for (int x : list3) {
        assert(x == expected[index]);
        index++;
    }
    assert(index == 3);

    std::cout << "tested" << std::endl;
}


int main() {
    test_createAndFillList();

    return 0;
}
