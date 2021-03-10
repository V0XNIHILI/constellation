//
// Created by Douwe den Blanken on 09/03/2021.
//

#include <cmath>

#include <Constellation/Trigonometry/Trigonometry.hpp>

namespace Constellation {
    namespace Trigonometry {
        template<>
        Matrix<float> sin(Matrix<float> const &a) {
            float *matrixAValues = a.getValues();

            int aWidth = a.getWidth();
            int aHeight = a.getHeight();

            int matrixSize = aWidth * aHeight;

            float *sinMatrixValues = new float[matrixSize];

            for (int i = 0; i < matrixSize; i++) {
                sinMatrixValues[i] = std::sin(matrixAValues[i]);
            }

            Matrix<float> c(aHeight, aWidth, sinMatrixValues);

            return c;
        }

        template<>
        Matrix<float> cos(Matrix<float> const &a) {
            float *matrixAValues = a.getValues();

            int aWidth = a.getWidth();
            int aHeight = a.getHeight();

            int matrixSize = aWidth * aHeight;

            float *cosMatrixValues = new float[matrixSize];

            for (int i = 0; i < matrixSize; i++) {
                cosMatrixValues[i] = std::cos(matrixAValues[i]);
            }

            Matrix<float> c(aHeight, aWidth, cosMatrixValues);

            return c;
        }
    }
}
