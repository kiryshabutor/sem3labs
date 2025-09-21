#pragma once
#include "person.h"
#include "entrepreneur.h"
#include "tourist.h"
#include "shuttler.h"
#include <memory>

class App {
private:
    std::unique_ptr<Person> current;
    void showMainMenu();
    void handleChoice(int choice);

    void menuPerson();
    void menuEntrepreneur();
    void menuTourist();
    void menuShuttler();

public:
    App() = default;
    void run();
};
