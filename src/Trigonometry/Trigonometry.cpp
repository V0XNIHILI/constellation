//
// Created by Douwe den Blanken on 09/03/2021.
//

#include <cmath>

#include <Constellation/Trigonometry/Trigonometry.hpp>

namespace Constellation {
    namespace Trigonometry {
        template<>
        Matrix<double> sin(Matrix<double> const &a) {
            double *matrixAValues = a.getValues();

            int aWidth = a.getWidth();
            int aHeight = a.getHeight();

            int matrixSize = aWidth * aHeight;

            double *sinMatrixValues = new double[matrixSize];

            for (int i = 0; i < matrixSize; i++) {
                sinMatrixValues[i] = std::sin(matrixAValues[i]);
            }

            Matrix<double> c(aHeight, aWidth, sinMatrixValues);

            return c;
        }

        template<>
        Matrix<double> cos(Matrix<double> const &a) {
            double *matrixAValues = a.getValues();

            int aWidth = a.getWidth();
            int aHeight = a.getHeight();

            int matrixSize = aWidth * aHeight;

            double *cosMatrixValues = new double[matrixSize];

            for (int i = 0; i < matrixSize; i++) {
                cosMatrixValues[i] = std::cos(matrixAValues[i]);
            }

            Matrix<double> c(aHeight, aWidth, cosMatrixValues);

            return c;
        }
    }
}
