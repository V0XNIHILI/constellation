//
// Created by Douwe den Blanken on 08/02/2021.
//

namespace Constellation {
    template<typename U>
    Matrix <U> Matrix<U>::operator+(Matrix <U> const &a) const {
        checkDimensionCompatibility(a, "added");

        U *summedMatrixValues = new U[size];

        U *matrixAValues = a.getValues();

        for (int i = 0; i < size; i++) {
            summedMatrixValues[i] = values[i] + matrixAValues[i];
        }

        Matrix<U> c(width, height, summedMatrixValues, true);

        return c;
    }
}; // namespace Constellation
