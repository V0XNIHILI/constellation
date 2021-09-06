//
// Created by Douwe den Blanken on 07/03/2021.
//

#include <stdexcept>

#include <gtest/gtest.h>

#include <Constellation/Matrix.hpp>

TEST (ConstructionTests, Matrix
) {
    int aValues[4] = {16, 2, 77, 40};

    EXPECT_THROW(Constellation::Matrix<int>(-2, 2, aValues), std::invalid_argument);
    EXPECT_THROW(Constellation::Matrix<int>(2, -2, aValues), std::invalid_argument);
    EXPECT_THROW(Constellation::Matrix<int>(-2, -2, aValues), std::invalid_argument);
    EXPECT_THROW(Constellation::Matrix<int>(0, 2, aValues), std::invalid_argument);
    EXPECT_THROW(Constellation::Matrix<int>(2, 0, aValues), std::invalid_argument);
    EXPECT_THROW(Constellation::Matrix<int>(0, 0, aValues), std::invalid_argument);
}

TEST (OperatorTests, Equals
) {
    int aValues[4] = {16, 2, 77, 40};
    int bValues[4] = {16, 3, 77, 40};
    int cValues[6] = {16, 3, 77, 40, 56, 77};

    Constellation::Matrix<int> a(2, 2, aValues);
    Constellation::Matrix<int> b(2, 2, bValues);
    Constellation::Matrix<int> c(2, 3, cValues);
    Constellation::Matrix<int> d(3, 2, cValues);

    // Check if matrices with same dimensions but different values do not equal
    EXPECT_EQ (false, a == b);

    // Check whether matrices with different dimensions do not equal
    EXPECT_EQ (false, c == b);

    // Check whether a matrix equals itself
    EXPECT_EQ (true, a == a);

    // Test whether matrices with the same values but different dimensions do not equal
    EXPECT_EQ (false, c == d);
}

TEST (OperatorTests, ValueAddition
) {
    int aValues[4] = {16, 2, 77, 40};
    int bValues[4] = {19, 5, 80, 43};
    int cValues[4] = {13, -1, 74, 37};

    Constellation::Matrix<int> a(2, 2, aValues);
    Constellation::Matrix<int> b(2, 2, bValues);
    Constellation::Matrix<int> c(2, 2, cValues);

    // Check positive addition
    EXPECT_EQ (b, a + 3);

    // Test negative addition
    EXPECT_EQ (c, a + -3);
}

TEST (OperatorTests, ValueSubtraction
) {
    int aValues[4] = {16, 2, 77, 40};
    int bValues[4] = {19, 5, 80, 43};
    int cValues[4] = {13, -1, 74, 37};

    Constellation::Matrix<int> a(2, 2, aValues);
    Constellation::Matrix<int> b(2, 2, bValues);
    Constellation::Matrix<int> c(2, 2, cValues);

    // Check positive addition
    EXPECT_EQ (c, a - 3);

    // Test negative addition
    EXPECT_EQ (b, a - -3);
}

TEST (OperatorTests, MatrixAddition
) {
    int aValues[4] = {16, 2, 77, 40};
    int bValues[4] = {19, 5, 80, 43};
    int cValues[4] = {35, 7, 157, 83};

    Constellation::Matrix<int> a(2, 2, aValues);
    Constellation::Matrix<int> b(2, 2, bValues);
    Constellation::Matrix<int> c(2, 2, cValues);

    // Check regular matrix addition
    EXPECT_EQ (c, a + b);
}

TEST (OperatorTests, MatrixMultiplication
) {
    int aValues[4] = {16, 2, 77, 40};
    int bValues[4] = {19, 5, 80, 43};
    int cValues[4] = {464, 166, 4663, 2105};

    Constellation::Matrix<int> a(2, 2, aValues);
    Constellation::Matrix<int> b(2, 2, bValues);
    Constellation::Matrix<int> c(2, 2, cValues);

    // Check regular matrix addition
    EXPECT_EQ (c, a * b);
}

TEST (MethodTests, DotProduct
) {
    int aValues[4] = {16, 2, 77, 40};
    int bValues[4] = {16, 3, 77, 40};

    Constellation::Matrix<int> a(2, 2, aValues);
    Constellation::Matrix<int> b(2, 2, bValues);

    EXPECT_EQ (7791, a.dot(b));
}

TEST (MethodTests, TransposeTest
) {
    int aValues[4] = {16, 2, 77, 40};
    int bValues[4] = {16, 77, 2, 40};

    Constellation::Matrix<int> a(2, 2, aValues);
    Constellation::Matrix<int> b(2, 2, bValues);

    EXPECT_EQ (b, a.T());
}

TEST (MethodTests, Set
) {
    int aValues[4] = {16, 2, 77, 40};
    int bValues[4] = {16, 2, 3, 3};

    Constellation::Matrix<int> a(2, 2, aValues);
    Constellation::Matrix<int> b(2, 2, bValues);

    EXPECT_EQ (b, a.set(a >= 40, 3));
}

TEST (MethodTests, EntryWiseMultiplication
) {
    int aValues[4] = {16, 2, 77, 40};
    int bValues[4] = {16, 3, 77, 40};
    int cValues[4] = {256, 6, 5929, 1600};

    Constellation::Matrix<int> a(2, 2, aValues);
    Constellation::Matrix<int> b(2, 2, bValues);
    Constellation::Matrix<int> c(2, 2, cValues);

    EXPECT_EQ (c, a.entryWise(b));
}