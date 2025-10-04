#include "../includes/app.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

void App::showMainMenu() const {
    cout << "\n=== MAIN MENU ===\n";
    cout << "1. Create Hourly Employee\n";
    cout << "2. Create Salaried Employee\n";
    cout << "3. Create Commission Employee\n";
    cout << "0. Exit\n";
}

void App::handleChoice(int choice) {
    switch (choice) {
        case 1:
            current = make_unique<HourlyEmployee>();
            current->inputData();
            current->printInfo();
            break;
        case 2:
            current = make_unique<SalariedEmployee>();
            current->inputData();
            current->printInfo();
            break;
        case 3:
            current = make_unique<CommissionEmployee>();
            current->inputData();
            current->printInfo();
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice.\n";
    }
}

void App::run() {
    int choice;
    do {
        showMainMenu();
        choice = safeInputInt("Choose: ");
        handleChoice(choice);
    } while (choice != 0);
}
