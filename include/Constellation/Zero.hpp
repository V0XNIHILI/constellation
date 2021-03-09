//
// Created by Douwe den Blanken on 09/03/2021.
//

#ifndef CONSTELLATION_ZERO_HPP
#define CONSTELLATION_ZERO_HPP

#include "Scalar.hpp"

namespace Constellation {
    template<typename U>
    class Zero : public Scalar<U> {

    public:
        Zero(int d) : Scalar<U>(d, U()) {}

        /**
         * @brief Multiply the zero matrix with a value to yield a zero matrix
         *
         * @param a Value to multiply the zero matrix with
         * @return Zero
         */
        Zero<U> operator*(U const &a) const {
            return Zero<U>(this->width);
        }

        /**
         * @brief Divide the zero matrix by a value to yield a zero matrix
         *
         * @param a Value to divide the zero matrix by
         * @return Zero
         */
        Zero<U> operator/(U const &a) const {
            return Zero<U>(this->width);
        }

        /**
         * @brief Add a scalar matrix to the zero matrix
         *
         * @param a Scalar matrix to be added
         * @return Matrix
         */
        Scalar<U> operator+(Scalar<U> const &a) const {
            this->checkDimensionCompatibility(a, "added");

            return Scalar<U>(a.high);
        }

        bool operator==(Matrix<U> const &a) const {
            if (a.getWidth() == this->width) {
                if (a.getHeight() == this->height) {
                    U *matrixAValues = a.getValues();

                    bool equals = true;

                    for (int i = 0; i < this->size; i++) {
                        if (matrixAValues[i] != this->low) {
                            equals = false;
                            break;
                        }

                    }

                    return equals;
                }
            }

            return false;
        }

        Zero<U> T() const {
            return Zero<U>(this->width);
        }
    };
}

#endif //CONSTELLATION_ZERO_HPP
