#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
    };

    Node* _root;
    int _size;

    Node* insert_recursive(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert_recursive(node->left, value);
        }
        else if (node->data < value) {
            node->right = insert_recursive(node->right, value);
        }

        return node;
    }

    Node* remove_recursive(Node* node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = remove_recursive(node->left, value);
        }
        else if (node->data < value) {
            node->right = remove_recursive(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = node->right;

            while (temp->left != nullptr) {
                temp = temp->left;
            }

            node->data = temp->data;
            node->right = remove_recursive(node->right, temp->data);
        }

        return node;
    }

    Node* find_recursive(Node* node, const T& value) const {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            return find_recursive(node->left, value);
        }

        if (node->data < value) {
            return find_recursive(node->right, value);
        }

        return node;
    }

    void clear_recursive(Node* node) {
        if (node == nullptr) {
            return;
        }

        clear_recursive(node->left);
        clear_recursive(node->right);

        delete node;
    }

    int height_recursive(Node* node) const {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = height_recursive(node->left);
        int rightHeight = height_recursive(node->right);

        return 1 + std::max(leftHeight, rightHeight);
    }

public:
    /// 1. Конструктор по умолчанию
    BinarySearchTree(): _root(nullptr), _size(0) {}

    /// 2. Деструктор
    ~BinarySearchTree() {
        clear();
    }

    /// 3. Конструктор копирования
    BinarySearchTree(const BinarySearchTree& other) : _root(nullptr), _size(0) {

        if (other._root == nullptr) {
            return;
        }

        _root = new Node(other._root->data);
        _size = 1;

        std::queue<std::pair<Node*, Node*>> q;
        q.push({ other._root, _root });

        while (!q.empty()) {
            Node* original = q.front().first;
            Node* copied = q.front().second;
            q.pop();

            if (original->left != nullptr) {
                copied->left = new Node(original->left->data);
                q.push({ original->left, copied->left });
                _size++;
            }

            if (original->right != nullptr) {
                copied->right = new Node(original->right->data);
                q.push({ original->right, copied->right });
                _size++;
            }
        }
    }

    /// 4. Оператор присваивания
    BinarySearchTree& operator=(const BinarySearchTree& other) {
        if (this == &other) {
            return *this;
        }

        BinarySearchTree temp(other);

        std::swap(_root, temp._root);
        std::swap(_size, temp._size);

        return *this;
    }

    /// 5. insert(const T& value) - вставить
    void insert(const T& value) {
        if (find(value)) {
            return;
        }

        _root = insert_recursive(_root, value);
        _size++;
    }

    /// 6. remove(const T& value) - удалить
    void remove(const T& value) {
        if (!find(value)) {
            return;
        }

        _root = remove_recursive(_root, value);
        _size--;
    }

    /// 7. find(const T& value) - найти элемент
    bool find(const T& value) const {
        return find_recursive(_root, value) != nullptr;
    }

    /// 8. inorder() - обход в порядке (выводит на консоль)
    void inorder() const {
        std::stack<Node*> nodes;
        Node* current = _root;

        while (current != nullptr || !nodes.empty()) {
            while (current != nullptr) {
                nodes.push(current);
                current = current->left;
            }

            current = nodes.top();
            nodes.pop();

            std::cout << current->data << " ";
            current = current->right;
        }

        std::cout << std::endl;
    }

    /// 9. preorder() - префиксный обход
    void preorder() const {
        if (_root == nullptr) {
            std::cout << std::endl;
            return;
        }

        std::stack<Node*> nodes;
        nodes.push(_root);

        while (!nodes.empty()) {
            Node* current = nodes.top();
            nodes.pop();

            std::cout << current->data << " ";

            if (current->right != nullptr) {
                nodes.push(current->right);
            }

            if (current->left != nullptr) {
                nodes.push(current->left);
            }
        }

        std::cout << std::endl;
    }

    /// 10. postorder() - постфиксный обход
    void postorder() const {
        if (_root == nullptr) {
            std::cout << std::endl;
            return;
        }

        std::stack<std::pair<Node*, bool>> nodes;
        nodes.push({ _root, false });

        while (!nodes.empty()) {
            Node* current = nodes.top().first;
            bool visited = nodes.top().second;
            nodes.pop();

            if (visited) {
                std::cout << current->data << " ";
            }
            else {
                nodes.push({ current, true });

                if (current->right != nullptr) {
                    nodes.push({ current->right, false });
                }

                if (current->left != nullptr) {
                    nodes.push({ current->left, false });
                }
            }
        }

        std::cout << std::endl;
    }

    /// 11. size() - количество элементов
    int size() const {
        return _size;
    }

    /// 12. height() - высота дерева
    int height() const {
        return height_recursive(_root);
    }

    /// 13. clear() - очистить
    void clear() {
        clear_recursive(_root);
        _root = nullptr;
        _size = 0;
    }

    /// 14. is_empty() - пусто ли
    bool is_empty() const {
        return _root == nullptr;
    }
};

#endif // BINARYSEARCHTREE_H
