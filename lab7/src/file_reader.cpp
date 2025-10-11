#include "../includes/file_reader.h"
#include <iostream>
#include <format>
#include <stdexcept>

namespace {
    constexpr std::ios_base::openmode FILE_MODE = std::ios::in | std::ios::out | std::ios::binary;
}

FileReader::FileReader(const std::string& filePath)
    : fileStream_(nullptr), filePath_(filePath) {
    openFile(filePath_);
}

FileReader::~FileReader() = default;

FileReader::FileReader(const FileReader& other)
    : filePath_(other.filePath_) {
    openFile(filePath_);
}

FileReader& FileReader::operator=(const FileReader& other) {
    if (this != &other) {
        filePath_ = other.filePath_;
        openFile(filePath_);
    }
    return *this;
}

FileReader::FileReader(FileReader&& other) noexcept
    : fileStream_(std::move(other.fileStream_)),
      filePath_(std::move(other.filePath_)),
      fileSize_(other.fileSize_) {
    other.fileSize_ = 0;
}

FileReader& FileReader::operator=(FileReader&& other) noexcept {
    if (this != &other) {
        fileStream_ = std::move(other.fileStream_);
        filePath_ = std::move(other.filePath_);
        fileSize_ = other.fileSize_;
        other.fileSize_ = 0;
    }
    return *this;
}

void FileReader::openFile(const std::string& filePath) {
    fileStream_ = std::make_unique<std::fstream>(filePath, FILE_MODE);
    if (!fileStream_ || !fileStream_->is_open()) {
        throw std::invalid_argument(std::format("Failed to open file '{}'", filePath));
    }

    fileStream_->seekg(0, std::ios::end);
    fileSize_ = static_cast<std::size_t>(fileStream_->tellg());
    fileStream_->seekg(0, std::ios::beg);

    if (fileSize_ == 0) {
        throw std::invalid_argument(std::format("File '{}' is empty", filePath));
    }
}

char FileReader::operator[](std::size_t index) const {
    if (!fileStream_ || !fileStream_->is_open()) {
        throw std::invalid_argument("File is not open");
    }

    if (index >= fileSize_) {
        throw std::out_of_range(std::format("Index out of file range ({} >= {})", index, fileSize_));
    }

    fileStream_->seekg(static_cast<std::streampos>(index), std::ios::beg);
    char ch{};
    fileStream_->get(ch);
    if (!fileStream_->good()) {
        throw std::runtime_error(std::format("Error reading at position {}", index));
    }
    return ch;
}

void FileReader::printFileContent() const {
    if (!fileStream_ || !fileStream_->is_open()) {
        throw std::invalid_argument("File is not open");
    }

    fileStream_->seekg(0, std::ios::beg);
    std::cout << "\nFile content:\n";
    std::string line;
    while (std::getline(*fileStream_, line)) {
        std::cout << line << '\n';
    }
    fileStream_->clear();
}

void FileReader::replaceCharacter(std::size_t index, char newChar) {
    if (!fileStream_ || !fileStream_->is_open()) {
        throw std::invalid_argument("File is not open");
    }

    if (index >= fileSize_) {
        throw std::out_of_range(std::format("Index out of file range ({} >= {})", index, fileSize_));
    }

    fileStream_->seekp(static_cast<std::streampos>(index), std::ios::beg);
    fileStream_->put(newChar);
    if (!fileStream_->good()) {
        throw std::runtime_error(std::format("Failed to write at position {}", index));
    }
    fileStream_->flush();
}
