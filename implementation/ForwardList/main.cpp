#include "ForwardList.h"
#include <cassert>
#include <iostream>
#include <limits>

// Реализуйте методы ForwardList<T>:
//   1. ForwardList()                   - конструктор
//   2. ~ForwardList()                  - деструктор
//   3. ForwardList(const &)            - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push_front(const T&)            - добавить в начало
//   6. pop_front()                     - удалить с начала
//   7. front()                         - первый элемент
//   8. insert_after(Node*, const T&)   - вставить после узла
//   9. erase_after(Node*)              - удалить после узла
//  10. clear()                         - очистить
//  11. reverse()                       - развернуть
//  12. size()                          - размер
//  13. empty()                         - пусто ли
//  14. begin()                         - начало списка

void test_push_front() {
    ForwardList<int> list;

    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);

    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);

    std::cout << "test_push_front passed" << std::endl;
}

void test_copy_constructor() {
    ForwardList<int> empty_list;
    ForwardList<int> copy_empty(empty_list);
    assert(copy_empty.empty() == true);

    ForwardList<int> list1;
    list1.push_front(std::numeric_limits<int>::max());
    ForwardList<int> copy_list1(list1);
    assert(copy_list1.size() == 1);
    assert(copy_list1.front() == std::numeric_limits<int>::max());

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    ForwardList<int> list1;
    ForwardList<int> list2;
    list2 = list1;
    assert(list2.empty() == true);


    list1.push_front(10);
    list1.push_front(std::numeric_limits<int>::min());
    list2 = list1;
    assert(list2.size() == 2);
    assert(list2.front() == std::numeric_limits<int>::min());

    std::cout << "test_assignment_operator passed" << std::endl;
}
void test_pop_front() {
    ForwardList<int> list;

    list.push_front(10);
    list.pop_front();
    assert(list.empty() == true);

    list.push_front(22);
    list.push_front(std::numeric_limits<int>::max());
    list.pop_front();
    assert(list.size() == 1);
    assert(list.front() == 22);

    std::cout << "test_pop_front passed" << std::endl;
}

void test_front() {
    ForwardList<int> list;

    list.push_front(55);
    assert(list.front() == 55);

    list.push_front(std::numeric_limits<int>::max());
    assert(list.front() == std::numeric_limits<int>::max());
    std::cout << "test_front passed" << std::endl;
}

void test_insert_after() {
    ForwardList<int> list;

    list.push_front(10);
    auto node = list.begin();

    list.insert_after(node, std::numeric_limits<int>::max());
    assert(list.size() == 2);
    assert(node->next->data == std::numeric_limits<int>::max());

    std::cout << "test_insert_after passed" << std::endl;
}

void test_erase_after() {
    ForwardList<int> list;

    list.push_front(30);
    list.push_front(20);
    auto node = list.begin(); 
    list.erase_after(node);
    assert(list.size() == 1);
    assert(node->next == nullptr);

    std::cout << "test_erase_after passed" << std::endl;
}

void test_clear() {
    ForwardList<int> list;

    list.clear();
    assert(list.empty() == true);
    list.push_front(1);
    list.push_front(std::numeric_limits<int>::max());
    list.clear();
    assert(list.empty() == true);
    assert(list.size() == 0);

    std::cout << "test_clear passed" << std::endl;
}

void test_reverse() {
    ForwardList<int> list;

    list.push_front(5);
    list.reverse();
    assert(list.front() == 5);
    list.clear();
    list.push_front(1);
    list.push_front(2);
    list.push_front(3); 
    list.reverse();     
    assert(list.front() == 1);
    std::cout << "test_reverse passed" << std::endl;
}

void test_size() {
    ForwardList<int> list;
    assert(list.size() == 0);

    list.push_front(10);
    assert(list.size() == 1);

    std::cout << "test_size passed" << std::endl;
}

void test_empty() {
    ForwardList<int> list;
    assert(list.empty() == true);

    list.push_front(10);
    assert(list.empty() == false);

    std::cout << "test_empty passed" << std::endl;
}

void test_begin() {
    ForwardList<int> list;
    assert(list.begin() == nullptr);

    list.push_front(56);
    assert(list.begin() != nullptr);
    assert(list.begin()->data == 56);
    std::cout << "terst_bwgin passed" << std::endl;
}




int main() {
    std::cout << "Running ForwardList tests" << std::endl;
    test_copy_constructor();
    test_assignment_operator();
    test_push_front();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_size();
    test_empty();
    test_begin();
    std::cout << "All tests passed" << std::endl;
    return 0;
}
