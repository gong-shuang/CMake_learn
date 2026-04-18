# 目录结构：
```
06_advanced_features/
├── 01_conditional_compilation/     # 条件编译
├── 02_custom_commands/             # 自定义命令
├── 03_external_dependencies/       # 外部依赖
├── 04_generated_files/             # 生成文件
├── 05_install_packaging/           # 安装和打包
└── 06_testing_coverage/            # 测试和覆盖率
```


每个例子都是独立的项目，可以单独构建和运行：
```
cd 06_advanced_features/01_conditional_compilation
mkdir -p build && cd build
cmake .. && make && ./conditional_app
```


# 每个例子的功能
## 1. 条件编译 ：
   - 使用 option() 定义编译选项
   - 使用 target_compile_definitions() 实现条件编译
   - 展示了如何在 CMake 中控制代码的编译选项

在cmake中定义编译宏，然后控制代码的执行

## 2. 自定义命令 ：
   - 使用 add_custom_command() 生成文件
   - 使用 add_custom_target() 创建自定义构建目标
   - 展示了如何在构建过程中执行自定义操作

使用 add_custom_command() 函数，不能生成文件，
使用 add_custom_target()，可以创建自定义的命令，在执行cmake命令之后，就可以使用该命令了。

## 3. 外部依赖 ：
   - 使用 find_package() 查找外部库（Boost 示例）
   - 展示了如何处理外部依赖的存在性检查

检测某个系统库有没有安装，如果没有则报错

## 4. 生成文件 ：
   - 使用 configure_file() 从模板生成配置文件
   - 展示了如何在构建时动态生成代码和配置

cmake 命令执行后，就生成了 对应的文件

## 5. 安装和打包 ：
   - 使用 install() 定义安装规则
   - 使用 CPack 配置打包
   - 展示了如何创建可安装的软件包

CPack 是 CMake 内置的打包工具，可以生成多种格式的安装包（如 .deb、.rpm、.dmg、Windows 安装程序等）。

使用方法
```
# 生成安装包
make package

# 或者直接使用 cpack
cpack

# 指定生成格式
cpack -G DEB    # 生成 Debian 包
cpack -G RPM    # 生成 RPM 包
cpack -G NSIS   # 生成 Windows 安装程序
```

## 6. 测试和覆盖率 ：
   - 使用 enable_testing() 启用测试
   - 使用 add_test() 添加测试
   - 展示了如何启用代码覆盖率分析

 使用方法
```
# 运行所有测试
ctest

# 或
make test

# 显示详细输出
ctest -V

# 只运行特定测试
ctest -R MyTest
```
