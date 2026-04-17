#include <iostream>

int main() {
    std::cout << "Conditional Compilation Example" << std::endl;
    
#ifdef USE_FEATURE_X
    std::cout << "Feature X is enabled!" << std::endl;
#else
    std::cout << "Feature X is disabled!" << std::endl;
#endif
    
#ifdef USE_FEATURE_Y
    std::cout << "Feature Y is enabled!" << std::endl;
#else
    std::cout << "Feature Y is disabled!" << std::endl;
#endif
    
    return 0;
}
