//
// Created by Douwe den Blanken on 01/02/2021.
//

#ifndef CONSTELLATION_COLUMNVECTOR_HPP
#define CONSTELLATION_COLUMNVECTOR_HPP

#include "Matrix.hpp"

namespace Constellation {
    template<typename U>
    class ColumnVector : public Matrix<U> {
    public:
        ColumnVector(int d, U *v) : Matrix<U>(1, d, v) {}
    };
}

#endif //CONSTELLATION_COLUMNVECTOR_HPP