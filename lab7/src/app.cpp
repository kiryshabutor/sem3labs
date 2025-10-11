#include "../includes/app.h"
#include "../includes/input_utils.h"
#include <iostream>
#include <format>
#include <stdexcept>

void App::run() {
    bool running = true;
    while (running) {
        showMenu();
        int choice = safeInputInt("Choose an option: ");
        if (choice == 0) {
            std::cout << "Exiting...\n";
            running = false;
            continue;
        }

        try {
            handleChoice(choice);
        } catch (const std::invalid_argument& e) {
            std::cout << std::format("Error: {}\n", e.what());
        } catch (const std::out_of_range& e) {
            std::cout << std::format("Range error: {}\n", e.what());
        } catch (const std::runtime_error& e) {
            std::cout << std::format("Runtime error: {}\n", e.what());
        }
    }
}

void App::showMenu() const {
    std::cout << "\n=== Menu ===\n"
              << "1 - Enter file path\n"
              << "2 - Show file content\n"
              << "3 - Read character by index\n"
              << "4 - Replace character by index\n"
              << "0 - Exit\n";
}

void App::handleChoice(int choice) {
    switch (choice) {
        case 1:
            enterFilePath();
            break;
        case 2:
            showFileContent();
            break;
        case 3:
            readCharacter();
            break;
        case 4:
            replaceCharacter();
            break;
        default:
            throw std::out_of_range("Invalid menu option");
    }
}

void App::enterFilePath() {
    currentFilePath_ = readLineTrimmed("Enter file path: ");
    reader_ = std::make_unique<FileReader>(currentFilePath_);
    std::cout << std::format("File '{}' loaded successfully.\n", currentFilePath_);
}

void App::showFileContent() const{
    if (!reader_) {
        throw std::invalid_argument("No file loaded. Please load a file first.");
    }
    reader_->printFileContent();
}

void App::readCharacter() const{
    if (!reader_) {
        throw std::invalid_argument("No file loaded. Please load a file first.");
    }

    int index = safeInputInt("Enter character index: ");
    char c = (*reader_)[static_cast<std::size_t>(index)];
    std::cout << std::format("Character at position {}: '{}'\n", index, c);
}

void App::replaceCharacter() {
    if (!reader_) {
        throw std::invalid_argument("No file loaded. Please load a file first.");
    }

    int index = safeInputInt("Enter character index to replace: ");
    std::string replacement = readLineTrimmed("Enter new character: ");

    if (replacement.size() != 1) {
        throw std::invalid_argument("You must enter exactly one character.");
    }

    reader_->replaceCharacter(static_cast<std::size_t>(index), replacement[0]);
    std::cout << "Character replaced successfully.\n";
}
