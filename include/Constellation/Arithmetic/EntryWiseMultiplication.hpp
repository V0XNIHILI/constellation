//
// Created by Douwe den Blanken on 09/03/2021.
//

#ifndef CONSTELLATION_ENTRYWISEMULTIPLICATION_HPP
#define CONSTELLATION_ENTRYWISEMULTIPLICATION_HPP

#include "../Matrix.hpp"

namespace Constellation {
    template<typename U>
    Matrix <U> Matrix<U>::entryWise(Matrix <U> const &a) const {
        checkDimensionCompatibility(a, "multiplied entrywise");

        U *entryWiseMultipliedMatrixValues = new U[size];

        U *matrixAValues = a.getValues();

        for (int i = 0; i < size; i++) {
            entryWiseMultipliedMatrixValues[i] = values[i] * matrixAValues[i];
        }

        Matrix <U> c(width, height, entryWiseMultipliedMatrixValues, true);

        return c;

    }
}; // namespace Constellation

#endif //CONSTELLATION_ENTRYWISEMULTIPLICATION_HPP
