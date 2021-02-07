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

integers = {
    "typeU": "int",
    "widthAVX": "8",
    "widthSSE": "4",
    "typeAVX": "__m256i",
    "typeSSE": "__m128i",
    "addAVX": "_mm256_add_epi32",
    "addSSE": "_mm_add_epi32",
    "loadAVX": "_mm256_load_si256",
    "loadSSE": "_mm_load_si128",
    "storeAVX": "_mm256_store_si256",
    "storeSSE": "_mm_store_si128",
    "set1AVX": "_mm256_set1_epi32",
    "set1SSE": "_mm_set1_epi32",
}

floats = {
    "typeU": "float",
    "widthAVX": "8",
    "widthSSE": "4",
    "typeAVX": "__m256",
    "typeSSE": "__m128",
    "addAVX": "_mm256_add_ps",
    "addSSE": "_mm_add_ps",
    "loadAVX": "_mm256_load_ps",
    "loadSSE": "_mm_load_ps",
    "storeAVX": "_mm256_store_ps",
    "storeSSE": "_mm_store_ps",
    "set1AVX": "_mm256_set1_ps",
    "set1SSE": "_mm_set_ps1",
}

result = matrix_addition

for key in floats:
   result = result.replace(key, floats[key])

print(result)