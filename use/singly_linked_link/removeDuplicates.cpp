#include <forward_list>
#include <iostream>
#include <cassert>

void removeDuplicates(std::forward_list<int>& list) {
    auto it = list.begin();

  
    while (it != list.end()) 
    {
        auto next = std::next(it);

        while ( next != list.end() && *it == *next){
            next = list.erase_after(it);
        }

        ++it;
    }
}

void test_removeDuplicates() {
    std::forward_list<int> list1 = { 1, 1, 2 };
    removeDuplicates(list1);
    assert(list1 == std::forward_list<int>({ 1, 2 }));

    std::forward_list<int> list2 = { 1, 1, 2, 3, 3 };
    removeDuplicates(list2);
    assert(list2 == std::forward_list<int>({ 1, 2, 3 }));

    std::forward_list<int> list3 = { 1, 1, 1, 1 };
    removeDuplicates(list3);
    assert(list3 == std::forward_list<int>({ 1 }));

    std::forward_list<int> list4 = { 1, 2, 3, 4 };
    removeDuplicates(list4);
    assert(list4 == std::forward_list<int>({ 1, 2, 3, 4 }));

    std::forward_list<int> list5;
    removeDuplicates(list5);
    assert(list5.empty());


    std::forward_list<int> list6 = { 5 };
    removeDuplicates(list6);
    assert(list6 == std::forward_list<int>({ 5 }));

    std::forward_list<int> list7 = { -3, -3, -1, 0, 0, 2, 2 };
    removeDuplicates(list7);
    assert(list7 == std::forward_list<int>({ -3, -1, 0, 2 }));

    std::cout << "tested" << std::endl;
}


int main() {
    test_removeDuplicates();

    return 0;
}
