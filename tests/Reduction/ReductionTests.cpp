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


