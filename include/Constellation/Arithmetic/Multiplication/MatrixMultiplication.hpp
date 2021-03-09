//
// Created by Douwe den Blanken on 08/02/2021.
//

#ifndef CONSTELLATION_MATRIXMULTIPLICATION_HPP
#define CONSTELLATION_MATRIXMULTIPLICATION_HPP

#include <stdexcept>

#include "../../Matrix.hpp"

namespace Constellation {
    template<typename U>
    Matrix <U> Matrix<U>::operator*(Matrix <U> const &a) const {
        int matrixAWidth = a.getWidth();

        int matrixAHeight = a.getHeight();

        if (matrixAWidth == height && matrixAHeight == width) {
            U *multipliedMatrixValues = new U[size];

            U *matrixAValues = a.getValues();

            int kTimesAWidth[matrixAHeight];

            for (int k = 0; k < matrixAHeight; k++) {
                kTimesAWidth[k] = k * matrixAWidth;
            }

            int jTimesWidth[width];

            for (int j = 0; j < width; j++) {
                jTimesWidth[j] = j * width;
            }

            //            std::for_each(std::execution::par_unseq, 0, matrixAWidth, [&](int i) {
            for (int i = 0; i < matrixAWidth; i++) {
                for (int j = 0; j < height; j++) {
                    int locationInNewMatrix = j * matrixAWidth + i;

                    int location = jTimesWidth[j];

                    multipliedMatrixValues[locationInNewMatrix] = 0;

                    // j, i =============> j, k =>>>>>>>>>> k , i
                    for (int k = 0; k < matrixAHeight; k++) {
                        // Updating the value in the matrix is faster than summing and then setting the value in the matrix to the sum (about 7% faster)
                        multipliedMatrixValues[locationInNewMatrix] +=
                                values[location + k] * matrixAValues[kTimesAWidth[k] + i];
                    }
                }
            }
            //            });

            Matrix<U> c(matrixAWidth, height, multipliedMatrixValues, true);

            return c;
        } else {
            throw std::invalid_argument("Dimensions of matrices to be multiplied are not corresponding");
        }
    }
}; // namespace Constellation

#endif //CONSTELLATION_MATRIXMULTIPLICATION_HPP
