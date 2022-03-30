
cmake_minimum_required(VERSION 3.16)
project(SpellChecker)

set(CMAKE_CXX_STANDARD 17)
add_executable(SpellChecker
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/SpellChecker.cpp
        )

target_include_directories(SpellChecker PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/include
        )