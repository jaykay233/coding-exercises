cmake_minimum_required(VERSION 3.10)

project(demo VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)



add_executable(main main.cpp Connection.cpp CommonConnectionPool.cpp)
target_include_directories(main PUBLIC "/usr/local/include/mysql")
target_link_libraries(main PUBLIC "/usr/local/lib/libmysqlclient.dylib" "/usr/local/lib/libmysqlclient.21.dylib" "/usr/local/lib/libmysqlclient.a")
