//
// Created by Douwe den Blanken on 08/02/2021.
//

namespace Constellation {
    template<typename U>
    Matrix <U> Matrix<U>::operator/(Matrix <U> const &a) const {
        checkDimensionCompatibility(a, "divided");

        U *dividedMatrixValues = new U[size];

        U *matrixAValues = a.getValues();

        for (int i = 0; i < size; i++) {
            dividedMatrixValues[i] = values[i] / matrixAValues[i];
        }

        Matrix <U> c(width, height, dividedMatrixValues, true);

        return c;

    }
}; // namespace Constellation
