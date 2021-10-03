//
// Created by Douwe den Blanken on 07/09/2021.
//

#ifndef CONSTELLATION_MACHINELEARNING_FUNCTIONS_HPP
#define CONSTELLATION_MACHINELEARNING_FUNCTIONS_HPP

#include <cmath>

#include "../../Matrix.hpp"

namespace Constellation {
    namespace MachineLearning {
        namespace Functions {
            template<typename U>
            U sigmoid(U const x) {
                return 1 / (1 + std::exp(-x));
            }

            /**
             * Calculate the sigmoid for each value in the matrix
             *
             * @tparam U Can only be double/float/long double
             * @param a Matrix for which the value of the sigmoid should be calculated
             * @return Matrix
             */
            template<typename U>
            Matrix<U> sigmoid(Matrix<U> const &a) {
                return a.forEveryElement(sigmoid);
            }

            template<typename U>
            Matrix<U> relu(Matrix<U> const &a) {
                return a.set(a > 0, 0);
            }
        }
    }
}

#endif //CONSTELLATION_MACHINELEARNING_FUNCTIONS_HPP
