#include <iostream>
#include "version.h"

int main() {
    std::cout << "Custom Build Steps Example" << std::endl;
    std::cout << "Version: " << VERSION << std::endl;
    std::cout << "Build Date: " << BUILD_DATE << std::endl;
    std::cout << "Custom build steps demonstrated" << std::endl;
    return 0;
}
