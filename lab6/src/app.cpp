#include "../includes/app.h"
#include "../includes/input_utils.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void App::showMainMenu() const {
    cout << "\n=== MAIN MENU ===\n";
    cout << "1. Create Person\n";
    cout << "2. Create Entrepreneur\n";
    cout << "3. Create Tourist\n";
    cout << "4. Create Shuttler\n";
    cout << "0. Exit\n";
}

void App::handleChoice(int choice) {
    switch (choice) {
        case 1:
            current = make_unique<Person>();
            current->inputData();
            menuPerson();
            break;
        case 2:
            current = make_unique<Entrepreneur>();
            current->inputData();
            menuEntrepreneur();
            break;
        case 3:
            current = make_unique<Tourist>();
            current->inputData();
            menuTourist();
            break;
        case 4:
            current = make_unique<Shuttler>();
            current->inputData();
            menuShuttler();
            break;
        case 0:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice.\n";
    }
}

void App::menuPerson() const {
    int choice = -1;
    do {
        try {
            cout << "\n=== PERSON MENU ===\n";
            cout << "1. Show info\n";
            cout << "0. Back to main menu\n";
            choice = safeInputInt("Choose: ");

            switch (choice) {
                case 1:
                    current->printInfo();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } catch (const exception &e) {
            cout << "Input error: " << e.what() << "\nPlease try again.\n";
        }
    } while (choice != 0);
}

void App::menuEntrepreneur() const {
    auto *e = dynamic_cast<Entrepreneur *>(current.get());
    if (!e) return;

    int choice = -1;
    do {
        try {
            cout << "\n=== ENTREPRENEUR MENU ===\n";
            cout << "1. Show info\n";
            cout << "2. Add tax payment\n";
            cout << "3. Show tax payments\n";
            cout << "0. Back to main menu\n";
            choice = safeInputInt("Choose: ");

            switch (choice) {
                case 1:
                    e->printInfo();
                    break;
                case 2: {
                    Date d;
                    d.inputDate();
                    float sum = safePositiveInputFloat("Enter tax sum: ");
                    e->addTaxPayment(d, sum);
                    break;
                }
                case 3:
                    e->printTaxPayments();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } catch (const exception &e) {
            cout << "Input error: " << e.what() << "\nPlease try again.\n";
        }
    } while (choice != 0);
}

void App::menuTourist() const {
    auto *t = dynamic_cast<Tourist *>(current.get());
    if (!t) return;

    int choice = -1;
    do {
        try {
            cout << "\n=== TOURIST MENU ===\n";
            cout << "1. Show info\n";
            cout << "2. Add border crossing\n";
            cout << "3. Show border crossings\n";
            cout << "0. Back to main menu\n";
            choice = safeInputInt("Choose: ");

            switch (choice) {
                case 1:
                    t->printInfo();
                    break;
                case 2: {
                    Date d;
                    d.inputDate();
                    string country = safeInputLine("Enter country: ");
                    t->addBorderCrossing(d, country);
                    break;
                }
                case 3:
                    t->printBorderCrossings();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } catch (const exception &e) {
            cout << "Input error: " << e.what() << "\nPlease try again.\n";
        }
    } while (choice != 0);
}

void App::menuShuttler() const {
    auto *s = dynamic_cast<Shuttler *>(current.get());
    if (!s) return;

    int choice = -1;
    do {
        try {
            cout << "\n=== SHUTTLER MENU ===\n";
            cout << "1. Show info\n";
            cout << "2. Add tax payment\n";
            cout << "3. Show tax payments\n";
            cout << "4. Add border crossing\n";
            cout << "5. Show border crossings\n";
            cout << "6. Add shopping address\n";
            cout << "7. Show shopping addresses\n";
            cout << "0. Back to main menu\n";
            choice = safeInputInt("Choose: ");

            switch (choice) {
                case 1:
                    s->printInfo();
                    break;
                case 2: {
                    Date d;
                    d.inputDate();
                    float sum = safePositiveInputFloat("Enter tax sum: ");
                    s->addTaxPayment(d, sum);
                    break;
                }
                case 3:
                    s->printTaxPayments();
                    break;
                case 4: {
                    Date d;
                    d.inputDate();
                    string country = safeInputLine("Enter country: ");
                    s->addBorderCrossing(d, country);
                    break;
                }
                case 5:
                    s->printBorderCrossings();
                    break;
                case 6: {
                    string addr = safeInputLine("Enter shopping address: ");
                    s->addShoppingAddress(addr);
                    break;
                }
                case 7:
                    s->printShoppingAddresses();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } catch (const exception &e) {
            cout << "Input error: " << e.what() << "\nPlease try again.\n";
        }
    } while (choice != 0);
}

void App::run() {
    int choice = -1;
    do {
        try {
            showMainMenu();
            choice = safeInputInt("Choose: ");
            handleChoice(choice);
        } catch (const exception &e) {
            cout << "Input error: " << e.what() << "\nPlease try again.\n";
        }
    } while (choice != 0);
}
