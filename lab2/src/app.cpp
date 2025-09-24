#include "../includes/app.h"
#include <iostream>

using namespace std;

void App::run() {
    String s1;
    String s2;

    while (true) {
        cout << "\n==== MENU ====\n";
        cout << "1. Enter string 1\n";
        cout << "2. Enter string 2\n";
        cout << "3. Show both strings\n";
        cout << "4. Concatenate string 1 and string 2\n";
        cout << "5. Copy string 2 into string 1\n";
        cout << "6. Exit\n";

        int choice;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter string 1: ";
                cin >> s1;
                break;
            case 2:
                cout << "Enter string 2: ";
                cin >> s2;
                break;
            case 3:
                cout << "String 1: " << s1 << "\n";
                cout << "String 2: " << s2 << "\n";
                break;
            case 4:
                s1 += s2;
                cout << "Concatenation result: " << s1 << "\n";
                break;
            case 5:
                s1 = s2;
                cout << "String 1 is now: " << s1 << "\n";
                break;
            case 6:
                cout << "Exiting.\n";
                return;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
