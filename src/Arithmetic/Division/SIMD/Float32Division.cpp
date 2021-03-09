//
// Created by Douwe den Blanken on 06/02/2021.
//

// If the code is compiled with AVX2
#ifdef __AVX2__

#include <immintrin.h>

#include <Constellation/Matrix.hpp>

namespace Constellation
{
    template<>
    Matrix<float> Matrix<float>::operator/(float const &a) const {
        float *summedMatrixValues = new float[size];

        const int amountAVX = size - size % 8;

        if(amountAVX != 0)
        {
            const __m256 firstAVX = _mm256_set1_ps(a);

            for (int i = 0; i < amountAVX; i += 8) {
                __m256 second = _mm256_load_ps((__m256 * ) & values[i]);

                __m256 result = _mm256_div_ps(second, firstAVX);

                _mm256_store_ps((__m256 * ) & summedMatrixValues[i], result);
            }
        }

        const int amountSSE = size - size % 4;

        if(amountSSE != amountAVX)
        {
            const __m128 firstSSE = _mm_set_ps1(a);

            for(int i = amountAVX; i < amountSSE; i += 4) {
                __m128 second = _mm_load_ps((__m128 * ) & values[i]);

                __m128 result = _mm_div_ps(second, firstSSE);

                _mm_store_ps((__m128 * ) & summedMatrixValues[i], result);
            }
        }

        for (int i = amountSSE; i < size; i++) {
            summedMatrixValues[i] = values[i] / a;
        }

        Matrix<float> c(width, height, summedMatrixValues, true);

        return c;
    }
}; // namespace Constellation

#endif