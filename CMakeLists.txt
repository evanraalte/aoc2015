cmake_minimum_required(VERSION 3.13.4)

project(AOC2015)

add_executable(${PROJECT_NAME} main.cpp)
set (CMAKE_CXX_STANDARD 11)

FILE(GLOB days RELATIVE ${PROJECT_SOURCE_DIR}  ${PROJECT_SOURCE_DIR}/day*)

FOREACH(day ${days})
    FILE(GLOB files ${day}/*.cpp)
    add_library(${day} ${files})
    target_include_directories(${PROJECT_NAME} PUBLIC  ${day})
    target_link_libraries(${PROJECT_NAME} ${day})
ENDFOREACH()
