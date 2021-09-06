enable_testing()

set(CONSTELLATION_TESTS_NAME
        CONSTELLATION_TESTS
        )

set(CONSTELLATION_TESTS_SOURCE
        DiagonalTests.cpp
        IdentityTests.cpp
        MatrixTests.cpp
        ZeroTests.cpp

        Reduction/ReductionTests.cpp
        )

add_executable(${CONSTELLATION_TESTS_NAME} ${CONSTELLATION_TESTS_SOURCE})

target_link_libraries(${CONSTELLATION_TESTS_NAME}
        gtest_main
        ${CONSTELLATION_LIBRARY_NAME}
        )

include(GoogleTest)
gtest_discover_tests(${CONSTELLATION_TESTS_NAME})
