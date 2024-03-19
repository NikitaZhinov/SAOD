cmake_minimum_required(VERSION 3.26)
project(SAOD)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(SAOD main.cpp  "modules/Sorts.ixx" "modules/BaseArrFuncs.ixx" "modules/Search.ixx")
