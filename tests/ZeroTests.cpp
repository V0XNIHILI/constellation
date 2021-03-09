//
// Created by Douwe den Blanken on 09/03/2021.
//

//
// Created by Douwe den Blanken on 09/03/2021.
//

#include <gtest/gtest.h>

#include <Constellation/Zero.hpp>
#include <Constellation/Matrix.hpp>

TEST (ConstructionTests, Zero
) {
    int bValues[16] = {0, 0, 0, 0,
                       0, 0, 0, 0,
                       0, 0, 0, 0,
                       0, 0, 0, 0};

    Constellation::Zero<int> a(4);
    Constellation::Matrix<int> b(4, 4, bValues);

    // Check if the zero matrix is actually a zero matrix
    EXPECT_EQ (true, a == b);

    // Do the same check, but from the Matrix class instead of from the Zero class
    EXPECT_EQ (true, b == a);
}

