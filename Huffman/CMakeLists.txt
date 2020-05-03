cmake_minimum_required(VERSION 2.6)
project(Huffman)
FILE(GLOB_RECURSE INC_ALL "include/*.h")
set(HEADERS include /usr/local/include /usr/include ../3rd_party/googletest-1.10.x/googletest/include)
set(SOURCES src/btree.cpp
            src/node.cpp
            src/huffman.cpp
            src/commons.cpp
            tests/commons_tests.cpp
            tests/huffman_tests.cpp
            tests/huffman_all_tests.cpp
            tests/node_tests.cpp)
include_directories(${HEADERS})
add_executable(Huffman ${SOURCES} ${INC_ALL})
link_directories(Huffman /usr/lib/x86_64-linux-gnu)
target_link_libraries(Huffman pthread rt gtest_main gtest)
target_compile_options(Huffman PUBLIC -std=c++17 -g -Wall -pedantic -Wextra -fpermissive)
add_test(NAME Commons COMMAND Huffman)
add_test(NAME Huffman COMMAND Huffman)
add_test(NAME Node COMMAND Huffman)
install(TARGETS Huffman DESTINATION build)

