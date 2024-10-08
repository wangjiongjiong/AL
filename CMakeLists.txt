cmake_minimum_required(VERSION 3.0)
project(AL)

#aux_source_directory(${PROJECT_SOURCE_DIR} SRC)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
set(EXECUTABLE_OUTPUT_PATH /home/AL/bin)
#set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(main ${SRC})
