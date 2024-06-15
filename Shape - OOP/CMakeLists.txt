cmake_minimum_required(VERSION 3.25)
project(assignment3)

set(CMAKE_CXX_STANDARD 11)

add_executable(assignment3 main.cpp Shape.h Shape.cpp Square.h Square.cpp Circle.h Circle.cpp OrthogonalTriangle.h OrthogonalTriangle.cpp Menu.h Menu.cpp LinkedList.h Node.h)
