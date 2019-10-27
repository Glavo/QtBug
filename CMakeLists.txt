cmake_minimum_required(VERSION 3.15)
project(QtTest)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_executable(QtTest main.cpp res.qrc)
target_link_libraries(QtTest Qt5::Core)