#ifndef GREETER_H
#define GREETER_H

#include <string>

class Greeter {
private:
    std::string name;

public:
    Greeter(const std::string& n);
    void sayHello() const;
};

#endif // GREETER_H
