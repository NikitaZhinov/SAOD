cmake_minimum_required(VERSION 3.20)
project(SAOD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SRC_FILES "src/*.cpp")

add_executable(SAOD ${SRC_FILES})
target_include_directories(SAOD PUBLIC "include")
