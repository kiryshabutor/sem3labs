#include "../includes/file_reader.h"
#include <iostream>
#include <format>
#include <ios>

namespace {
    constexpr std::ios_base::openmode FILE_MODE = std::ios::in | std::ios::out | std::ios::binary;
}

void FileReader::openFile(const std::string& filePath) {
    fileStream_ = std::make_unique<std::fstream>(filePath, FILE_MODE);
    if (!fileStream_ || !fileStream_->is_open()) {
        throw std::ios_base::failure(std::format("Failed to open file '{}'", filePath));
    }

    fileStream_->seekg(0, std::ios::end);
    fileSize_ = static_cast<std::size_t>(fileStream_->tellg());
    fileStream_->seekg(0, std::ios::beg);

    if (fileSize_ == 0) {
        throw std::length_error(std::format("File '{}' is empty", filePath));
    }
}

char FileReader::operator[](std::size_t index) const {
    if (!fileStream_ || !fileStream_->is_open()) {
        throw std::ios_base::failure("File is not open");
    }

    if (index >= fileSize_) {
        throw std::out_of_range(std::format("Index out of file range ({} >= {})", index, fileSize_));
    }

    fileStream_->seekg(static_cast<std::streampos>(index), std::ios::beg);
    char ch{};
    fileStream_->get(ch);
    if (!fileStream_->good()) {
        throw std::ios_base::failure(std::format("Error reading at position {}", index));
    }
    return ch;
}

void FileReader::replaceCharacter(std::size_t index, char newChar) {
    if (!fileStream_ || !fileStream_->is_open()) {
        throw std::ios_base::failure("File is not open");
    }

    if (index >= fileSize_) {
        throw std::out_of_range(std::format("Index out of file range ({} >= {})", index, fileSize_));
    }

    fileStream_->seekp(static_cast<std::streampos>(index), std::ios::beg);
    fileStream_->put(newChar);
    if (!fileStream_->good()) {
        throw std::ios_base::failure(std::format("Failed to write at position {}", index));
    }
    fileStream_->flush();
}
