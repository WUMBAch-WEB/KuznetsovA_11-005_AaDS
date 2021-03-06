cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled "cmake-build-debug/First week H/main.cpp")

add_executable(firstTask cmake-build-debug/SecondWeekHW/FirstTask.cpp)

add_executable(secondTask cmake-build-debug/SecondWeekHW/SecondTask.cpp)

add_executable(thirdTask cmake-build-debug/SecondWeekHW/ThirdTask.cpp)

add_executable(stack cmake-build-debug/ThirdWeek/Stack.cpp)

add_executable(list cmake-build-debug/ThirdWeek/LinkedList.cpp)

add_executable(DoubleList cmake-build-debug/HomeWork_10.03/DoubleLinkedList.cpp)

add_executable(Queue cmake-build-debug/HomeWork_10.03/Queue.cpp)