#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* next;
};


bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

void test_hasCycle() {
    Node a = { 1, nullptr };
    Node b = { 2, nullptr };
    Node c = { 3, nullptr };
    Node d = { 4, nullptr };

    a.next = &b;
    b.next = &c;
    c.next = &d;

    assert(!hasCycle(&a));

    d.next = &b;

    assert(hasCycle(&a));

    Node single = { 1, nullptr };
    assert(!hasCycle(&single));

    single.next = &single;
    assert(hasCycle(&single));

    assert(!hasCycle(nullptr));

    std::cout << "tested " << std::endl;
}

int main() {
    test_hasCycle();

    return 0;
}
