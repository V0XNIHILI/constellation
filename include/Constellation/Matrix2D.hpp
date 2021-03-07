//
// Created by Douwe den Blanken on 09/02/2021.
//

#ifndef CONSTELLATION_MATRIX2D_HPP
#define CONSTELLATION_MATRIX2D_HPP

#endif //CONSTELLATION_MATRIX2D_HPP

namespace Constellation {
    template<typename U>
    class Matrix2D : public Matrix<U> {
//    protected:
//        U values [4];
    public:
        Matrix2D(int d, U *v) : Matrix<U>(2, 2, v) {
            this->values
        }
    };
}