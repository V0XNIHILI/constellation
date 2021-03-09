cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

if (NOT ((TARGET gtest) AND (TARGET gtest_main)))
    message(FATAL_ERROR "gtest and gtest_main targets NOT found")
endif ()

set(CONSTELLATION_TESTS_NAME
        CONSTELLATION_TESTS
        )

set(CONSTELLATION_TESTS_SOURCE
        MatrixTests.cpp
        DiagonalTests.cpp
        ZeroTests.cpp
        )

add_executable(${CONSTELLATION_TESTS_NAME} ${CONSTELLATION_TESTS_SOURCE})

target_link_libraries(${CONSTELLATION_TESTS_NAME}
        gtest
        gtest_main
        ${CONSTELLATION_LIBRARY_NAME}
        )
add_test(${CONSTELLATION_TESTS_NAME} ${CONSTELLATION_TESTS_NAME})