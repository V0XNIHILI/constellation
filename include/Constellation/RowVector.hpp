//
// Created by Douwe den Blanken on 01/02/2021.
//

#ifndef CONSTELLATION_ROWVECTOR_HPP
#define CONSTELLATION_ROWVECTOR_HPP

#include "Matrix.hpp"

namespace Constellation {
    template<typename U>
    class RowVector : public Matrix<U> {
    public:
        RowVector(int d, U *v) : Matrix<U>(d, 1, v) {}
    };
}

#endif //CONSTELLATION_COLUMNVECTOR_HPP