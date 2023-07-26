cmake_minimum_required(VERSION 3.22.1)
project(Cube_Demo LANGUAGES CXX)
find_package(SFML 2 REQUIRED COMPONENTS graphics window system )

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_VERBOSE_MAKEFILE true)

add_executable(${PROJECT_NAME} src/Main.cpp
src/Application.cpp
src/Canvas.cpp
src/Polygon.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system)


include_directories(include)

# Auto-generated comment:
# Post-compile data

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)

# Auto-generated comment:
# This list made with CMakeEasy.
