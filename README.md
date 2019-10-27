## Qt 在 Windows 下使用 CMake 编译，运行时无法找到资源文件的问题
环境：

系统   Windows 10, 版本1903 (内部版本18362.418)

编译器 MSVC 19.23.28106.4 

Qt   5.13.1 for msvc2017

问题：

使用 cmake 构建 Qt 项目后，Qt 的资源文件 (qrc 文件) 成功链接至生成的 exe 文件内，
但只有使用 CLion 在 build type 为 Debug 的情况下编译，运行时才能正确，而使用
CLion 内的其他 build type (Release, RelWithDebInfo, MinSizeReld 等)
或者命令行内使用任意 build type (Debug, Release 等) 构建，
在运行时都无法查找到对应的资源文件。

CLion 选择的 cmake generator 为 `CodeLite - NMake Makefiles`， 
使用命令行构建时选择的 generator 为 `Visual Studio 16 2019`。Release 与 Debug 
构建分别将 `CMAKE_BUILD_TYPE` 设置为了 `Release` 与 `Debug`。
因为我这里在命令行内使用 `CodeLite - NMake Makefiles` generator，
会原因不明的生成失败，所以没有尝试这样构建。
 
本项目是这个问题的最小化复现，可以尝试构建此项目，只有在 CLion 中 Debug 构建才会
输出 `true`，其他情况下都会输出 `false`。

另外通过二进制编译器查看生成的 exe 文件会发现资源文件的内容实际已经被包含至 exe 中，
但运行时依然查找不到。
