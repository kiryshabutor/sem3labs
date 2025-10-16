#include "includes/app.h"

int main() {
    std::cout << "Choose list type:\n"
              << "1 - int\n"
              << "2 - double\n"
              << "3 - char\n";

    switch (safeInputInt("Enter type: ")) {
        case 1: {
            App<int> app;
            app.run();
            break;
        }
        case 2: {
            App<double> app;
            app.run();
            break;
        }
        case 3: {
            App<char> app;
            app.run();
            break;
        }
        default:
            std::cout << "Invalid type selected.\n";
    }

    return 0;
}
