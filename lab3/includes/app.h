#pragma once
#include "person.h"
#include "entrepreneur.h"
#include "tourist.h"
#include "shuttler.h"
#include <memory>

class App {
private:
    std::unique_ptr<Person> current;
    void showMainMenu() const;
    void handleChoice(int choice);

    void menuPerson() const;
    void menuEntrepreneur() const;
    void menuTourist() const;
    void menuShuttler() const;

public:
    App() = default;
    void run();
};
