#pragma once
#include <string>
#include <memory>
#include "../includes/file_reader.h"

class App final {
public:
    App() = default;
    void run();

private:
    std::unique_ptr<FileReader> reader_;
    std::string currentFilePath_;

    void showMenu() const;
    void handleChoice(int choice);
    void enterFilePath();
    void showFileContent() const;
    void readCharacter() const;
    void replaceCharacter();
};
