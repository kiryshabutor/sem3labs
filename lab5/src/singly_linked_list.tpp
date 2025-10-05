#pragma once
#include <iostream>
using namespace std;

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), size(0) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template <typename T>
void SinglyLinkedList<T>::pushFront(const T& value) {
    auto* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
    ++size;
}

template <typename T>
void SinglyLinkedList<T>::pushBack(const T& value) {
    auto* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
    }
    ++size;
}

template <typename T>
void SinglyLinkedList<T>::popFront() {
    if (isEmpty()) throw runtime_error("List is empty.");
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    --size;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
size_t SinglyLinkedList<T>::getSize() const {
    return size;
}

template <typename T>
void SinglyLinkedList<T>::print() const {
    if (isEmpty()) {
        cout << "(empty list)\n";
        return;
    }

    Node<T>* current = head;
    cout << "List: ";
    while (current) {
        cout << current->data;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
T& SinglyLinkedList<T>::front() {
    if (isEmpty()) throw runtime_error("List is empty.");
    return head->data;
}

template <typename T>
const T& SinglyLinkedList<T>::front() const {
    if (isEmpty()) throw runtime_error("List is empty.");
    return head->data;
}

template <typename T>
T& SinglyLinkedList<T>::back() {
    if (isEmpty()) throw runtime_error("List is empty.");
    Node<T>* current = head;
    while (current->next)
        current = current->next;
    return current->data;
}

template <typename T>
const T& SinglyLinkedList<T>::back() const {
    if (isEmpty()) throw runtime_error("List is empty.");
    Node<T>* current = head;
    while (current->next)
        current = current->next;
    return current->data;
}
