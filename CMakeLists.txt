cmake_minimum_required(VERSION 3.12)
project(lists-jonathanprieto99)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)



add_executable(lists-jonathanprieto99 circular.h forward.h iterator.h linked.h list.h node.h main.cpp test/tester.cpp mock/mocker.cpp mock/mocker.h)