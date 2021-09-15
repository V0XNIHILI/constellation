//
// Created by Douwe den Blanken on 12/03/2021.
//

#ifndef CONSTELLATION_COMPARISON_HPP
#define CONSTELLATION_COMPARISON_HPP

#include "../Matrix.hpp"

namespace Constellation {
    template<typename U>
    Matrix<bool> Matrix<U>::operator>=(const U &a) const {
        bool *comparedMatrixValues = new bool[size];

        for (int i = 0; i < size; i++) {
            comparedMatrixValues[i] = values[i] >= a;
        }

        Matrix<bool> c(width, height, comparedMatrixValues);

        delete[] comparedMatrixValues;

        return c;
    }

    template<typename U>
    Matrix<bool> Matrix<U>::operator>(const U &a) const {
        bool *comparedMatrixValues = new bool[size];

        for (int i = 0; i < size; i++) {
            comparedMatrixValues[i] = values[i] > a;
        }

        Matrix<bool> c(width, height, comparedMatrixValues);

        delete[] comparedMatrixValues;

        return c;
    }

    template<typename U>
    Matrix<bool> Matrix<U>::operator<(const U &a) const {
        bool *comparedMatrixValues = new bool[size];

        for (int i = 0; i < size; i++) {
            comparedMatrixValues[i] = values[i] < a;
        }

        Matrix<bool> c(width, height, comparedMatrixValues);

        delete[] comparedMatrixValues;

        return c;
    }

    template<typename U>
    Matrix<bool> Matrix<U>::operator<=(const U &a) const {
        bool *comparedMatrixValues = new bool[size];

        for (int i = 0; i < size; i++) {
            comparedMatrixValues[i] = values[i] <= a;
        }

        Matrix<bool> c(width, height, comparedMatrixValues);

        delete[] comparedMatrixValues;

        return c;
    }

    template<typename U>
    Matrix<bool> Matrix<U>::operator!=(const U &a) const {
        bool *comparedMatrixValues = new bool[size];

        for (int i = 0; i < size; i++) {
            comparedMatrixValues[i] = values[i] == a;
        }

        Matrix<bool> c(width, height, comparedMatrixValues);

        delete[] comparedMatrixValues;

        return c;
    }

    template<typename U>
    Matrix<bool> Matrix<U>::operator==(U const &a) const {
        bool *comparedMatrixValues = new bool[size];

        for (int i = 0; i < size; i++) {
            comparedMatrixValues[i] = a == values[i];
        }

        Matrix<bool> c(width, height, comparedMatrixValues);

        delete[] comparedMatrixValues;

        return c;
    }
}; // namespace Constellation

#endif //CONSTELLATION_COMPARISON_HPP
