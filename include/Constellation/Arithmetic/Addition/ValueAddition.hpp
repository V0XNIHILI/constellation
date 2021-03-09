//
// Created by Douwe den Blanken on 08/02/2021.
//

#ifndef CONSTELLATION_VALUEADDITION_HPP
#define CONSTELLATION_VALUEADDITION_HPP

#include "../../Matrix.hpp"

namespace Constellation {
    template<typename U>
    Matrix <U> Matrix<U>::operator+(U const &a) const {
        U *summedMatrixValues = new U[size];

        for (int i = 0; i < size; i++)
        {
            summedMatrixValues[i] = values[i] + a;
        }

        Matrix<U> c(width, height, summedMatrixValues, true);

        return c;
    }
}; // namespace Constellation

#endif //CONSTELLATION_VALUEADDITION_HPP