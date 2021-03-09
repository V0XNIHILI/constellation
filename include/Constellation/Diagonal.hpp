//
// Created by Douwe den Blanken on 08/03/2021.
//

#ifndef CONSTELLATION_DIAGONAL_HPP
#define CONSTELLATION_DIAGONAL_HPP

#include "Matrix.hpp"

namespace Constellation {
    template<typename U>
    class Diagonal : public Matrix<U> {
    protected:
        U low;

    public:
        Diagonal(int d, U *v) : Matrix<U>(d, d, v) {
            low = U();
        }

        bool operator==(Matrix<U> const &a) const {
            if (a.getWidth() == this->width) {
                if (a.getHeight() == this->height) {
                    U *matrixAValues = a.getValues();

                    bool equals = true;

                    int secondDiagonalIndex = this->width + 1;

                    int j = 0;

                    for (int i = 0; i < this->size; i++) {
                        if (i % secondDiagonalIndex == 0) {
                            if (matrixAValues[i] != this->values[j]) {
                                equals = false;
                                break;
                            }

                            j += 1;
                        } else {
                            if (matrixAValues[i] != low) {
                                equals = false;
                                break;
                            }
                        }
                    }

                    return equals;
                }
            }

            return false;
        }
    };
}

#endif //CONSTELLATION_DIAGONAL_HPP
