#include <iostream>

// Declarations for library functions
int add(int a, int b);
int subtract(int a, int b);

int main() {
    std::cout << "Testing and Coverage Example" << std::endl;
    
    // Test add function
    int result1 = add(5, 3);
    std::cout << "5 + 3 = " << result1 << std::endl;
    
    // Test subtract function
    int result2 = subtract(10, 4);
    std::cout << "10 - 4 = " << result2 << std::endl;
    
    std::cout << "Tests completed!" << std::endl;
    return 0;
}
