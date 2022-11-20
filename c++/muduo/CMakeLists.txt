cmake_minimum_required(VERSION 2.5)
project(muduo)

## mymuduo最终编译成动态库
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
## 设置调试信息 以及启动c++11语言标准
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -fPIC")
## 定义参与编译的源文件
aux_source_directory(. SRC_LIST)
## 编译动态库
add_library(muduo SHARED ${SRC_LIST})