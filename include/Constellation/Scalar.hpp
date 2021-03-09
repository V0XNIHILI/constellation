//
// Created by Douwe den Blanken on 08/03/2021.
//

#ifndef CONSTELLATION_SCALAR_HPP
#define CONSTELLATION_SCALAR_HPP

#include "Diagonal.hpp"

namespace Constellation {
    template<typename U>
    class Scalar : public Diagonal<U> {

    public:
        U high;

        Scalar(int d, U v) : Diagonal<U>(d, new U[0]) {
            high = v;
        }

        /**
         * @brief Add a scalar matrix to the scalar matrix
         *
         * @param a Scalar matrix to be added
         * @return Scalar
         */
        Scalar<U> operator+(Scalar<U> const &a) const {
            this->checkDimensionCompatibility(a, "added");

            U summedScalarValue = high + a.high;

            Scalar<U> c(this->width, summedScalarValue);

            return c;
        }

        /**
         * @brief Subtract a scalar matrix to the scalar matrix
         *
         * @param a Scalar matrix to be subtracted
         * @return Scalar
         */
        Scalar<U> operator-(Scalar<U> const &a) const {
            this->checkDimensionCompatibility(a, "subtracted");

            U subtractedScalarValue = high - a.high;

            Scalar<U> c(this->width, subtractedScalarValue);

            return c;
        }

        /**
         * @brief Multiply a scalar matrix with another scalar matrix
         *
         * @param a Scalar matrix to be multiplied
         * @return Scalar
         */
        Scalar<U> operator*(Scalar<U> const &a) const {
            this->checkDimensionCompatibility(a, "multiplied");

            U multipliedScalarValue = high * a.high;

            Scalar<U> c(this->width, multipliedScalarValue);

            return c;
        }

        /**
         * @brief Multiply a scalar matrix with another scalar matrix
         *
         * @param a Scalar matrix to be multiplied
         * @return Scalar
         */
        Scalar<U> operator/(Scalar<U> const &a) const {
            this->checkDimensionCompatibility(a, "divided");

            U dividedScalarValue = high / a.high;

            Scalar<U> c(this->width, dividedScalarValue);

            return c;
        }

        /**
         * @brief Multiply the scalar matrix with a value to yield a scalar matrix
         *
         * @param a Value to multiply the scalar matrix with
         * @return Scalar
         */
        Scalar<U> operator*(U const &a) const {
            return Scalar<U>(this->width, a);
        }

        /**
         * @brief Divide the scalar matrix by a value to yield a scalar matrix
         *
         * @param a Value to divide the scalar matrix by
         * @return Scalar
         */
        Scalar<U> operator/(U const &a) const {
            return Scalar<U>(this->width, high / a);
        }

        /**
         * @brief Add a value to the scalar matrix to yield a scalar matrix
         *
         * @param a Value to add to the scalar matrix
         * @return Scalar
         */
        Scalar<U> operator+(U const &a) const {
            return Scalar<U>(this->width, high + a);
        }

        /**
         * @brief Subtract a value from the scalar matrix to yield a scalar matrix
         *
         * @param a Value to add from the scalar matrix
         * @return Scalar
         */
        Scalar<U> operator-(U const &a) const {
            return Scalar<U>(this->width, high - a);
        }

        U *getValues() const {
            U *matrixValues = new U[this->size];

            int secondDiagonalIndex = this->width + 1;

            for (int i = 0; i < this->size; i++) {
                if (i % secondDiagonalIndex == 0) {
                    matrixValues[i] = high;
                } else {
                    matrixValues[i] = this->low;
                }
            }

            return matrixValues;
        }
    };
}

#endif //CONSTELLATION_SCALAR_HPP
