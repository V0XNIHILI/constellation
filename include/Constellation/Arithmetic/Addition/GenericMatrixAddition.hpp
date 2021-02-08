//
// Created by Douwe den Blanken on 08/02/2021.
//

#include <stdexcept>

namespace Constellation
{
    template <typename U>
    Matrix<U> Matrix<U>::operator+(Matrix<U> const &a) const
    {
        if (a.getWidth() == width)
        {
            if (a.getHeight() == height)
            {
                U *summedMatrixValues = new U[size];

                U *matrixAValues = a.getValues();

                for (int i = 0; i < size; i++)
                {
                    summedMatrixValues[i] = values[i] + matrixAValues[i];
                }

                Matrix<U> c(width, height, summedMatrixValues, true);

                return c;
            }
            else
            {
                throw std::invalid_argument("Heights of matrices to be added do not match");
            }
        }
        else
        {
            throw std::invalid_argument("Widths of matrices to be added do not match");
        }
    }
}; // namespace Constellation
