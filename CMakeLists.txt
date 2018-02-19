cmake_minimum_required(VERSION 3.9)
project(DNAlgorithms)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost 1.66.0 COMPONENTS program_options filesystem REQUIRED)
include_directories( ${Boost_INCLUDE_DIR} )

add_executable(DNAlgorithms main.cpp DNAUtility.h)
target_link_libraries(DNAlgorithms LINK_PUBLIC ${Boost_LIBRARIES} )