cmake_minimum_required(VERSION 3.30)
# Project name
project(cpp_oop_review)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Include the directories containing the header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Define the executable target
add_executable(cpp_oop_review main.cpp
        src/Resource.cpp
        src/Executable.cpp
        src/UsableResource.cpp
        src/ConsumableResource.cpp
        src/Task.cpp
        src/Process.cpp)
