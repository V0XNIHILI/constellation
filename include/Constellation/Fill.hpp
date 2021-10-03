//
// Created by Douwe den Blanken on 09/03/2021.
//

#ifndef CONSTELLATION_FILL_HPP
#define CONSTELLATION_FILL_HPP

#include "Matrix.hpp"

namespace Constellation {
    template<typename U>
    class Fill : public Matrix<U> {

    public:
        Fill(int w, int h) : Matrix<U>(w, h) {}
    };
}

#endif //CONSTELLATION_FILL_HPP
