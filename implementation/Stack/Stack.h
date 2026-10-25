#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
private:
    T* _data;
    int _capacity;
    int _size;

    void expand() {
        int newCapacity = _capacity * 2;
        T* newData = new T[newCapacity];

        for (int i = 0; i < _size; i++) {
            newData[i] = _data[i];
        }

        delete[] _data;
        _data = newData;
        _capacity = newCapacity;
    }

public:
    /// 1. Конструктор по умолчанию
    Stack() {
        _capacity = 2;
        _size = 0;
        _data = new T[_capacity];
    }

    /// 2. Деструктор
    ~Stack() {
        delete[] _data;
    }

    /// 3. Конструктор копирования
    Stack(const Stack& other) {
        _capacity = other._capacity;
        _size = other._size;
        _data = new T[_capacity];

        for (int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    /// 4. Оператор присваивания
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            T* newData = new T[other._capacity];

            for (int i = 0; i < other._capacity; i++) {
                newData[i] = other._data[i];
            }

            delete[] _data;

            _data = newData;
            _capacity = other._capacity;
            _size = other._size;
        }

        return *this;
    }

    /// 5. push(const T& x) - добавить в стек
    void push(const T& x) {
        if (_size == _capacity) {
            expand();
        }

        _data[_size] = x;
        _size++;
    }

    /// 6. pop() - удалить с вершины
    void pop() {
        if (_size > 0) {
            _size--;
        }
    }

    /// 7. top() - вершина стека
    T& top() {
        return _data[_size - 1];
    }
    const T& top() const {
        return _data[_size - 1];
    }

    /// 8. size() - количество элементов
    int size() const {
        return _size;
    }

    /// 9. capacity() - вместимость
    int capacity() const {
        return _capacity;
    }

    /// 10. is_empty() - пуст ли
    bool is_empty() const {
        return _size == 0;
    }

    /// 11. clear() - очистить
    void clear() {
        _size = 0;
    }

    /// 12. peek() - посмотреть вершину без удаления
    T& peek() {
        return _data[_size - 1];
    }
    const T& peek() const {
        return _data[_size - 1];
    }
};

#endif // STACK_H
