#pragma once
#include <cstddef>
#include <iterator>

template <typename T>
class DoublyLinkedList {
    struct Node {
        T data{};
        Node* prev = nullptr;
        Node* next = nullptr;

        explicit Node(const T& value) : data(value) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    size_t size_ = 0;

public:
    DoublyLinkedList() = default;
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList(DoublyLinkedList&& other) noexcept;
    ~DoublyLinkedList();

    DoublyLinkedList& operator=(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;

    class Iterator {
        Node* current = nullptr;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator() = default;
        explicit Iterator(Node* ptr) : current(ptr) {}

        reference operator*() const { return current->data; }

        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        Iterator& operator--() {
            if (current) current = current->prev;
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const = default;

        friend class DoublyLinkedList;
    };

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }

    void pushBack(const T& value);
    void pushFront(const T& value);
    void popBack();
    void popFront();
    void clear();

    bool empty() const noexcept { return size_ == 0; }
    size_t size() const noexcept { return size_; }
};

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other) {
    for (auto curr = other.head; curr != nullptr; curr = curr->next)
        pushBack(curr->data);
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList&& other) noexcept
    : head(other.head), tail(other.tail), size_(other.size_) {
    other.head = other.tail = nullptr;
    other.size_ = 0;
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& other) {
    if (this == &other)
        return *this;

    clear();
    for (auto curr = other.head; curr != nullptr; curr = curr->next)
        pushBack(curr->data);
    return *this;
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList&& other) noexcept {
    if (this == &other)
        return *this;

    clear();
    head = other.head;
    tail = other.tail;
    size_ = other.size_;

    other.head = other.tail = nullptr;
    other.size_ = 0;
    return *this;
}

template <typename T>
void DoublyLinkedList<T>::pushBack(const T& value) {
    auto newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++size_;
}

template <typename T>
void DoublyLinkedList<T>::pushFront(const T& value) {
    auto newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    ++size_;
}

template <typename T>
void DoublyLinkedList<T>::popBack() {
    if (!tail)
        return;

    auto tmp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;

    delete tmp;
    --size_;
}

template <typename T>
void DoublyLinkedList<T>::popFront() {
    if (!head)
        return;

    auto tmp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;

    delete tmp;
    --size_;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    auto curr = head;
    while (curr) {
        auto tmp = curr;
        curr = curr->next;
        delete tmp;
    }
    head = tail = nullptr;
    size_ = 0;
}
