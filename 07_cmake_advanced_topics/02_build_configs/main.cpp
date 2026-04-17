#include <iostream>

int main() {
    std::cout << "Build Configurations Example" << std::endl;
    std::cout << "Configuration: " << CONFIG << std::endl;
    
#ifdef DEBUG
    std::cout << "Debug mode enabled" << std::endl;
#else
    std::cout << "Release mode enabled" << std::endl;
#endif
    
    return 0;
}
