cmake_minimum_required(VERSION 2.6)
project(DataCompression)
FILE(GLOB_RECURSE INC_ALL "include/*.h")
set(HEADERS include /usr/local/include /usr/include)
set(SOURCES src/main.cpp src/lz77.cpp)
include_directories(${HEADERS})
add_executable(DataCompression ${SOURCES} ${INC_ALL})
link_directories(DataCompression /usr/lib/x86_64-linux-gnu)
target_link_libraries(DataCompression pthread rt)
target_compile_options(DataCompression PUBLIC -std=c++17 -g -Wall -pedantic -Wextra -fpermissive)
install(TARGETS DataCompression DESTINATION build)

