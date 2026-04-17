#include <iostream>
#include "config.h"

int main() {
    std::cout << "Generated Files Example" << std::endl;
    std::cout << "Project: " << PROJECT_NAME << std::endl;
    std::cout << "Version: " << PROJECT_VERSION << std::endl;
    std::cout << "Build Type: " << BUILD_TYPE << std::endl;
    std::cout << "Compiler: " << COMPILER << std::endl;
    return 0;
}
