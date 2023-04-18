cmake_minimum_required(VERSION 3.5)

project(Parcial1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Parcial1 main.cpp)

install(TARGETS Parcial1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
