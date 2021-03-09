//
// Created by Douwe den Blanken on 01/02/2021.
//

#ifndef CONSTELLATION_MATRIX_HPP
#define CONSTELLATION_MATRIX_HPP

#include <stdexcept>
#include <string>
#include <fstream>
#include <cmath>

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
         * @param passByReference Whether or not to copy the values into the values array of the matrix. True = copying
         * the pointer, false = copying the values
         */
        Matrix(int w, int h, U *v, bool passByReference) {
            if (w > 0) {
                if (h > 0) {
                    width = w;
                    height = h;

                    size = h * w;

                    if (passByReference == true) {
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

        /**
         * @brief Throws an error when either the widths or the heights of two matrices do not match
         *
         * @param a Matrix to be checked against
         * @param verb Word that will be added in the error message. Can be 'added' or 'divided' etc.
         */
        void checkDimensionCompatibility(Matrix<U> const &a, std::string verb) const {
            if (a.getWidth() != width)
                throw std::invalid_argument("Widths of matrices to be " + verb + " do not match");
            else if (a.getHeight() != height)
                throw std::invalid_argument("Heights of matrices to be " + verb + " not match");
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
         * @brief Construct a new Matrix object from values in the file with the supplied file name
         *
         * @param fileName Name of the file in which the values of the matrix are stored
         */
        Matrix(std::string fileName) {}

        /**
         * @brief Check if two matrices are equal to each other in terms of dimensions and values.
         * 
         * @param a Matrix to check against
         * @return bool
         */
        bool operator==(Matrix<U> const &a) const {
            if (a.getWidth() == width) {
                if (a.getHeight() == height) {
                    U *matrixAValues = a.getValues();

                    bool equals = true;

                    for (int i = 0; i < size; i++) {
                        if (matrixAValues[i] != values[i]) {
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
         * @brief Divide the matrix by a another matrix
         *
         * @param a Matrix to divide the matrix by
         * @return Matrix
         */
        Matrix<U> operator/(Matrix<U> const &a) const;

        /**
         * @brief Calculate a certain power of the matrix
         *
         * @param a Power that should be calculated
         * @return Matrix
         */
        Matrix<U> operator^(int const &a) const;

        /**
         * @brief Multiply two matrices entrywise/elementwise (calculate the Hadamard product)
         *
         * @param a Matrix to perform elementwise multiplication with
         * @return Matrix
         */
        Matrix<U> entryWise(Matrix<U> const &a) const;

        /**
         * @brief Calculate the dot product of two matrices
         *
         * @param a Matrix using which the dot product should be calculated
         * @return Matrix
         */
        U dot(Matrix<U> const &a) const {
            checkDimensionCompatibility(a, "dotted");

            // Zero initialization of the dot product (see: https://en.cppreference.com/w/cpp/language/zero_initialization)
            U dotProduct = U();

            U *matrixAValues = a.getValues();

            for (int i = 0; i < size; i++) {
                dotProduct += values[i] * matrixAValues[i];
            }

            return dotProduct;
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

        Matrix<U> replace(char where, U value, U with) const {
            U *replacedMatrixValues = new U[size];

            if (where == '>') {
                for (int i = 0; i < size; i++) {
                    replacedMatrixValues[i] = values[i] > value ? with : values[i];
                }
            } else if (where == '=') {
                for (int i = 0; i < size; i++) {
                    replacedMatrixValues[i] = values[i] == value ? with : values[i];
                }
            } else if (where == '<') {
                for (int i = 0; i < size; i++) {
                    replacedMatrixValues[i] = values[i] < value ? with : values[i];
                }
            } else {
                throw std::invalid_argument("The supplied 'where' is not >, = or <");
            }

            Matrix c(height, width, replacedMatrixValues, true);

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
         * Returns the values of the matrix in an 1D array
         *
         * @return U
         */
        virtual U *getValues() const {
            return values;
        }

        /**
         * @brief Returns the value in the matrix at the provided coordinates
         *
         * @param x horizontal coordinate (0 indexed)
         * @param y vertical coordinate (0 indexed)
         *
         * @return U
         */
        U operator()(int &x, int &y) const {
            if (x >= width)
                throw std::invalid_argument("Provided x coordinate is not in matrix");

            if (y >= height)
                throw std::invalid_argument("Provided y coordinate is not in matrix");

            return values[width * y + x];
        }

        /**
         * @brief Save the values in the matrix into a CSV file
         *
         * @todo Add binary export for smaller outfiles
         * @todo Add error handling
         *
         * @param fileName Name of the file in which the values should be saved
         */
        void save(std::string fileName) {
            std::ofstream file(fileName);

            if (file.is_open()) {
                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < width; j++) {
                        file << values[j + i * width] << ';';
                    }

                    // Make sure that there is no empty line at the end of the file
                    if (i != height - 1)
                        file << '\n';
                }
            }

            file.close();
        }
    };

    template<typename U>
    std::ostream &operator<<(std::ostream &os, const Matrix<U> &a) {
        os << "[ ";

        for (size_t i = a.getWidth() * a.getHeight(); i--;) {
            if ((a.getWidth() * a.getHeight() - 1 - i) % a.getWidth() == 0)
                os << "\n";

            os << a.getValues()[a.getWidth() * a.getHeight() - 1 - i] << " ";
        }

        os << "]" << std::endl;

        return os;
    }

} // namespace Constellation

#include "Arithmetic/Addition/ValueAddition.hpp"
#include "Arithmetic/Addition/MatrixAddition.hpp"

#include "Arithmetic/Division/ValueDivision.hpp"
#include "Arithmetic/Division/MatrixDivision.hpp"

#include "Arithmetic/Multiplication/ValueMultiplication.hpp"
#include "Arithmetic/Multiplication/MatrixMultiplication.hpp"

#include "Arithmetic/Subtraction/ValueSubtraction.hpp"
#include "Arithmetic/Subtraction/MatrixSubtraction.hpp"

#include "Arithmetic/EntryWiseMultiplication.hpp"

#endif //CONSTELLATION_MATRIX_HPP