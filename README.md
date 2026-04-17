# CMake Learning Project

This project is designed to help learn CMake from entry level to advanced level. Each directory contains a self-contained CMake project with detailed comments explaining each CMake command.

## Directory Structure

- **01_entry/**: Basic CMake project with fundamental commands
- **02_beginner/**: More advanced CMake project with compiler flags and additional commands
- **03_intermediate/**: Project demonstrating library creation and linking
- **04_advanced/**: Sophisticated project with configurable builds, installation rules, and custom targets

## How to Build and Run

### Entry Level
```bash
cd 01_entry
mkdir -p build
cd build
cmake ..
make
./entry_app
```

### Beginner Level
```bash
cd 02_beginner
mkdir -p build
cd build
cmake ..
make
./beginner_app
```

### Intermediate Level
```bash
cd 03_intermediate
mkdir -p build
cd build
cmake ..
make
./intermediate_app
```

### Advanced Level
```bash
cd 04_advanced
mkdir -p build
cd build
cmake ..
make
./advanced_app
```

## Key CMake Commands Explained

Each CMakeLists.txt file contains detailed comments explaining each command. Here are some of the key commands covered:

- **cmake_minimum_required**: Specifies the minimum CMake version required
- **project**: Sets the project name and version
- **set**: Defines variables for better organization
- **add_executable**: Creates an executable target
- **add_library**: Creates a library target
- **target_include_directories**: Specifies include directories for targets
- **target_link_libraries**: Links libraries to targets
- **configure_file**: Generates files from templates with CMake variables
- **install**: Specifies installation rules
- **add_custom_target**: Creates custom build targets

## Learning Progression

1. **Entry Level**: Learn basic CMake structure and commands
2. **Beginner Level**: Explore compiler flags and additional CMake commands
3. **Intermediate Level**: Understand library creation and linking
4. **Advanced Level**: Master configurable builds, installation, and custom targets
