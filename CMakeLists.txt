cmake_minimum_required(VERSION 3.0)

project(INERTIAL_FLOW)


 

#set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "MinCut.cpp" )

add_executable(INERTIAL_FLOW ${SOURCES})
target_include_directories(INERTIAL_FLOW PUBLIC "INERTIALFLOW")
