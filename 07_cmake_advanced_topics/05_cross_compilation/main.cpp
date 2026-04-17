#include <iostream>

int main() {
    std::cout << "Cross-platform and Cross-compilation Example" << std::endl;
    
#ifdef WINDOWS
    std::cout << "Running on Windows" << std::endl;
#elif MACOS
    std::cout << "Running on macOS" << std::endl;
#elif LINUX
    std::cout << "Running on Linux" << std::endl;
#elif ANDROID
    std::cout << "Running on Android" << std::endl;
#elif IOS
    std::cout << "Running on iOS" << std::endl;
#else
    std::cout << "Running on unknown platform" << std::endl;
#endif
    
    std::cout << "Cross-platform support demonstrated" << std::endl;
    return 0;
}
