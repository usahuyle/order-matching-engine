cmake_minimum_required(VERSION 3.15)

project(OrderMatchingEngine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src/headers)

file(GLOB_RECURSE SOURCES
    "src/*.cpp"
)

add_executable(OrderMatchingEngine 
main.cpp ${SOURCES})