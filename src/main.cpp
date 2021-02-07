#include <iostream>
#include <chrono>

#include "Constellation/Matrix.hpp"
#include "Constellation/Vector.hpp"
#include "Constellation/Vector3.hpp"

int main()
{
    int dim = 20 * 1000;

    float *firstValues = new float[dim * dim];
    float *secondValues = new float[dim * dim];

    int *firstValuesInt = new int[dim * dim];
    int *secondValuesInt = new int[dim * dim];

    for (int n = 0; n < dim * dim; n++)
    {
        firstValues[n] = 0.5;
        secondValues[n] = 0.7;

        firstValuesInt[n] = rand() % 10 + 3;
        secondValuesInt[n] = rand() % 10 + 3;
    }

    Constellation::Matrix<float> a(dim, dim, firstValues);
    Constellation::Matrix<float> b(dim, dim, secondValues);

    Constellation::Matrix<int> f(dim, dim, firstValuesInt);
    Constellation::Matrix<int> g(dim, dim, secondValuesInt);

    auto begin = std::chrono::high_resolution_clock::now();

    Constellation::Matrix<int> c = f + 3;

    auto end = std::chrono::high_resolution_clock::now();

    auto dur = end - begin;
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(dur).count();

    std::cout << "duration in ns: " << ns << std::endl;

    return 0;
}
