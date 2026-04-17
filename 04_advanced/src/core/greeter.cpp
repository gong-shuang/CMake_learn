#include "core/greeter.h"
#include <iostream>

Greeter::Greeter(const std::string& n) : name(n) {}

void Greeter::sayHello() const {
    std::cout << "Hello, " << name << "!" << std::endl;
}
