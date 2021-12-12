cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
project(sample)
add_executable(
   	test1 
    test1.cpp
    ../src/library.cpp
    ../src/withparam.cpp
	../src/phase1.cpp
	../src/phase2.cpp
    ../src/solve.cpp
	)
