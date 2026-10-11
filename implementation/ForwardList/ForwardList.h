#pragma once
#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <stdexcept>

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* _head;
    int _size;

public:
    /// 1. Конструктор по умолчанию
    ForwardList() : _head(nullptr), _size(0){}

    /// 2. Деструктор
    ~ForwardList() {
        clear();
    }

    /// 3. Конструктор копирования
    ForwardList(const ForwardList& other) : _head(nullptr), _size(0) {
        if (other._head == nullptr) {
            return;
        }
        Node* current = other._head;
        Node** tail = &_head;
        while (current != nullptr) {
            *tail = new Node(current->data);
            tail = &((*tail)->next);
            current = current->next;
            _size++;
        }
    }

    /// 4. Оператор присваивания
    ForwardList& operator=(const ForwardList& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        if (other._head != nullptr) {
            Node* current = other._head;
            Node** tail = &_head;
            while (current != nullptr) {
                *tail = new Node(current->data);
                tail = &((*tail)->next);
                current = current->next;
                _size++;
            }
        }
        return *this;
    }

    /// 5. push_front(const T& x) - добавить в начало
    void push_front(const T& x) {
        Node* newNode = new Node(x);
        newNode->next = _head;
        _head = newNode;
        _size++;
    }

    /// 6. pop_front() - удалить с начала
    void pop_front() {
        if (_head == nullptr) {
            return;
        }
        Node* temp = _head;
        _head = _head->next;
        delete temp;
        _size--;
    }

    /// 7. front() - первый элемент
    T& front() {
        if (_head == nullptr) {
            throw std::out_of_range("ForwardList is empty");
        }
        return _head->data;
    }
    const T& front() const {
        if (_head == nullptr) {
            throw std::out_of_range("ForwardList is empty");
        }
        return _head->data;
    }

    /// 8. insert_after(Node* node, const T& value) - вставить после узла
    void insert_after(Node* node, const T& value) {
        if (node == nullptr) {
            throw std::out_of_range("ForwardList is empty");
        }
        Node* newNode = new Node(value);
        newNode->next = node->next;
        node->next = newNode;
        _size++;
    }

    /// 9. erase_after(Node* node) - удалить после узла
    void erase_after(Node* node) {
        if (node == nullptr) {
            throw std::out_of_range("ForwardList is empty");
        }
        Node* target = node->next;
        if (target == nullptr) {
            return;
        }
        node->next = target->next;
        delete target;
        _size--;
    }

    /// 10. clear() - очистить
    void clear() {
        while (_head != nullptr) {
            Node* temp = _head;
            _head = _head->next;
            delete temp;
        }
        _size = 0;
    }

    /// 11. reverse() - развернуть
    void reverse() {
        Node* prev = nullptr;
        Node* current = _head;
        while(current != nullptr) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        _head = prev;
    }

    /// 12. size() - количество элементов
    int size() const {
        return _size;
    }

    /// 13. empty() - пуст ли
    bool empty() const {
        return _head == nullptr;
    }

    /// 14. begin() - начало списка
    Node* begin() {
        return _head;
    }
    Node* begin() const {
        return _head;
    }
};

#endif // FORWARDLIST_H
