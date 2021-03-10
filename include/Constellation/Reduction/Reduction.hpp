//
// Created by Douwe den Blanken on 10/03/2021.
//

#ifndef CONSTELLATION_REDUCTION_HPP
#define CONSTELLATION_REDUCTION_HPP

#include <algorithm>

#include "../Matrix.hpp"

namespace Constellation {
    namespace Reduction {
        template<typename U>
        U min(Matrix<U> const &a) {
            U *matrixAValues = a.getValues();

            return *std::min_element(matrixAValues, matrixAValues + a.getHeight() * a.getWidth());
        }

        template<typename U>
        U max(Matrix<U> const &a) {
            U *matrixAValues = a.getValues();

            return *std::max_element(matrixAValues, matrixAValues + a.getHeight() * a.getWidth());
        }

        template<typename U>
        U trace(Matrix<U> const &a);

        template<typename U>
        U sum(Matrix<U> const &a);

        template<typename U>
        U prod(Matrix<U> const &a);

        template<typename U>
        U avg(Matrix<U> const &a);
    }
}

#endif //CONSTELLATION_REDUCTION_HPP
