#include "BinarySearchTree.h"
#include <iostream>
#include <cassert>
#include <climits>
#include <sstream>

// Реализуйте методы BinarySearchTree<T>:
//   1. BinarySearchTree()              - конструктор
//   2. ~BinarySearchTree()             - деструктор
//   3. BinarySearchTree(const &)       - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. insert(const T&)                - вставить
//   6. remove(const T&)                - удалить
//   7. find(const T&)                  - найти
//   8. inorder()                       - обход в порядке
//   9. preorder()                      - префиксный обход
//  10. postorder()                     - постфиксный обход
//  11. size()                          - размер
//  12. height()                        - высота
//  13. clear()                         - очистить
//  14. is_empty()                      - пусто ли

void test_insert() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    assert(bst.size() == 1);
    assert(bst.find(50));

    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    assert(bst.size() == 5);
    assert(bst.find(30));
    assert(bst.find(70));

    std::cout << "test_insert passed" << std::endl;
}

void test_constructor() {
    BinarySearchTree<int> bst;

    assert(bst.is_empty());
    assert(bst.size() == 0);
    assert(bst.height() == 0);
    assert(!bst.find(10));

    bst.insert(10);


    assert(!bst.is_empty());
    assert(bst.size() == 1);
    assert(bst.height() == 1);

    std::cout << "test_construstor passed" << std::endl;
}

void test_copy_constructor() {
    BinarySearchTree<int> empty;
    BinarySearchTree<int> empty_copy(empty);

    assert(empty_copy.is_empty());
    assert(empty_copy.size() == 0);
    assert(empty_copy.height() == 0);

    BinarySearchTree<int> single;
    single.insert(10);

    BinarySearchTree<int> single_copy(single);

    assert(single_copy.size() == 1);
    assert(single_copy.find(10));
    assert(single_copy.height() == 1);

    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(INT_MIN);
    bst.insert(INT_MAX);

    BinarySearchTree<int> copy(bst);

    assert(copy.size() == 7);
    assert(copy.height() == bst.height());
    assert(copy.find(50));
    assert(copy.find(30));
    assert(copy.find(70));
    assert(copy.find(INT_MIN));
    assert(copy.find(INT_MAX));

    copy.insert(100);

    assert(copy.size() == 8);
    assert(!bst.find(100));
    assert(bst.size() == 7);

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    BinarySearchTree<int> empty;
    BinarySearchTree<int> empty_copy;

    empty_copy = empty;

    assert(empty_copy.is_empty());
    assert(empty_copy.size() == 0);

    BinarySearchTree<int> single;
    single.insert(10);

    BinarySearchTree<int> single_copy;
    single_copy = single;

    assert(single_copy.size() == 1);
    assert(single_copy.find(10));

    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(INT_MIN);
    bst.insert(INT_MAX);

    BinarySearchTree<int> copy;
    copy.insert(999);
    copy = bst;

    assert(copy.size() == 7);
    assert(copy.find(50));
    assert(copy.find(INT_MIN));
    assert(copy.find(INT_MAX));
    assert(!copy.find(999));

    copy.insert(100);

    assert(!bst.find(100));
    assert(bst.size() == 7);

    copy = copy;

    assert(copy.size() == 8);
    assert(copy.find(100));

    std::cout << "test_assignment_operator passed" << std::endl;
}

void test_remove() {
    BinarySearchTree<int> empty;

    empty.remove(10);

    assert(empty.is_empty());
    assert(empty.size() == 0);

    BinarySearchTree<int> single;

    single.insert(10);
    single.remove(10);

    assert(single.is_empty());
    assert(single.size() == 0);
    assert(!single.find(10));

    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    assert(bst.size() == 7);

    bst.remove(20);

    assert(bst.size() == 6);
    assert(!bst.find(20));

    bst.remove(30);

    assert(bst.size() == 5);
    assert(!bst.find(30));
    assert(bst.find(40));

    bst.remove(70);

    assert(bst.size() == 4);
    assert(!bst.find(70));
    assert(bst.find(60));
    assert(bst.find(80));

    bst.remove(50);

    assert(bst.size() == 3);
    assert(!bst.find(50));

    bst.remove(1000);

    assert(bst.size() == 3);

    bst.insert(INT_MIN);
    bst.insert(INT_MAX);

    assert(bst.find(INT_MIN));
    assert(bst.find(INT_MAX));

    bst.remove(INT_MIN);
    bst.remove(INT_MAX);

    assert(!bst.find(INT_MIN));
    assert(!bst.find(INT_MAX));

    std::cout << "test_remove passed" << std::endl;
}

void test_find() {
    BinarySearchTree<int> bst;

    assert(!bst.find(10));
    assert(!bst.find(INT_MIN));
    assert(!bst.find(INT_MAX));

    bst.insert(10);

    assert(bst.find(10));
    assert(!bst.find(20));

    bst.insert(5);
    bst.insert(15);
    bst.insert(INT_MIN);
    bst.insert(INT_MAX);

    assert(bst.find(5));
    assert(bst.find(15));
    assert(bst.find(INT_MIN));
    assert(bst.find(INT_MAX));

    assert(!bst.find(100));
    std::cout << "test_find passed" << std::endl;
}

void test_inorder() {
    BinarySearchTree<int> empty;

    std::ostringstream output;
    std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());

    empty.inorder();

    std::cout.rdbuf(old_cout);

    assert(output.str() == "\n");

    BinarySearchTree<int> single;
    single.insert(10);

    output.str("");
    output.clear();

    old_cout = std::cout.rdbuf(output.rdbuf());

    single.inorder();

    std::cout.rdbuf(old_cout);

    assert(output.str() == "10 \n");

    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(INT_MIN);
    bst.insert(INT_MAX);

    output.str("");
    output.clear();

    old_cout = std::cout.rdbuf(output.rdbuf());

    bst.inorder();

    std::cout.rdbuf(old_cout);

    assert(output.str() == "-2147483648 20 30 40 50 70 2147483647 \n");

    std::cout << "test_inorder passed" << std::endl;
}

void test_preorder() {
    BinarySearchTree<int> empty;

    std::ostringstream output;
    std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());

    empty.preorder();

    std::cout.rdbuf(old_cout);

    assert(output.str() == "\n");

    BinarySearchTree<int> single;
    single.insert(10);

    output.str("");
    output.clear();

    old_cout = std::cout.rdbuf(output.rdbuf());

    single.preorder();

    std::cout.rdbuf(old_cout);

    assert(output.str() == "10 \n");

    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    output.str("");
    output.clear();

    old_cout = std::cout.rdbuf(output.rdbuf());

    bst.preorder();

    std::cout.rdbuf(old_cout);

    assert(output.str() == "50 30 20 40 70 \n");

    std::cout << "test_preorder passed" << std::endl;
}

void test_postorder() {
    BinarySearchTree<int> empty;

    std::ostringstream output;
    std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());

    empty.postorder();

    std::cout.rdbuf(old_cout);

    assert(output.str() == "\n");

    BinarySearchTree<int> single;
    single.insert(10);

    output.str("");
    output.clear();

    old_cout = std::cout.rdbuf(output.rdbuf());

    single.postorder();

    std::cout.rdbuf(old_cout);

    assert(output.str() == "10 \n");

    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    output.str("");
    output.clear();

    old_cout = std::cout.rdbuf(output.rdbuf());

    bst.postorder();

    std::cout.rdbuf(old_cout);

    assert(output.str() == "20 40 30 70 50 \n");

    std::cout << "test_postorder passed" << std::endl;
}

void test_size() {
    BinarySearchTree<int> bst;

    assert(bst.size() == 0);

    bst.insert(10);

    assert(bst.size() == 1);

    bst.insert(20);
    bst.insert(5);

    assert(bst.size() == 3);

    bst.insert(10);

    assert(bst.size() == 3);

    bst.remove(20);

    assert(bst.size() == 2);

    bst.remove(100);

    assert(bst.size() == 2);

    bst.clear();

    assert(bst.size() == 0);

    bst.insert(INT_MIN);
    bst.insert(INT_MAX);

    assert(bst.size() == 2);

    std::cout << "test_size passed" << std::endl;
}

void test_height() {
    BinarySearchTree<int> bst;

    assert(bst.height() == 0);

    bst.insert(10);

    assert(bst.height() == 1);

    bst.insert(5);

    assert(bst.height() == 2);

    bst.insert(15);

    assert(bst.height() == 2);

    bst.insert(2);

    assert(bst.height() == 3);

    bst.insert(1);

    assert(bst.height() == 4);

    bst.clear();
    assert(bst.height() == 0);

        bst.insert(INT_MIN);
    bst.insert(INT_MAX);

    assert(bst.height() == 2);

    std::cout << "test_height passed" << std::endl;
}

void test_clear() {
    BinarySearchTree<int> bst;

    bst.clear();

    assert(bst.is_empty());
    assert(bst.size() == 0);
    assert(bst.height() == 0);

    bst.insert(10);

    bst.clear();

    assert(bst.is_empty());
    assert(bst.size() == 0);
    assert(bst.height() == 0);

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    assert(bst.size() == 5);

    bst.clear();

    assert(bst.is_empty());
    assert(bst.size() == 0);
    assert(bst.height() == 0);
    assert(!bst.find(50));

    bst.clear();

    assert(bst.is_empty());

    std::cout << "test_clar passed" << std::endl;
}

void test_is_empty() {
    BinarySearchTree<int> bst;

    assert(bst.is_empty());

    bst.insert(10);

    assert(!bst.is_empty());

    bst.insert(20);

    assert(!bst.is_empty());

    bst.remove(10);

    assert(!bst.is_empty());

    bst.remove(20);

    assert(bst.is_empty());

    bst.insert(INT_MIN);
    bst.insert(INT_MAX);

    assert(!bst.is_empty());

    bst.clear();

    assert(bst.is_empty());

    std::cout << "test_is_empty passed" << std::endl;
}

int main() {
    std::cout << "Running BinarySearchTree tests" << std::endl;
    test_insert();
    test_constructor();
    test_copy_constructor();
    test_assignment_operator();
    test_remove();
    test_find();
    test_inorder();
    test_preorder();
    test_postorder();
    test_size();
    test_height();
    test_clear();
    test_is_empty();

    std::cout << "All tests passed" << std::endl;
    return 0;
}
