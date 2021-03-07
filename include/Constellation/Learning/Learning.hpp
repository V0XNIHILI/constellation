//
// Created by Douwe den Blanken on 10/02/2021.
//

#ifndef CONSTELLATION_LEARNING_HPP
#define CONSTELLATION_LEARNING_HPP

#endif //CONSTELLATION_LEARNING_HPP

#include <cmath>

namespace Constellation {
    namespace Learning {
        template<typename U>
        class Layer {
            // activation types + backpropagation + weights
        private:
            Matrix <U> *weights;

        };

        template<typename U>
        /**
         * (Neural) network class
         *
         * @tparam U type of data that the network should process
         */
        class Network {
        private:
            Layer *layers;
        };

        namespace Activation {
            template<typename U>
            Matrix <U> ReLU(Matrix < U >
            const &a) {
            int width = a.getWidth();
            int height = a.getHeight();
            int size = width * height;

            U zeroValue = U();

            U *reluMatrixValues = new U[size];

            U *matrixAValues = a.getValues();

            for (
            int i = 0;
            i<size;
            i++) {
            reluMatrixValues[i] = (matrixAValues[i] > zeroValue) ? matrixAValues[i] :
            zeroValue;
        }

        Matrix <U> c(width, height, reluMatrixValues, true);

        return
        c;
    }

    Matrix<double> Sigmoid(Matrix < double >
    const &a) {
    int width = a.getWidth();
    int height = a.getHeight();
    int size = width * height;

    double *sigmoidMatrixValues = new double[size];

    double *matrixAValues = a.getValues();

    for (
    int i = 0;
    i<size;
    i++) {
    sigmoidMatrixValues[i] = 1 / (1 + std::exp(-matrixAValues[i]));
}

Matrix<double> c(width, height, sigmoidMatrixValues, true);

return
c;
}

Matrix<float> Sigmoid(Matrix < float >
const &a) {
int width = a.getWidth();
int height = a.getHeight();
int size = width * height;

float *sigmoidMatrixValues = new float[size];

float *matrixAValues = a.getValues();

for (
int i = 0;
i<size;
i++) {
sigmoidMatrixValues[i] = 1 / (1 + std::exp(-matrixAValues[i]));
}

Matrix<float> c(width, height, sigmoidMatrixValues, true);

return
c;
}
}
}
}
