//
// Created by Douwe den Blanken on 09/03/2021.
//

#include <gtest/gtest.h>

#include <Constellation/Diagonal.hpp>
#include <Constellation/Matrix.hpp>

TEST (ConstructionTests, Diagonal
) {
    int aValues[4] = {16, 2, 77, 40};
    int bValues[16] = {16, 0, 0, 0,
                       0, 2, 0, 0,
                       0, 0, 77, 0,
                       0, 0, 0, 40};

    int cValues[16] = {16, 0, 0, 0,
                       0, 3, 0, 0,
                       0, 0, 77, 0,
                       0, 0, 0, 40};

    int dValues[16] = {16, 1, 0, 0,
                       0, 2, 0, 0,
                       0, 0, 77, 0,
                       0, 0, 0, 40};

    Constellation::Diagonal<int> a(4, aValues);
    Constellation::Matrix<int> b(4, 4, bValues);
    Constellation::Matrix<int> c(4, 4, cValues);
    Constellation::Matrix<int> d(4, 4, dValues);

    // Check if the diagonal matrix is actually a diagonal matrix
    EXPECT_EQ (true, a == b);

    // Check if equals function works as expected with change in diagonal value
    EXPECT_EQ (false, a == c);

    // Check if equals function works as expected with change in padding value
    EXPECT_EQ (false, a == d);
}