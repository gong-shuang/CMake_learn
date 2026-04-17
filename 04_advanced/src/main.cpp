#include "core/greeter.h"
#include "config/config.h"
#include <iostream>

int main() {
    Greeter greeter("CMake Advanced Level");
    greeter.sayHello();
    
    std::cout << "Project Version: " << PROJECT_VERSION << std::endl;
    std::cout << "Build Type: " << BUILD_TYPE << std::endl;
    std::cout << "Compiler: " << COMPILER_ID << std::endl;
    
    return 0;
}
