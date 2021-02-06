//
// Created by Douwe den Blanken on 06/02/2021.
//

// If the code is compiled with AVX2
#ifdef __AVX2__

#include <immintrin.h>

namespace Constellation
{
    template <>
    Matrix<int> Matrix<int>::operator+(Matrix<int> const &a) const
    {
        checkAddDimensions(a.getWidth(), a.getWidth());

        int *summedMatrixValues = new int[size];

        int *matrixAValues = a.getValues();

        const int amountAVX = size - size % 8;

        for (int i = 0; i < amountAVX; i += 8)
        {
            __m256i first = _mm256_load_si256((__m256i *)&values[i]);

            __m256i second = _mm256_load_si256((__m256i *)&matrixAValues[i]);

            __m256i result = _mm256_add_epi32(first, second);

            _mm256_store_si256((__m256i *)&summedMatrixValues[i], result);
        }

        const int amountSSE = size - size % 4;

        for (int i = amountAVX; i < amountSSE; i += 4)
        {
            __m128i first = _mm_load_si128((__m128i *)&values[i]);

            __m128i second = _mm_load_si128((__m128i *)&matrixAValues[i]);

            __m128i result = _mm_add_epi32(first, second);

            _mm_store_si128((__m128i *)&summedMatrixValues[i], result);
        }

        for (int i = amountSSE; i < size; i++)
        {
            summedMatrixValues[i] = values[i] + matrixAValues[i];
        }

        Matrix<int> c(width, height, summedMatrixValues, true);

        return c;
    }
}; // namespace Constellation

#endif