cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)  #c++ standard version

set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MANAGEMENT VERSION 1.0)  #project name

add_executable(${PROJECT_NAME} src/main.cpp 
    src/person.cpp 
    src/student.cpp 
    src/teacher.cpp 
    src/personmanager.cpp
    src/subject.cpp
    src/club.cpp)  #goes before include directory

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)