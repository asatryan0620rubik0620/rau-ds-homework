#include "Vector.h"
#include <cassert>
#include <iostream>

// Реализуйте методы Vector<T>:
//
//   1. Vector()                        - конструктор по умолчанию
//   2. ~Vector()                       - деструктор
//   3. Vector(const Vector& other)     - конструктор копирования
//   4. operator=(const Vector& other)  - оператор присваивания
//   5. push_back(const T& x)           - добавить в конец
//   6. pop_back()                      - удалить с конца
//   7. operator[](int index)           - доступ по индексу
//   8. back()                          - последний элемент
//   9. insert(int pos, const T& val)   - вставить
//  10. erase(int pos)                  - удалить
//  11. swap(Vector& other)             - обменять содержимое
//  12. clear()                         - очистить
//  13. resize(int new_size)            - изменить размер
//  14. front()                         - первый элемент
//
// Напишите для каждой функции один тест:
//   void test_<название_функции>() { ... }
//
// Каждый тест должен проверять:
//   - Нормальный случай
//   - Граничные случаи


void test_push_back() {
    Vector<int> v;
    
    v.push_back(5);
    assert(v.size() == 1);
    assert(v[0] == 5);
    
    v.push_back(10);
    v.push_back(15);
    assert(v.size() == 3);
    assert(v.back() == 15);
    
    std::cout << "test_push_back passed" << std::endl;
}

void test_copy_constructor() {
    Vector<int> empty;
    Vector<int> copy_empty(empty);
    assert(copy_empty.size() == 0);

    Vector<int> v;
    v.push_back(10);
    Vector<int> copy(v);
    assert(copy.size() == 1);
    assert(copy[0] == 10);

    Vector<int> v1;
    v1.push_back(std::numeric_limits<int>::max());
    v1.push_back(20);
    Vector<int> copy_v1(v1);
    assert(copy_v1.size() == 2);
    assert(copy_v1[0] == std::numeric_limits<int>::max());
    assert(copy_v1[1] == 20);

    std::cout << "test_copy_constructor passed " << std::endl;
}

void test_assignment_operator() {
    Vector<int> v1;
    Vector<int> v2;
    v2 = v1;
    assert(v2.size() == 0);

    Vector<int> v;
    v.push_back(42);
    v1 = v;
    assert(v1.size() == 1);
    assert(v1[0] == 42);

    Vector<int> v3;
    v3.push_back(std::numeric_limits<int>::min());
    v3.push_back(100);
    v2 = v3;
    assert(v2.size() == 2);
    assert(v2[0] == std::numeric_limits<int>::min());
    assert(v2[1] == 100);

    std::cout << "test_assignment_operator  passed" << std::endl;
}

void test_pop_back() {
    Vector<int> v;

    v.push_back(10);
    assert(v.size() == 1);
    v.pop_back();
    assert(v.size() == 0);

    v.push_back(std::numeric_limits<int>::max());
    v.push_back(56);
    v.push_back(20);
    assert(v.size() == 3);

    v.pop_back();
    assert(v.size() == 2);
    assert(v.back() == 56);

    std::cout << "test_pop_back passed" << std::endl;
}

void test_operator_bracket() {
    Vector<int> v;

    v.push_back(5);
    assert(v[0] == 5);

    v.push_back(std::numeric_limits<int>::max());
    v.push_back(30);
    assert(v[1] == std::numeric_limits<int>::max());
    assert(v[2] == 30);

    v[2] = std::numeric_limits<int>::min();
    assert(v[2] == std::numeric_limits<int>::min());

    std::cout << "test_operator_bracket passed" << std::endl;
}

void test_back() {
    Vector<int> v;

    v.push_back(77);
    assert(v.back() == 77);

    v.push_back(std::numeric_limits<int>::max());
    assert(v.back() == std::numeric_limits<int>::max());

    std::cout << "test_backpassed" << std::endl;
}

void test_front() {
    Vector<int> v;

    v.push_back(88);
    assert(v.front() == 88);

    v.push_back(std::numeric_limits<int>::max());
    assert(v.front() == 88);

    std::cout << "test_front passed" << std::endl;
}

void test_insert() {
    Vector<int> v;

    v.insert(0, 11);
    assert(v.size() == 1);
    assert(v[0] == 11);

    v.insert(0, 5);
    assert(v[0] == 5);
    assert(v[1] == 11);

    v.insert(1, std::numeric_limits<int>::max());
    assert(v.size() == 3);
    assert(v[1] == std::numeric_limits<int>::max());

    std::cout << "test_insert passed" << std::endl;
}

void test_erase() {
    Vector<int> v;

    v.push_back(100);
    v.erase(0);
    assert(v.size() == 0);

  v.push_back(10);
    v.push_back(std::numeric_limits<int>::max());
    v.push_back(30);

    v.erase(1); 
    assert(v.size() == 2);
    assert(v[0] == 10);
    assert(v[1] == 30);

    std::cout << "test_erase passed" << std::endl;
}

void test_swap() {
    Vector<int> v1;
    Vector<int> v2;

    v1.swap(v2);
    assert(v1.size() == 0);
    assert(v2.size() == 0);

    v1.push_back(1);
    v1.swap(v2);
    assert(v1.size() == 0);
    assert(v2.size() == 1);
    assert(v2[0] == 1);

    v1.push_back(std::numeric_limits<int>::max());
    v1.push_back(99);
    v1.swap(v2);
    assert(v1.size() == 1);
    assert(v1[0] == 1);
    assert(v2.size() == 2);
    assert(v2[0] == std::numeric_limits<int>::max());

    std::cout << "test_swap passed" << std::endl;
}

void test_clear() {
    Vector<int> v;
    v.clear();
    assert(v.size() == 0);

    v.push_back(5);
    v.clear();
    assert(v.size() == 0);

    v.push_back(std::numeric_limits<int>::max());
    v.push_back(std::numeric_limits<int>::min());
    assert(v.size() == 2);
    v.clear();
    assert(v.size() == 0);

    std::cout << "test_clear passed" << std::endl;
}

void test_resize() {
    Vector<int> v;

    v.resize(0);
    assert(v.size() == 0);

    v.resize(1);
    assert(v.size() == 1);

    v.resize(100);
    assert(v.size() == 100);

    v.resize(5);
    assert(v.size() == 5);

    std::cout << "test_resize passed" << std::endl;
}


int main() {
    std::cout << "Running Vector tests" << std::endl;
    
    test_push_back();
    test_pop_back();
    test_operator_bracket();
    test_back();
    test_front();
    test_insert();
    test_erase();
    test_swap();
    test_clear();
    test_resize();
    test_copy_constructor();
    test_assignment_operator();
    
    std::cout << "All tests passed" << std::endl;
    return 0;
}
