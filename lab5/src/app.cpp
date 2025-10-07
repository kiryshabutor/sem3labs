#include "../includes/app.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

template <typename T>
void manageList(SinglyLinkedList<T>& list, const string& typeName) {
    int choice;
    do {
        cout << "\n=== Singly Linked List (" << typeName << ") ===\n";
        cout << "1. Push front\n";
        cout << "2. Push back\n";
        cout << "3. Pop front\n";
        cout << "4. Show list\n";
        cout << "5. Clear list\n";
        cout << "0. Exit to main menu\n";

        choice = safeInputInt("Choose: ");
        switch (choice) {
            case 1:
                if constexpr (is_same_v<T, int>)
                    list.pushFront(safeInputInt("Enter value: "));
                else if constexpr (is_same_v<T, double>)
                    list.pushFront(safeInputDouble("Enter value: "));
                else if constexpr (is_same_v<T, char>)
                    list.pushFront(safeInputChar("Enter value: "));
                break;

            case 2:
                if constexpr (is_same_v<T, int>)
                    list.pushBack(safeInputInt("Enter value: "));
                else if constexpr (is_same_v<T, double>)
                    list.pushBack(safeInputDouble("Enter value: "));
                else if constexpr (is_same_v<T, char>)
                    list.pushBack(safeInputChar("Enter value: "));
                break;

            case 3:
                try {
                    list.popFront();
                    cout << "First element removed.\n";
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;

            case 4:
                list.print();
                break;

            case 5:
                list.clear();
                cout << "List cleared.\n";
                break;

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}


void App::run() const{
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
