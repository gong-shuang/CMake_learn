#include <iostream>

#ifdef BOOST_FOUND
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#else
// Stub implementation if Boost not found
namespace fs {
    struct path {
        path(const char*) {}
    };
    bool exists(const path&) { return true; }
}
#endif

int main() {
    std::cout << "External Dependencies Example" << std::endl;
    
#ifdef BOOST_FOUND
    std::cout << "Boost is available!" << std::endl;
    fs::path path(".");
    std::cout << "Current directory exists: " << std::boolalpha << fs::exists(path) << std::endl;
#else
    std::cout << "Boost not available, using stub implementation" << std::endl;
    fs::path path(".");
    std::cout << "Current directory exists: true" << std::endl;
#endif
    
    return 0;
}
