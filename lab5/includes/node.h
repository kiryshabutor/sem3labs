#pragma once

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;

    explicit Node(const T& value) : data(value) {}
};

