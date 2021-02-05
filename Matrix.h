//
// Created by Douwe den Blanken on 01/02/2021.
//

#ifndef MATRIX_H
#define MATRIX_H

#endif //MATRIX_H

#include <stdexcept>
#include <iostream>
#include <immintrin.h>

namespace Constellation {
    template<typename U>
    /**
     * Matrix class
     *
     * @tparam U type of data that the matrix should hold
     */
    class Matrix {
    protected:
        // Width of the matrix
        int width;

        // Height of the matrix
        int height;

        // Amount of values in matrix. This property is kept separate from width and height, because in
        // looping over the values of the matrix, this value is often used and thus does not have to be
        // recomputed every time
        int size;

        // Values of the matrix
        U *values;

        /**
         * @brief Construct a new Matrix object based on a width and height.
         *
         * @param w Width of the matrix
         * @param h Height of the matrix
         * @param v 1D-Array of values that the matrix should contain (should contain w * h entries)
         * @param passByPointer Whether or not to copy the values into the values array of the matrix. True = copying
         * the pointer, false = copying the values
         */
        Matrix(int w, int h, U *v, bool passByPointer) {
            if (w > 0) {
                if (h > 0) {
                    width = w;
                    height = h;

                    size = h * w;

                    if (passByPointer == true) {
                        values = v;
                    } else {
                        values = new U[size];

                        // Copy the numerical values from the array into the matrix
                        // Copying speed on MacBook Pro 2014: n^2 * 2.015625E-6 ms
                        for (int i = 0; i < size; i++) {
                            values[i] = v[i];
                        }
                    }
                } else {
                    throw std::invalid_argument("Matrix height should be larger than 0");
                }
            } else {
                throw std::invalid_argument("Matrix width should be larger than 0");
            }
        }

    public:
        ~Matrix() {
            delete[] values;
        }

        /**
         * @brief Construct a new Matrix object based on given values. Generic type should be of type number or of type Matrix
         *
         * @param w Width of the matrix
         * @param h Height of the matrix
         * @param v 1D-Array of values that the matrix should contain (should contain w * h entries)
         */
        Matrix(int w, int h, U *v) : Matrix(w, h, v, false) {}

        /**
         * @brief Add two matrices
         *
         * @todo Can be sped up using SIMD
         *
         * @param a Matrix to be added
         * @return Matrix
         */
        Matrix<U> operator+(Matrix<U> const &a) const;

        /**
         * @brief Add a certain value from the matrix
         *
         * @param a Value to add to all matrix entries
         * @return Matrix
         */
        Matrix<U> operator+(U const &a) const {
            U *summedMatrixValues = new U[size];

            for (int i = 0; i < size; i++) {
                summedMatrixValues[i] = values[i] + a;
            }

            Matrix<U> c(width, height, summedMatrixValues, true);

            return c;
        }

        /**
         * @brief Subtract one matrix from another
         *
         * @param a Matrix to be subtracted
         * @return Matrix
         */
        Matrix<U> operator-(Matrix const &a) const {
            if (a.getWidth() == width) {
                if (a.getHeight() == height) {
                    U *subtractedMatrixValues;

                    subtractedMatrixValues = new U[size];

                    U *matrixAValues = a.getValues();

                    for (int i = 0; i < size; i++) {
                        subtractedMatrixValues[i] = values[i] - matrixAValues[i];
                    }

                    Matrix<U> c(width, height, subtractedMatrixValues, true);

                    return c;
                } else {
                    throw std::invalid_argument("Heights of matrices to be subtracted do not match");
                }
            } else {
                throw std::invalid_argument("Widths of matrices to be subtracted do not match");
            }
        }

        /**
         * @brief Subtract a certain value from the matrix
         *
         * @param a Value to subtract from all matrix entries
         * @return Matrix
         */
        Matrix<U> operator-(U const &a) const {
            U *subtractedMatrixValues = new U[size];

            for (int i = 0; i < size; i++) {
                subtractedMatrixValues[i] = values[i] - a;
            }

            Matrix<U> c(width, height, subtractedMatrixValues, true);

            return c;
        }

        /**
         * @brief Multiply two matrices
         *
         * @todo look at SIMD (http://www.cs.uu.nl/docs/vakken/magr/2017-2018/files/SIMD%20Tutorial.pdf)
         * @todo Implement strassen
         * @todo Parallelize it
         *
         * @param a Matrix to be multiplied
         * @return Matrix
         */
        Matrix<U> operator*(Matrix<U> const &a) const {
            int matrixAWidth = a.getWidth();

            int matrixAHeight = a.getHeight();

            if (matrixAWidth == height && matrixAHeight == width) {
                U *multipliedMatrixValues = new U[size];

                U *matrixAValues = a.getValues();

                int kTimesAWidth[matrixAHeight];

                for (int k = 0; k < matrixAHeight; k++) {
                    kTimesAWidth[k] = k * matrixAWidth;
                }

                int jTimesWidth[width];

                for (int j = 0; j < width; j++) {
                    jTimesWidth[j] = j * width;
                }

//            std::for_each(std::execution::par_unseq, 0, matrixAWidth, [&](int i) {
                for (int i = 0; i < matrixAWidth; i++) {
                    for (int j = 0; j < height; j++) {
                        int locationInNewMatrix = j * matrixAWidth + i;

                        int location = jTimesWidth[j];

                        multipliedMatrixValues[locationInNewMatrix] = 0;

                        // j, i =============> j, k =>>>>>>>>>> k , i
                        for (int k = 0; k < matrixAHeight; k++) {
                            // Updating the value in the matrix is faster than summing and then setting the value in the matrix to the sum (about 7% faster)
                            multipliedMatrixValues[locationInNewMatrix] +=
                                    values[location + k] * matrixAValues[kTimesAWidth[k] + i];
                        }
                    }
                }
//            });

                Matrix<U> c(matrixAWidth, height, multipliedMatrixValues, true);

                return c;
            } else {
                throw std::invalid_argument("Dimensions of matrices to be multiplied are not corresponding");
            }
        }

        /**
         * @brief Multiply the matrix with a certain value
         *
         * @param a Value to multiply matrix with
         * @return Matrix
         */
        Matrix<U> operator*(U const &a) const {
            U *multipliedMatrixValues = new U[size];

            for (int i = 0; i < size; i++) {
                multipliedMatrixValues[i] = values[i] * a;
            }

            Matrix<U> c(width, height, multipliedMatrixValues, true);

            return c;
        }

        /**
         * @brief Calculate the dot product of two matrices
         *
         * @param a Matrix using which the dot product should be calculated
         * @return Matrix
         */
        U dot(Matrix<U> const &a) const {
            if (a.getWidth() == width) {
                if (a.getHeight() == height) {
                    U dotProduct = U();

                    U *matrixAValues = a.getValues();

                    for (int i = 0; i < size; i++) {
                        dotProduct += values[i] * matrixAValues[i];
                    }

                    return dotProduct;
                } else {
                    throw std::invalid_argument("Heights of matrices to be added do not match");
                }
            } else {
                throw std::invalid_argument("Widths of matrices to be added do not match");
            }
        }

//    /**
//     * @brief Raise all entries in the matrix to a certain power
//     *
//     * @param a Value to raise all matrix entries to the power by
//     * @return Matrix
//     */
//    Matrix operator^(float const &a) const {
//        float *raisedMatrixValues = new float[size];
//
//        for (int i = 0; i < size; i++) {
//            raisedMatrixValues[i] = std::pow(values[i], a);
//        }
//
//        Matrix c(width, height, raisedMatrixValues);
//
//        delete[] raisedMatrixValues;
//
//        return c;
//    }

        /**
         * @brief Divide the matrix by a certain value
         *
         * @param a Value to divide all matrix entries by
         * @return Matrix
         */
        Matrix<U> operator/(Matrix<U> const &a) const {
            U *dividedMatrixValues = new U[size];

            for (int i = 0; i < size; i++) {
                dividedMatrixValues[i] = values[i] / a;
            }

            Matrix<U> c(width, height, dividedMatrixValues, true);

            return c;
        }

        /**
         * @brief Return the transpose of the matrix
         *
         * @return Matrix
         */
        Matrix<U> T() const {
            U *transposedMatrixValues = new U[size];

            for (int i = 0; i < size; i++) {
                int valueLocation = (i / width) + (i % width) * height;

                transposedMatrixValues[i] = values[valueLocation];
            }

            Matrix<U> c(height, width, transposedMatrixValues, true);

            return c;
        }

        /**
         * Returns the width of the matrix
         *
         * @return int
         */
        int getWidth() const {
            return width;
        }

        /**
         * Returns the height of the matrix
         *
         * @return int
         */
        int getHeight() const {
            return height;
        }

        /**
         * Returns the values of the matrix in a 1D array
         *
         * @return U
         */
        U *getValues() const {
            return values;
        }

        /**
         * @brief Returns the value in the matrix at the provided coordinates
         *
         * @param x horizontal coordinate
         * @param y vertical coordinate
         *
         * @return U
         */
        U getValueAt(int x, int y) const {
            if (x >= width)
                throw std::invalid_argument("Provided x coordinate is not in matrix");

            if (y >= height)
                throw std::invalid_argument("Provided y coordinate is not in matrix");

            return values[width * y + x];
        }

//        friend std::ostream &operator<<(std::ostream &os, const Matrix<U> &a);
    };

    /**
     * Add the values of two matrices and return the result
     *
     * @tparam U type of data stored in the matrix
     * @param a Matrix to be added
     * @return Matrix<U>
     */
    template<typename U>
    Matrix<U> Matrix<U>::operator+(Matrix<U> const &a) const {
        if (a.getWidth() == width) {
            if (a.getHeight() == height) {
                U *summedMatrixValues = new U[size];

                U *matrixAValues = a.getValues();

                for (int i = 0; i < size; i++) {
                    summedMatrixValues[i] = values[i] + matrixAValues[i];
                }

                Matrix<U> c(width, height, summedMatrixValues, true);

                return c;
            } else {
                throw std::invalid_argument("Heights of matrices to be added do not match");
            }
        } else {
            throw std::invalid_argument("Widths of matrices to be added do not match");
        }
    }

    /**
     * Add two matrices of integers, using AVX2. The performance benefit is most likely only noticeable for matrices
     * with a low amount of values.
     *
     * @param a Matrix to be added
     * @return Matrix<int>
     */
    template<>
    Matrix<int> Matrix<int>::operator+(Matrix<int> const &a) const {
        if (a.getWidth() == width) {
            if (a.getHeight() == height) {
                __m256i *summedMatrixValues = new __m256i[size / 8];

                int *matrixAValues = a.getValues();

                for (int i = 0; i < size; i += 8) {
                    __m256i first = _mm256_load_si256((__m256i * ) & values[0 + i]);

                    __m256i second = _mm256_load_si256((__m256i * ) & matrixAValues[0 + i]);

                    summedMatrixValues[i / 8] = _mm256_add_epi32(first, second);
                }

                Matrix<int> c(width, height, (int *) summedMatrixValues, true);

                return c;
            } else {
                throw std::invalid_argument("Heights of matrices to be added do not match");
            }
        } else {
            throw std::invalid_argument("Widths of matrices to be added do not match");
        }
    }

//    template<typename U>
//    std::ostream& operator<<(std::ostream &os, const Matrix<U> &a) {
//        os << "[ ";
//
//        for (size_t i = this->size; i--;) {
//            if ((size - 1 - i) % width == 0)
//                os << "\n";
//
//            os << values[size - 1 - i] << " ";
//        }
//
//        os << "]" << std::endl;
//
//        return os;
//    }
}



