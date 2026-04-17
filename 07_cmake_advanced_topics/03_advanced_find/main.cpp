#include <iostream>

int main() {
    std::cout << "Advanced Find and Configure Example" << std::endl;
    
#ifdef OPENGL_FOUND
    std::cout << "OpenGL is available" << std::endl;
#else
    std::cout << "OpenGL not available" << std::endl;
#endif
    
#ifdef _OPENMP
    std::cout << "OpenMP is available" << std::endl;
#else
    std::cout << "OpenMP not available" << std::endl;
#endif
    
    std::cout << "Advanced package finding demonstrated" << std::endl;
    return 0;
}
