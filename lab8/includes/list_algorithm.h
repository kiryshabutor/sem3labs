#pragma once
#include "doubly_linked_list.h"
#include <algorithm>
#include <ranges>

template <typename T>
class ListAlgorithm {
public:
    bool find(const DoublyLinkedList<T>& list, const T& value) const;
    void sort(DoublyLinkedList<T>& list) const;
};

template <typename T>
bool ListAlgorithm<T>::find(const DoublyLinkedList<T>& list, const T& value) const {
    // безопасно и совместимо со всеми компиляторами
    for (auto it = list.begin(); it != list.end(); ++it)
        if (*it == value)
            return true;
    return false;

    // если твой компилятор поддерживает ranges с кастомными итераторами — можно заменить на:
    // return std::ranges::any_of(list, [&](const T& elem) { return elem == value; });
}

template <typename T>
void ListAlgorithm<T>::sort(DoublyLinkedList<T>& list) const {
    if (list.size() < 2)
        return;

    bool swapped;
    do {
        swapped = false;
        for (auto it = list.begin(); it != list.end(); ++it) {
            auto next = it;
            ++next;
            if (next != list.end() && *next < *it) {
                std::swap(*it, *next);
                swapped = true;
            }
        }
    } while (swapped);
}
