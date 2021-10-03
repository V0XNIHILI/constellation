//
// Created by Douwe den Blanken on 09/03/2021.
//

#ifndef CONSTELLATION_FUNCTIONS_HPP
#define CONSTELLATION_FUNCTIONS_HPP

#include <algorithm>
#include <numeric>
#include <cmath>

#include "../Matrix.hpp"

namespace Constellation {
    namespace Functions {
        /**
         * Calculate the cosine for each value in the matrix
         *
         * @tparam U Can only be double/float/long double
         * @param a Matrix for which the value of sin should be calculated
         * @return Matrix
         */
        template<typename U>
        Matrix<U> sin(Matrix<U> const &a) {
            return a.forEveryElement(std::sin);
        }

        /**
         * Calculate the cosine for each value in the matrix
         *
         * @tparam U Can only be double/float/long double
         * @param a Matrix for which the value of cos should be calculated
         * @return Matrix
         */
        template<typename U>
        Matrix<U> cos(Matrix<U> const &a) {
            return a.forEveryElement(std::cos);
        }

        /**
         * Calculate the exponential function for each value in the matrix
         *
         * @tparam U Can only be double/float/long double
         * @param a Matrix for which the exponent should be calculated
         * @return Matrix
         */
        template<typename U>
        Matrix<U> exp(Matrix<U> const &a) {
            return a.forEveryElement(std::exp);
        }

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
        U tr(Matrix<U> const &a) {
            int width = a.getWidth();
            int height = a.getHeight();
            int size = width * height;

            if(width != height) {
                throw std::invalid_argument("Trace of a matrix is only defined for square matrices");
            }

            U *matrixAValues = a.getValues();

            U trace = U();

            int step = width+1;

            for (int i = 0; i < size; i+=step) {
                trace += matrixAValues[i];
            }

            return trace;
        }

        template<typename U>
        U sum(Matrix<U> const &a) {
            U *matrixAValues = a.getValues();

            return std::accumulate(matrixAValues, matrixAValues + a.getHeight() * a.getWidth(), 0);
        }

        template<typename U>
        U prod(Matrix<U> const &a) {
            U *matrixAValues = a.getValues();

            return std::accumulate(matrixAValues, matrixAValues + a.getHeight() * a.getWidth(), 1, std::multiplies<U>());
        }

        template<typename U>
        U avg(Matrix<U> const &a) {
            return sum(a) / (a.getHeight() * a.getWidth());
        }
    }
}

#endif //CONSTELLATION_FUNCTIONS_HPP
