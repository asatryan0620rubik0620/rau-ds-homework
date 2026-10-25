#include "Stack.h"
#include <cassert>
#include <iostream>

void test_push() {
    Stack<int> s;

    s.push(5);
    assert(s.size() == 1);
    assert(s.top() == 5);

    s.push(10);
    s.push(15);
    assert(s.size() == 3);
    assert(s.top() == 15);
}

void test_pop() {
    Stack<int> s;

    s.push(5);
    s.push(10);
    s.pop();

    assert(s.size() == 1);
    assert(s.top() == 5);

    s.pop();
    assert(s.is_empty());
}

void test_top_and_peek() {
    Stack<int> s;

    s.push(10);
    s.push(20);

    assert(s.top() == 20);
    assert(s.peek() == 20);
    assert(s.size() == 2);
}

void test_capacity() {
    Stack<int> s;

    assert(s.capacity() >= 1);

    int initialCapacity = s.capacity();

    for (int i = 0; i < initialCapacity + 1; i++) {
        s.push(i);
    }

    assert(s.capacity() > initialCapacity);
}

void test_clear() {
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.clear();

    assert(s.size() == 0);
    assert(s.is_empty());
}

void test_copy_constructor() {
    Stack<int> s;
    s.push(5);
    s.push(10);

    Stack<int> copy(s);

    assert(copy.size() == 2);
    assert(copy.top() == 10);

    copy.push(15);

    assert(copy.size() == 3);
    assert(s.size() == 2);
}

void test_assignment() {
    Stack<int> s;
    s.push(5);
    s.push(10);

    Stack<int> copy;
    copy.push(100);
    copy = s;

    assert(copy.size() == 2);
    assert(copy.top() == 10);

    copy.pop();

    assert(copy.top() == 5);
    assert(s.top() == 10);
}

int main() {
    test_push();
    test_pop();
    test_top_and_peek();
    test_capacity();
    test_clear();
    test_copy_constructor();
    test_assignment();

    std::cout << "All tests passed " << std::endl;
    return 0;
}
