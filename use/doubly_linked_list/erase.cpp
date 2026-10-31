#include <iostream>
#include <cassert>

struct ListNode{
    int data;
    ListNode* prev;
    ListNode* next;
};

void erase(ListNode* node) {
    if (node == nullptr){
        return;
    }

    if (node->prev != nullptr) {
        node->prev->next = node->next;
    }

    if (node->next != nullptr) 
    {
        node->next->prev = node->prev;
    }

    delete node;
}

void test_erase() {
    ListNode* a = new ListNode{ 1, nullptr, nullptr };
    ListNode* b = new ListNode{ 2, a, nullptr };
    ListNode* c = new ListNode{ 3, b, nullptr };
    ListNode* d = new ListNode{ 4, c, nullptr };

    a->next = b;
    b->next = c;
    c->next = d;

    erase(c);
    assert(b->next == d);
    assert(d->prev == b);
    erase(a);
    assert(b->prev == nullptr);

    erase(d);

    assert(b->next == nullptr);
    erase(b);

    erase(nullptr);

    std::cout << "tested" << std::endl;
}

int main() {
    test_erase();

    return 0;
}
