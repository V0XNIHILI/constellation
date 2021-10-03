//
// Created by Douwe den Blanken on 06/09/2021.
//

#include <gtest/gtest.h>

#include <Constellation/Matrix.hpp>

#include <Constellation/Functions/Functions.hpp>

#include <Constellation/MachineLearning/Functions/Functions.hpp>

TEST (FunctionTests, Exponential
) {
    float aValues[16] = {0.0, 0.0, 0.0, 0,
                       0.0, 0.0, 0.0, 0,
                       0.0, 0, 7.0, 0,
                       0.0, 0.0, 0, -3.0};

    Constellation::Matrix<float> a(4, 4, aValues);

    // Check if the exponential is calculated correctly
    EXPECT_EQ (a, Constellation::Functions::exp(a));
}

TEST (FunctionTests, Sigmoid
) {
    float aValues[16] = {0.0, 0.0, 0.0, 0,
                         0.0, 0.0, 0.0, 0,
                         0.0, 0, 7.0, 0,
                         0.0, 0.0, 0, -3.0};

    Constellation::Matrix<float> a(4, 4, aValues);

    // Check if the exponential is calculated correctly
    EXPECT_EQ (a, Constellation::MachineLearning::Functions::sigmoid(a));
}


TEST (ReductionTests, MinMax
) {
    int aValues[16] = {0, 0, 0, 0,
                       0, 0, 0, 0,
                       0, 0, 7, 0,
                       0, 0, 0, -3};

    Constellation::Matrix<int> a(4, 4, aValues);

    // Check if the maximum is found correctly
    EXPECT_EQ (7, Constellation::Functions::max(a));

    // Check if the minimum is found correctly
    EXPECT_EQ (-3, Constellation::Functions::min(a));
}

TEST (ReductionTests, Sum
) {
    int aValues[16] = {0, 0, 1, 0,
                       0, 8, 0, 0,
                       0, 0, 7, 0,
                       0, 0, 0, -3};

    Constellation::Matrix<int> a(4, 4, aValues);

    // Check if the sum is found correctly
    EXPECT_EQ (13, Constellation::Functions::sum(a));
}

TEST (ReductionTests, Product
) {
    int aValues[4] = {1, 3,
                      3, 8};

    Constellation::Matrix<int> a(2, 2, aValues);

    // Check if the product is found correctly
    EXPECT_EQ (72, Constellation::Functions::prod(a));
}

TEST (ReductionTests, Trace
) {
    int aValues[4] = {23, 3,
                      3, -1};

    Constellation::Matrix<int> a(2, 2, aValues);

    // Check if the trace is found correctly
    EXPECT_EQ (22, Constellation::Functions::tr(a));
}

TEST (ReductionTests, Average
) {
    int aValues[4] = {2, 3,
                      4, 8};

    Constellation::Matrix<int> a(2, 2, aValues);

    // Check if the average is found correctly
    EXPECT_EQ (4, Constellation::Functions::avg(a));
}
