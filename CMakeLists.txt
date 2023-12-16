cmake_minimum_required(VERSION 3.22)
project(hello
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_library(basics STATIC
    "${PROJECT_SOURCE_DIR}/sources/02_basics.cpp"
    "${PROJECT_SOURCE_DIR}/sources/03_basics.cpp")

add_executable(hello "${PROJECT_SOURCE_DIR}/sources/main.cpp")
target_include_directories(hello PRIVATE "${PROJECT_SOURCE_DIR}/sources")
target_link_libraries(hello PRIVATE basics)
