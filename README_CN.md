# CMake 学习项目

这个项目旨在帮助从入门到高级学习 CMake。每个目录包含一个独立的 CMake 项目，带有详细的注释解释每个 CMake 命令。

## 目录结构

- **01_entry/**: 基础 CMake 项目，包含基本命令
- **02_beginner/**: 更高级的 CMake 项目，包含编译器标志和其他命令
- **03_intermediate/**: 演示库创建和链接的项目
- **04_advanced/**: 复杂项目，包含可配置构建、安装规则和自定义目标

## 如何构建和运行

### 入门级别
```bash
cd 01_entry
mkdir -p build
cd build
cmake ..
make
./entry_app
```

### 初级级别
```bash
cd 02_beginner
mkdir -p build
cd build
cmake ..
make
./beginner_app
```

### 中级级别
```bash
cd 03_intermediate
mkdir -p build
cd build
cmake ..
make
./intermediate_app
```

### 高级级别
```bash
cd 04_advanced
mkdir -p build
cd build
cmake ..
make
./advanced_app
```

## 关键 CMake 命令解释

每个 CMakeLists.txt 文件都包含详细的注释，解释每个命令。以下是涵盖的一些关键命令：

- **cmake_minimum_required**: 指定所需的最低 CMake 版本
- **project**: 设置项目名称和版本
- **set**: 定义变量以更好地组织
- **add_executable**: 创建可执行目标
- **add_library**: 创建库目标
- **target_include_directories**: 指定目标的包含目录
- **target_link_libraries**: 将库链接到目标
- **configure_file**: 从带有 CMake 变量的模板生成文件
- **install**: 指定安装规则
- **add_custom_target**: 创建自定义构建目标

## 学习进度

1. **入门级别**: 学习基本的 CMake 结构和命令
2. **初级级别**: 探索编译器标志和其他 CMake 命令
3. **中级级别**: 了解库的创建和链接
4. **高级级别**: 掌握可配置构建、安装和自定义目标
