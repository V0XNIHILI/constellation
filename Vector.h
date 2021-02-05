//
// Created by Douwe den Blanken on 01/02/2021.
//

#ifndef VECTOR_H
#define VECTOR_H

#endif //VECTOR_H

namespace Constellation {
    template<typename U>
    class Vector : public Matrix<U> {
    public:
        Vector(int d, U *v) : Matrix<U>(1, d, v) {}
    };
}