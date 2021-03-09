## cmake version to be used
#cmake_minimum_required( VERSION 3.0 )
#
## project name
#project( constellation )
#
## cpp version
#
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
## flags
#if (UNIX)
#    set(CMAKE_CXX_FLAGS "-Ofast -march=native -flto -fomit-frame-pointer -mavx2 -fno-tree-vectorize")
#endif (UNIX)
#
## files
#
## include
#include_directories( ./include ./src )
#
## target
#add_executable( binary ./src/main.cpp )
#
## tests
##enable_testing()
#add_executable(all_tests tests/main.cpp)
#set(INSTALL_GTEST OFF)
#add_subdirectory(libs/googletest)
#target_link_libraries(all_tests gtest gtest_main)
##add_test( all_tests all_tests )

cmake_minimum_required(VERSION 3.0)

enable_testing()

set(CONSTELLATION_PROJECT_NAME
        "CONSTELLATION"
        )

set(CONSTELLATION_LIBRARY_NAME
        "Constellation"
        )

set(CONSTELLATION_HEADERS_DIR
        include/${CONSTELLATION_LIBRARY_NAME}
        )

set(CONSTELLATION_HEADERS
        ${CONSTELLATION_HEADERS_DIR}/Matrix.hpp
        )

set(CONSTELLATION_SOURCE_DIR
        src
        )

set(CONSTELLATION_SOURCE
        ${CONSTELLATION_SOURCE_DIR}/Matrix.cpp
        ${CONSTELLATION_SOURCE_DIR}/Identity.cpp

        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Addition/SIMD/Float32Addition.cpp
        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Addition/SIMD/Int32Addition.cpp

        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Division/SIMD/Float32Division.cpp

        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Multiplication/SIMD/Float32Multiplication.cpp
        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Multiplication/SIMD/Int32Multiplication.cpp

        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Subtraction/SIMD/Float32Subtraction.cpp
        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Subtraction/SIMD/Int32Subtraction.cpp
        )

project(${CONSTELLATION_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${CONSTELLATION_LIBRARY_NAME} STATIC
        ${CONSTELLATION_HEADERS}
        ${CONSTELLATION_SOURCE}
        )

target_include_directories(${CONSTELLATION_LIBRARY_NAME} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${CONSTELLATION_LIBRARY_NAME}>
        $<INSTALL_INTERFACE:include/${CONSTELLATION_LIBRARY_NAME}>
        )

target_include_directories(${CONSTELLATION_LIBRARY_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

if (NOT ((TARGET gtest) AND (TARGET gtest_main)))
    add_subdirectory(libs/googletest)
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
endif ()

add_subdirectory(tests)