cmake_minimum_required(VERSION 3.16)
project(Polynomial LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Polynomial
    src/main.cpp
    src/Polynomial.cpp
    include/Polynomial.h
    include/myFunctions.h
)

target_include_directories(Polynomial PRIVATE include)

if(MSVC)
    target_compile_options(Polynomial PRIVATE /W4)
else()
    target_compile_options(Polynomial PRIVATE -Wall -Wextra -Wpedantic)
endif()