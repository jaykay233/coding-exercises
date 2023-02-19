cmake_minimum_required(VERSION 3.10)

project(demo VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)



add_executable(main test_nginx_pool.cpp nginx_mem_pool.cpp)
target_include_directories(main PUBLIC "./nginx-1.12.2/src/core" "./nginx-1.12.2/src/event" "./nginx-1.12.2/src/event/modules" "./nginx-1.12.2/src/os/unix" "./nginx-1.12.2/src/http" "./nginx-1.12.2/src/http/modules")
# target_link_libraries(main PUBLIC "/usr/local/lib/libmysqlclient.dylib" "/usr/local/lib/libmysqlclient.21.dylib" "/usr/local/lib/libmysqlclient.a")