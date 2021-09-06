//
// Created by Douwe den Blanken on 10/03/2021.
//

#include <gtest/gtest.h>

#include <Constellation/Matrix.hpp>
#include <Constellation/Reduction/Reduction.hpp>

TEST (ReductionTests, MinMax
) {
    int aValues[16] = {0, 0, 0, 0,
                       0, 0, 0, 0,
                       0, 0, 7, 0,
                       0, 0, 0, -3};

    Constellation::Matrix<int> a(4, 4, aValues);

    // Check if the maximum is found correctly
    EXPECT_EQ (7, Constellation::Reduction::max(a));

    // Check if the minimum is found correctly
    EXPECT_EQ (-3, Constellation::Reduction::min(a));
}

TEST (ReductionTests, Sum
) {
    int aValues[16] = {0, 0, 1, 0,
                       0, 8, 0, 0,
                       0, 0, 7, 0,
                       0, 0, 0, -3};

    Constellation::Matrix<int> a(4, 4, aValues);

    // Check if the maximum is found correctly
    EXPECT_EQ (13, Constellation::Reduction::sum(a));
}

TEST (ReductionTests, Product
) {
    int aValues[4] = {1, 3,
                      3, 8};

    Constellation::Matrix<int> a(2, 2, aValues);

    // Check if the maximum is found correctly
    EXPECT_EQ (72, Constellation::Reduction::prod(a));
}

TEST (ReductionTests, Trace
) {
    int aValues[4] = {23, 3,
                      3, -1};

    Constellation::Matrix<int> a(2, 2, aValues);

    // Check if the maximum is found correctly
    EXPECT_EQ (22, Constellation::Reduction::tr(a));
}

TEST (ReductionTests, Average
) {
    int aValues[4] = {2, 3,
                      4, 8};

    Constellation::Matrix<int> a(2, 2, aValues);

    // Check if the maximum is found correctly
    EXPECT_EQ (4, Constellation::Reduction::avg(a));
}




