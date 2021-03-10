//
// Created by Douwe den Blanken on 08/03/2021.
//

#ifndef CONSTELLATION_IDENTITY_HPP
#define CONSTELLATION_IDENTITY_HPP

#include <stdexcept>

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
            if (a.getWidth() == this->height && a.getWidth() == this->width) {
                return Identity<U>(this->width);
            } else {
                throw std::invalid_argument("Dimensions of identity matrices to be multiplied are not corresponding");
            }
        }
    };
}

#endif //CONSTELLATION_IDENTITY_HPP