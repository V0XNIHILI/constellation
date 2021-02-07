//
// Created by Douwe den Blanken on 06/02/2021.
//

#include "Constellation/Matrix.h"

// If the code is compiled with AVX2
#ifdef __AVX2__

#include <immintrin.h>

namespace Constellation
{
    template<>
    Matrix<int> Matrix<int>::operator-(int const &a) const {
        int *summedMatrixValues = new int[size];

        const int amountAVX = size - size % 8;

        if(amountAVX != 0)
        {
            const __m256i firstAVX = _mm256_set1_epi32(a);

            for (int i = 0; i < amountAVX; i += 8) {
                __m256i second = _mm256_load_si256((__m256i * ) & values[i]);

                __m256i result = _mm256_sub_epi32(second, firstAVX);

                _mm256_store_si256((__m256i * ) & summedMatrixValues[i], result);
            }
        }

        const int amountSSE = size - size % 4;

        if(amountSSE != amountAVX)
        {
            const __m128i firstSSE = _mm_set1_epi32(a);

            for(int i = amountAVX; i < amountSSE; i += 4) {
                __m128i second = _mm_load_si128((__m128i * ) & values[i]);

                __m128i result = _mm_sub_epi32(second, firstSSE);

                _mm_store_si128((__m128i * ) & summedMatrixValues[i], result);
            }
        }

        for (int i = amountSSE; i < size; i++) {
            summedMatrixValues[i] = values[i] - a;
        }

        Matrix<int> c(width, height, summedMatrixValues, true);

        return c;
    }
}; // namespace Constellation

#endif