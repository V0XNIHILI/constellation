//
// Created by Douwe den Blanken on 07/03/2021.
//

#include <iostream>
#include <Constellation/Matrix.hpp>

namespace Constellation {
    template<>
    Matrix<int> Matrix<int>::operator+(int const &a) const {
        int *summedMatrixValues = new int[size];

        for (int i = 0; i < size; i++) {
            summedMatrixValues[i] = values[i] + a;
        }

        Matrix<int> c(width, height, summedMatrixValues, true);

        return c;
    }
}
