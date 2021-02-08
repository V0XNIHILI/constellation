//
// Created by Douwe den Blanken on 08/02/2021.
//

#include <stdexcept>

namespace Constellation {
    template<typename U>
    Matrix <U> Matrix<U>::operator-(Matrix <U> const &a) const {
        checkDimensionCompatibility(a, "subtracted");

        U *subtractedMatrixValues;

        subtractedMatrixValues = new U[size];

        U *matrixAValues = a.getValues();

        for (int i = 0; i < size; i++) {
            subtractedMatrixValues[i] = values[i] - matrixAValues[i];
        }

        Matrix<U> c(width, height, subtractedMatrixValues, true);

        return c;

    }
}; // namespace Constellation