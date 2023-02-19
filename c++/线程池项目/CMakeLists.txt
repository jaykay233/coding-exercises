cmake_minimum_required(VERSION 3.10)

project(demo VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)



add_executable(main main.cpp threadpool.cpp)