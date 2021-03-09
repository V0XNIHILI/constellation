//
// Created by Douwe den Blanken on 09/03/2021.
//

#include <gtest/gtest.h>

#include <Constellation/Identity.hpp>
#include <Constellation/Matrix.hpp>

TEST (ConstructionTests, Identity
) {
    int bValues[16] = {1, 0, 0, 0,
                       0, 1, 0, 0,
                       0, 0, 1, 0,
                       0, 0, 0, 1};

    Constellation::Identity<int> a(4);
    Constellation::Matrix<int> b(4, 4, bValues);

    // Check if the identity matrix is actually an identity matrix
    EXPECT_EQ (true, a == b);

    // Do the same check, but from the Matrix class instead of from the Identity class
    EXPECT_EQ (true, b == a);
}

TEST (OperatorTests, IdentityMultiplication
) {
    Constellation::Identity<int> a(4);

    // Check if the identity matrix multiplied with an identity matrix equals an identity matrix
    EXPECT_EQ (a, a * a);
}

