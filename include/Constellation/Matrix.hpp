//
// Created by Douwe den Blanken on 01/02/2021.
//

#ifndef MATRIX_H
#define MATRIX_H

#endif //MATRIX_H

#include <stdexcept>
#include <string>

namespace Constellation
{
    template <typename U>
    /**
     * Matrix class
     *
     * @tparam U type of data that the matrix should hold
     */
    class Matrix
    {
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
         * @param passByReference Whether or not to copy the values into the values array of the matrix. True = copying
         * the pointer, false = copying the values
         */
        Matrix(int w, int h, U *v, bool passByReference)
        {
            if (w > 0)
            {
                if (h > 0)
                {
                    width = w;
                    height = h;

                    size = h * w;

                    if (passByReference == true)
                    {
                        values = v;
                    }
                    else
                    {
                        values = new U[size];

                        // Copy the numerical values from the array into the matrix
                        // Copying speed on MacBook Pro 2014: n^2 * 2.015625E-6 ms
                        for (int i = 0; i < size; i++)
                        {
                            values[i] = v[i];
                        }
                    }
                }
                else
                {
                    throw std::invalid_argument("Matrix height should be larger than 0");
                }
            }
            else
            {
                throw std::invalid_argument("Matrix width should be larger than 0");
            }
        }

    private:
        /**
         * @brief Throws an error when either the widths or the heights of two matrices do not match
         *
         * @param a Matrix to be checked against
         * @param verb Word that will be added in the error message. Can be 'added' or 'divided' etc.
         */
        void checkDimensionCompatibility(Matrix<U> const &a, std::string verb) const
        {
            if (a.getWidth() != width)
                throw std::invalid_argument("Widths of matrices to be " + verb + " do not match");
            else if (a.getHeight() != height)
                throw std::invalid_argument("Heights of matrices to be " + verb + " not match");
        }

    public:
        ~Matrix()
        {
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
         * @brief Check if two matrices are equal to each other in terms of dimensions and values.
         * 
         * @param a Matrix to check against
         * @return bool
         */
        bool operator==(Matrix<U> const &a) const
        {
            if (a.getWidth() == width)
            {
                if (a.getHeight() == height)
                {
                    U *matrixAValues = a.getValues();

                    bool equals = true;

                    for (int i = 0; i < size; i++)
                    {
                        if (matrixAValues[i] != values[i])
                        {
                            equals = false;
                            break;
                        }
                    }

                    return equals;
                }
            }

            return false;
        }

        /**
         * @brief Add two matrices
         *
         * @param a Matrix to be added
         * @return Matrix<U>
         */
        Matrix<U> operator+(Matrix<U> const &a) const;

        /**
         * @brief Add a certain value from the matrix
         *
         * @param a Value to add to all matrix entries
         * @return Matrix
         */
        Matrix<U> operator+(U const &a) const;

        /**
         * @brief Subtract one matrix from another
         *
         * @param a Matrix to be subtracted
         * @return Matrix
         */
        Matrix<U> operator-(Matrix<U> const &a) const;

        /**
         * @brief Subtract a certain value from the matrix
         *
         * @param a Value to subtract from all matrix entries
         * @return Matrix
         */
        Matrix<U> operator-(U const &a) const;

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
        Matrix<U> operator*(Matrix<U> const &a) const;

        /**
         * @brief Multiply the matrix with a certain value
         *
         * @param a Value to multiply matrix with
         * @return Matrix
         */
        Matrix<U> operator*(U const &a) const;

        /**
         * @brief Divide the matrix by a certain value
         *
         * @param a Value to divide all matrix entries by
         * @return Matrix
         */
        Matrix<U> operator/(U const &a) const;

        /**
         * @brief Calculate the dot product of two matrices
         *
         * @param a Matrix using which the dot product should be calculated
         * @return Matrix
         */
        U dot(Matrix<U> const &a) const
        {
            if (a.getWidth() == width)
            {
                if (a.getHeight() == height)
                {
                    U dotProduct = U();

                    U *matrixAValues = a.getValues();

                    for (int i = 0; i < size; i++)
                    {
                        dotProduct += values[i] * matrixAValues[i];
                    }

                    return dotProduct;
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

        /**
         * @brief Return the transpose of the matrix
         *
         * @return Matrix
         */
        Matrix<U> T() const
        {
            U *transposedMatrixValues = new U[size];

            for (int i = 0; i < size; i++)
            {
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
        int getWidth() const
        {
            return width;
        }

        /**
         * Returns the height of the matrix
         *
         * @return int
         */
        int getHeight() const
        {
            return height;
        }

        /**
         * Returns the values of the matrix in a 1D array
         *
         * @return U
         */
        U *getValues() const
        {
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
        U getValueAt(int x, int y) const
        {
            if (x >= width)
                throw std::invalid_argument("Provided x coordinate is not in matrix");

            if (y >= height)
                throw std::invalid_argument("Provided y coordinate is not in matrix");

            return values[width * y + x];
        }

        // friend std::ostream &operator<<(std::ostream &os, const Matrix<U> &a);
    };

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
} // namespace Constellation

#include "Arithmetic/Addition/GenericAddition.hpp"
#include "Arithmetic/Addition/GenericMatrixAddition.hpp"

#include "Arithmetic/Subtraction/GenericSubtraction.hpp"
#include "Arithmetic/Subtraction/GenericMatrixSubtraction.hpp"

#include "Arithmetic/Multiplication/GenericMultiplication.hpp"
#include "Arithmetic/Multiplication/GenericMatrixMultiplication.hpp"

#include "Arithmetic/Division/GenericDivision.hpp"

#include "Arithmetic/Addition/AVX-SSE/Int32Addition.hpp"
// #include "Arithmetic/Subtraction/AVX-SSE/Int32Subtraction.hpp"
// #include "Arithmetic/Multiplication/AVX-SSE/Int32Multiplication.hpp"

// #include "Arithmetic/Addition/AVX-SSE/Float32Addition.hpp"
// #include "Arithmetic/Division/AVX-SSE/Float32Division.hpp"
// #include "Arithmetic/Subtraction/AVX-SSE/Float32Subtraction.hpp"
// #include "Arithmetic/Multiplication/AVX-SSE/Float32Multiplication.hpp"
