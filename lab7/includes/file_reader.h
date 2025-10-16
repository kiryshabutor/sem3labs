#pragma once
#include <string>
#include <fstream>
#include <memory>

class FileReader final {
public:
    explicit FileReader(const std::string& filePath);
    ~FileReader() noexcept;

    FileReader(const FileReader& other);
    FileReader& operator=(const FileReader& other);
    FileReader(FileReader&& other) noexcept;
    FileReader& operator=(FileReader&& other) noexcept;

    char operator[](std::size_t index) const;
    void printFileContent() const;
    void replaceCharacter(std::size_t index, char newChar);

private:
    std::unique_ptr<std::fstream> fileStream_;
    std::string filePath_;
    std::size_t fileSize_{};

    void openFile(const std::string& filePath);

    // 🔽 Новые вспомогательные методы для уменьшения дублирования
    void validateFileOpen() const;
    void ensureFileIsOpen() const;
    void validateIndex(std::size_t index) const;
    void closeFileSafely() noexcept;
};
