int32 = {
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

float32 = {
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

# -------------------------------------------------------------------------------------------------

def update_addition_for_data_type(dict, operation):
    result = operation

    for key in dict:
        result = result.replace(key, dict[key])

    return result

def update_addition_for_division(operation):
    return operation.replace('>::operator+', '>::operator/').replace('+ a', '/ a').replace('_add_', '_div_')
    
def update_addition_for_subtraction(operation):
    return operation.replace('>::operator+', '>::operator-').replace('+ a', '- a').replace('_add_', '_sub_')
    
def update_addition_for_multiplication(operation):
    return operation.replace('>::operator+', '>::operator*').replace('+ a', '* a').replace('_add_', '_mul_')
    
# -------------------------------------------------------------------------------------------------

matrix_operation = """//
// Created by Douwe den Blanken on 06/02/2021.
//

#include "Constellation/Matrix.h"

// If the code is compiled with AVX2
#ifdef __AVX2__

#include <immintrin.h>

namespace Constellation
{
    template<>
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
    }
}; // namespace Constellation

#endif"""

# -------------------------------------------------------------------------------------------------

int32_addition = update_addition_for_data_type(int32, matrix_operation)
int32_division = update_addition_for_division(int32_addition)
int32_subtraction = update_addition_for_subtraction(int32_addition)
int32_multiplication = update_addition_for_multiplication(int32_addition)

float32_addition = update_addition_for_data_type(float32, matrix_operation)
float32_division = update_addition_for_division(float32_addition)
float32_subtraction = update_addition_for_subtraction(float32_addition)
float32_multiplication = update_addition_for_multiplication(float32_addition)

# -------------------------------------------------------------------------------------------------

avx_sse_path = "src/avx_sse/"

int32_name = 'int32'
float32_name = 'float32'

addition_path = "addition/"
addition_suffix = "_addition.cpp"

division_path = "division/"
division_suffix = "_division.cpp"

subtraction_path = "subtraction/"
subtraction_suffix = "_subtraction.cpp"

multiplication_path = "multiplication/"
multiplication_suffix = "_multiplication.cpp"

# -------------------------------------------------------------------------------------------------

# int32

f = open(avx_sse_path + addition_path + int32_name + addition_suffix, 'w')
f.write(int32_addition)
f.close()

f = open(avx_sse_path + division_path + int32_name + division_suffix, 'w')
f.write(int32_division)
f.close()

f = open(avx_sse_path + subtraction_path + int32_name + subtraction_suffix, 'w')
f.write(int32_subtraction)
f.close()

f = open(avx_sse_path + multiplication_path + int32_name + multiplication_suffix, 'w')
f.write(int32_multiplication)
f.close()

# -------------------------------------------------------------------------------------------------

# float32

f = open(avx_sse_path + addition_path + float32_name + addition_suffix, 'w')
f.write(float32_addition)
f.close()

f = open(avx_sse_path + division_path + float32_name + division_suffix, 'w')
f.write(float32_division)
f.close()

f = open(avx_sse_path + subtraction_path + float32_name + subtraction_suffix, 'w')
f.write(float32_subtraction)
f.close()

f = open(avx_sse_path + multiplication_path + float32_name + multiplication_suffix, 'w')
f.write(float32_multiplication)
f.close()

# -------------------------------------------------------------------------------------------------