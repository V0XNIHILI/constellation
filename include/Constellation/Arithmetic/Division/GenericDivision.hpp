//
// Created by Douwe den Blanken on 08/02/2021.
//

namespace Constellation
{
    template <typename U>
    Matrix<U> Matrix<U>::operator/(U const &a) const
    {
        U *dividedMatrixValues = new U[size];

        for (int i = 0; i < size; i++)
        {
            dividedMatrixValues[i] = values[i] / a;
        }

        Matrix<U> c(width, height, dividedMatrixValues, true);

        return c;
    }
} // namespace Constellation
