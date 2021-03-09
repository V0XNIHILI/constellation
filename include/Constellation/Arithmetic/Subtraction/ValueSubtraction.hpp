//
// Created by Douwe den Blanken on 08/02/2021.
//

#ifndef CONSTELLATION_VALUESUBTRACTION_HPP
#define CONSTELLATION_VALUESUBTRACTION_HPP

#include "../../Matrix.hpp"

namespace Constellation
{
    template <typename U>
    Matrix<U> Matrix<U>::operator-(U const &a) const
    {
        U *subtractedMatrixValues = new U[size];

        for (int i = 0; i < size; i++)
        {
            subtractedMatrixValues[i] = values[i] - a;
        }

        Matrix<U> c(width, height, subtractedMatrixValues, true);

        return c;
    }
}; // namespace Constellation

#endif //CONSTELLATION_VALUESUBTRACTION_HPP