cmake_minimum_required(VERSION 3.26)
project(SAOD)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(modules)
target_sources(modules
  PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
    "modules/BaseArrFuncs.ixx"
    "modules/Contaners.ixx"
    "modules/Search.ixx"
    "modules/Sorts.ixx"
)
add_executable(SAOD main.cpp)
target_link_libraries(SAOD PRIVATE modules)

