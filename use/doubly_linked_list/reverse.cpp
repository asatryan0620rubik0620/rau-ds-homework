#include <iostream>
#include <cassert>

struct ListNode {
    int data;
    ListNode* prev;
    ListNode* next;
};

ListNode* reverse(ListNode* head) {
    ListNode* current = head;
    ListNode* newHead = nullptr;

    while (current != nullptr){
        ListNode* tmp = current->next;

     current->next = current->prev;
        current->prev = tmp;

        newHead = current;
        current = tmp;
    }


    return newHead;
}

void test_reverse() {
    ListNode* a = new ListNode{ 1, nullptr, nullptr };
    ListNode* b = new ListNode{ 2, a, nullptr };
    ListNode* c = new ListNode{ 3, b, nullptr };
    ListNode* d = new ListNode{ 4, c, nullptr };

    a->next = b;
    b->next = c;
    c->next = d;

    ListNode* head = reverse(a);

    assert(head->data == 4);
    assert(head->prev == nullptr);
    assert(head->next->data == 3);
    assert(head->next->prev == head);
    assert(head->next->next->data == 2);
    assert(head->next->next->next->data == 1);
    assert(head->next->next->next->next == nullptr);

    head = reverse(head);

    assert(head->data == 1);
    assert(head->next->data == 2);

    ListNode* single = new ListNode{ 5, nullptr, nullptr };
    assert(reverse(single) == single);

    assert(reverse(nullptr) == nullptr);

    delete single;

    ListNode* current = head;
    while (current != nullptr) 
    {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    std::cout << "tested " << std::endl;

}

int main() {
    test_reverse();

    return 0;
}
