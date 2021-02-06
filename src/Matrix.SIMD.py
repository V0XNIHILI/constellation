# typeU
# widthAVX
# widthSSE
# typeAVX
# typeSSE
# addAVX
# addSSE
# loadAVX
# loadSSE
# storeAVX
# storeSSE
# set1AVX
# set1SSE

matrix_addition = """    template<>
    Matrix<typeU> Matrix<typeU>::operator+(typeU const &a) const {
        typeU *summedMatrixValues = new typeU[size];

        const int amountAVX = size - size % widthAVX;

        if(amountAVX != 0)
        {
            const typeAVX firstAVX = set1AVX(a);

            for (int i = 0; i < amountAVX; i += 8) {
                typeAVX second = loadAVX((typeAVX * ) & values[i]);

                typeAVX result = addAVX(second, firstAVX);

                storeAVX((typeAVX * ) & summedMatrixValues[i], result);
            }
        }

        const int amountSSE = size - size % widthSSE;

        if(amountSSE != amountAVX)
        {
            const typeSSE firstSSE = set1SSE(a);

            for(int i = amountAVX; i < amountSSE; i += 4) {
                typeSSE second = loadSSE((typeSSE * ) & values[i]);

                typeSSE result = addSSE(second, firstSSE);

                storeSSE((typeSSE * ) & summedMatrixValues[i], result);
            }
        }

        for (int i = amountSSE; i < size; i++) {
            summedMatrixValues[i] = values[i] + a;
        }

        Matrix<typeU> c(width, height, summedMatrixValues, true);

        return c;
    }"""

result = matrix_addition.replace("typeU", "int").replace("widthAVX", "8").replace("widthSSE", "4").replace("typeAVX", "__m256i").replace("typeSSE", "__m128i")
result = result.replace("addAVX", "_mm256_add_epi32").replace("addSSE", "_mm_add_epi32").replace("loadAVX", "_mm256_load_si256").replace("loadSSE", "_mm_load_si128").replace("storeAVX", "_mm256_store_si256")
result = result.replace("storeSSE", "_mm_store_si128").replace("set1AVX", "_mm256_set1_epi32").replace("set1SSE", "_mm_set1_epi32")
# typeU
# widthAVX
# widthSSE
# typeAVX
# typeSSE
# addAVX
# addSSE
# loadAVX
# loadSSE
# storeAVX
# storeSSE
# set1AVX
# set1SSE

print(result)