cmake_minimum_required(VERSION 3.23)
project(SAOD)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(SAOD main.cpp)
target_include_directories(SAOD PUBLIC modules)
