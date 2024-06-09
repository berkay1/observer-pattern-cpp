cmake_minimum_required(VERSION 3.10)

project(observer-pattern-cpp)


set(CMAKE_CXX_STANDARD 17)
# Set the source files
set(PROJECT_SOURCES src/main.cc
                    include/observer.hpp
                    include/observable.hpp)

# Add any necessary include directories here)
set(DIRECTORIES include)

# Add any necessary libraries here
set(LIBRARIES)

# Add include directories
include_directories(${DIRECTORIES})

# Add the executable
add_executable(observer-pattern-cpp ${PROJECT_SOURCES})

# Link libraries
target_link_libraries(observer-pattern-cpp ${LIBRARIES})
