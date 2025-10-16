#pragma once

#include "doubly_linked_list.h"
#include "list_algorithm.h"
#include "input_utils.h"
#include <iostream>
#include <type_traits>
#include <string>

template <typename T>
class App {
    DoublyLinkedList<T> list_;
    ListAlgorithm<T> algorithm_;

    void createList();
    void addListElement();
    void removeListElement();
    void showList();
    void sortList();
    void searchListElement();
    void clearList();

public:
    App();
    void run();
};

template <typename T>
App<T>::App() {
    std::cout << "\nYou successfully chose a type of list!\n";
}

template <typename T>
void App<T>::createList() {
    if (!list_.empty()) {
        std::cout << "\nError: list already exists!\n";
        return;
    }

    int size = safeInputInt("Enter initial size of list: ");
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter element " << i + 1 << ": ";
        if constexpr (std::is_same_v<T, int>) {
            list_.pushBack(safeInputInt(""));
        } else if constexpr (std::is_same_v<T, double>) {
            list_.pushBack(safeInputDouble(""));
        } else if constexpr (std::is_same_v<T, char>) {
            list_.pushBack(safeInputChar(""));
        }
    }

    std::cout << "List created successfully!\n";
}

template <typename T>
void App<T>::addListElement() {
    std::cout << "\nEnter value to add: ";
    T value;

    if constexpr (std::is_same_v<T, int>)
        value = safeInputInt("");
    else if constexpr (std::is_same_v<T, double>)
        value = safeInputDouble("");
    else if constexpr (std::is_same_v<T, char>)
        value = safeInputChar("");

    std::cout << "1 - Add to front\n2 - Add to back\n";
    int choice = safeInputInt("Enter option: ");

    if (choice == 1) {
        list_.pushFront(value);
        std::cout << "Element added to front.\n";
    } else if (choice == 2) {
        list_.pushBack(value);
        std::cout << "Element added to back.\n";
    } else {
        std::cout << "Invalid choice.\n";
    }
}

template <typename T>
void App<T>::removeListElement() {
    if (list_.empty()) {
        std::cout << "List is empty.\n";
        return;
    }

    std::cout << "1 - Remove front\n2 - Remove back\n";
    int choice = safeInputInt("Enter option: ");

    if (choice == 1) {
        list_.popFront();
        std::cout << "Front element removed.\n";
    } else if (choice == 2) {
        list_.popBack();
        std::cout << "Back element removed.\n";
    } else {
        std::cout << "Invalid choice.\n";
    }
}

template <typename T>
void App<T>::showList() {
    if (list_.empty()) {
        std::cout << "List is empty.\n";
        return;
    }

    std::cout << "\nList elements: ";
    for (auto it = list_.begin(); it != list_.end(); ++it) {
        std::cout << *it;
        auto next = it;
        ++next;
        if (next != list_.end())
            std::cout << " <-> ";
    }
    std::cout << "\n";
}

template <typename T>
void App<T>::sortList() {
    if (list_.empty()) {
        std::cout << "List is empty.\n";
        return;
    }

    algorithm_.sort(list_);
    std::cout << "List sorted successfully.\n";
}

template <typename T>
void App<T>::searchListElement() {
    if (list_.empty()) {
        std::cout << "List is empty.\n";
        return;
    }

    std::cout << "Enter value to search: ";
    T value;
    if constexpr (std::is_same_v<T, int>)
        value = safeInputInt("");
    else if constexpr (std::is_same_v<T, double>)
        value = safeInputDouble("");
    else if constexpr (std::is_same_v<T, char>)
        value = safeInputChar("");

    if (algorithm_.find(list_, value))
        std::cout << "Element found.\n";
    else
        std::cout << "Element not found.\n";
}

template <typename T>
void App<T>::clearList() {
    if (list_.empty()) {
        std::cout << "List is already empty.\n";
        return;
    }

    list_.clear();
    std::cout << "List cleared successfully.\n";
}

template <typename T>
void App<T>::run() {
    std::string typeName;

    if constexpr (std::is_same_v<T, int>)
        typeName = "int";
    else if constexpr (std::is_same_v<T, double>)
        typeName = "double";
    else if constexpr (std::is_same_v<T, char>)
        typeName = "char";
    else
        typeName = "unknown";

    bool running = true;
    while (running) {
        std::cout << "\n=== MENU (" << typeName << " list) ===\n"
                  << "1 - Create list\n"
                  << "2 - Add element\n"
                  << "3 - Remove element\n"
                  << "4 - Show list\n"
                  << "5 - Sort list\n"
                  << "6 - Search element\n"
                  << "7 - Clear list\n"
                  << "8 - Exit\n";

        int option = safeInputInt("Enter menu option: ");
        switch (option) {
            case 1: createList(); break;
            case 2: addListElement(); break;
            case 3: removeListElement(); break;
            case 4: showList(); break;
            case 5: sortList(); break;
            case 6: searchListElement(); break;
            case 7: clearList(); break;
            case 8:
                std::cout << "Exiting program.\n";
                running = false;
                break;
            default:
                std::cout << "Invalid option.\n";
        }
    }
}
