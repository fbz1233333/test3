cmake_minimum_required(VERSION 3.5.0)
project(Main)

set(CMAKE_CXX_STANDARD 17)


include_directories(/usr/include/gtk-3.0)
add_executable(main main.cpp )