#pragma once
#include "node.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    size_t size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;

    SinglyLinkedList(SinglyLinkedList&&) = delete;
    SinglyLinkedList& operator=(SinglyLinkedList&&) = delete;

    void pushFront(const T& value);
    void pushBack(const T& value);
    void popFront();
    void clear();

    bool isEmpty() const;
    size_t getSize() const;

    void print() const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
};


#include "../src/singly_linked_list.tpp"
