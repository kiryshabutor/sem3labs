#pragma once
#include <memory>
#include "worker.h"
#include "hourly_employee.h"
#include "salaried_employee.h"
#include "commission_employee.h"

class App {
private:
    std::unique_ptr<Worker> current;

public:
    void showMainMenu() const;
    void handleChoice(int choice);
    void run();
};
