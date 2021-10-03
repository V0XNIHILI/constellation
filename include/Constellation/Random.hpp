//
// Created by Douwe den Blanken on 10/03/2021.
//

#ifndef CONSTELLATION_RANDOM_HPP
#define CONSTELLATION_RANDOM_HPP

#include "Matrix.hpp"

namespace Constellation {
    template<typename U>
    class Random : public Matrix<U> {

    public:
        Random(int w, int h) : Matrix<U>(w, h) {}
    };
}

#endif //CONSTELLATION_RANDOM_HPP
