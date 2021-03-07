//
// Created by Douwe den Blanken on 01/02/2021.
//

#ifndef CONSTELLATION_VECTOR_HPP
#define CONSTELLATION_VECTOR_HPP

#endif //CONSTELLATION_VECTOR_HPP

namespace Constellation {
    template<typename U>
    class Vector : public Matrix<U> {
    public:
        Vector(int d, U *v) : Matrix<U>(1, d, v) {}
    };
}