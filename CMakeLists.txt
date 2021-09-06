cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# Set up project
set(CONSTELLATION_PROJECT_NAME
        "CONSTELLATION"
        )

project(${CONSTELLATION_PROJECT_NAME} VERSION 0.1
                                      DESCRIPTION "Linear algebra package in C++"
                                      LANGUAGES CXX)

# Specify the C++ standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set library name
set(CONSTELLATION_LIBRARY_NAME
        "Constellation"
        )

# Set all source file paths
set(CONSTELLATION_SOURCE_DIR
        src
        )

set(CONSTELLATION_SOURCES
        ${CONSTELLATION_SOURCE_DIR}/Matrix.cpp
        ${CONSTELLATION_SOURCE_DIR}/Identity.cpp

        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Addition/SIMD/Float32Addition.cpp
        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Addition/SIMD/Int32Addition.cpp

        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Division/SIMD/Float32Division.cpp

        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Multiplication/SIMD/Float32Multiplication.cpp
        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Multiplication/SIMD/Int32Multiplication.cpp

        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Subtraction/SIMD/Float32Subtraction.cpp
        ${CONSTELLATION_SOURCE_DIR}/Arithmetic/Subtraction/SIMD/Int32Subtraction.cpp

        ${CONSTELLATION_SOURCE_DIR}/Trigonometry/Trigonometry.cpp
        )

add_library(${CONSTELLATION_LIBRARY_NAME} STATIC
        #        ${CONSTELLATION_HEADERS}
        ${CONSTELLATION_SOURCES}
        )

# Make sure that we have private headers like "#include Abc.hpp" and public headers like "#include
# <LibName/Abc.hpp>" (see: https://medium.com/swlh/c-project-structure-for-cmake-67d60135f6f5)
target_include_directories(${CONSTELLATION_LIBRARY_NAME} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${CONSTELLATION_LIBRARY_NAME}>
        $<INSTALL_INTERFACE:include/${CONSTELLATION_LIBRARY_NAME}>
        )

target_include_directories(${CONSTELLATION_LIBRARY_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

target_compile_options(${CONSTELLATION_LIBRARY_NAME} PRIVATE "-mavx" "-mavx2")

# GTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(tests)
