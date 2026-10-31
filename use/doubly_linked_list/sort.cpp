#include <iostream>
#include <cassert>

struct ListNode {
    int data;
    ListNode* prev;
    ListNode* next;
};


void sort(ListNode* head) {
    bool swayp = true;

    while (swayp) 
    {
        swayp = false;

        for (auto current = head; current != nullptr && current->next != nullptr; current = current->next){
            if (current->data > current->next->data) {
                int tmp = current->data;
                current->data = current->next->data;
                current->next->data = tmp;

                swayp = true;
            }
        }
    }
}


void test_sort() {
    ListNode* a = new ListNode{ 5, nullptr, nullptr };
    ListNode* b = new ListNode{ 2, a, nullptr };
    ListNode* c = new ListNode{ 4, b, nullptr };
    ListNode* d = new ListNode{ 1, c, nullptr };
    ListNode* e = new ListNode{ 3, d, nullptr };

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    sort(a);

    assert(a->data == 1);
    assert(a->next->data == 2);
    assert(a->next->next->data == 3);
    assert(a->next->next->next->data == 4);
    assert(a->next->next->next->next->data == 5);

    ListNode* single = new ListNode{ 7, nullptr, nullptr };
    sort(single);
    assert(single->data == 7);

    sort(nullptr);

    ListNode* empty = nullptr;
    assert(empty == nullptr);

    delete single;

    ListNode* current = a;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    std::cout << "tested " << std::endl;
}

int main() {
    test_sort();

    return 0;
}
