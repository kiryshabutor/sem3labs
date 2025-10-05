#include "../includes/app.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

template <typename T>
void manageList(SinglyLinkedList<T>& list, const std::string& typeName) {
    int choice;
    do {
        std::cout << "\n=== Singly Linked List (" << typeName << ") ===\n";
        std::cout << "1. Push front\n";
        std::cout << "2. Push back\n";
        std::cout << "3. Pop front\n";
        std::cout << "4. Show list\n";
        std::cout << "5. Clear list\n";
        std::cout << "0. Exit to main menu\n";

        choice = safeInputInt("Choose: ");
        switch (choice) {
            case 1:
                if constexpr (std::is_same_v<T, int>)
                    list.pushFront(safeInputInt("Enter value: "));
                else if constexpr (std::is_same_v<T, double>)
                    list.pushFront(safeInputDouble("Enter value: "));
                else if constexpr (std::is_same_v<T, char>)
                    list.pushFront(safeInputChar("Enter value: "));
                break;

            case 2:
                if constexpr (std::is_same_v<T, int>)
                    list.pushBack(safeInputInt("Enter value: "));
                else if constexpr (std::is_same_v<T, double>)
                    list.pushBack(safeInputDouble("Enter value: "));
                else if constexpr (std::is_same_v<T, char>)
                    list.pushBack(safeInputChar("Enter value: "));
                break;

            case 3:
                try {
                    list.popFront();
                    std::cout << "First element removed.\n";
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << std::endl;
                }
                break;

            case 4:
                list.print();
                break;

            case 5:
                list.clear();
                std::cout << "List cleared.\n";
                break;

            case 0:
                std::cout << "Returning to main menu...\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}


void App::run() {
    int choice;
    do {
        cout << "\n=== Main Menu ===\n";
        cout << "1. Create int list\n";
        cout << "2. Create double list\n";
        cout << "3. Create char list\n";
        cout << "0. Exit\n";
        choice = safeInputInt("Choose: ");

        if (choice == 1) {
            SinglyLinkedList<int> list;
            manageList(list, "int");
        } else if (choice == 2) {
            SinglyLinkedList<double> list;
            manageList(list, "double");
        } else if (choice == 3) {
            SinglyLinkedList<char> list;
            manageList(list, "char");
        } else if (choice != 0) {
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}
