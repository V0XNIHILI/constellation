//
// Created by Douwe den Blanken on 08/03/2021.
//

#ifndef CONSTELLATION_IDENTITY_HPP
#define CONSTELLATION_IDENTITY_HPP

#include "Scalar.hpp"

namespace Constellation {
    template<typename U>
    class Identity : public Scalar<U> {

    public:
        Identity(int d) : Scalar<U>(d, U() + 1) {}

        /**
         * @brief Multiply the identity matrix with another identity matrix
         *
         * @param a Identity matrix to be multiplied with
         * @return Matrix
         */
        Identity<U> operator*(Identity<U> const &a) const {
            checkDimensionCompatibility(a);

            return Identity<U>(this->width);
        }
    };
}

#endif //CONSTELLATION_IDENTITY_HPP