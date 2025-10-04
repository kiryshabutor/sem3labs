#include "../includes/worker.h"

Worker::Worker() = default;

Worker::Worker(std::string_view f, std::string_view l)
    : firstName(f), lastName(l) {}

void Worker::setFirstName(std::string_view f) { firstName = f; }
void Worker::setLastName(std::string_view l) { lastName = l; }

std::string_view Worker::getFirstName() const { return firstName; }
std::string_view Worker::getLastName() const { return lastName; }
