#include <iostream>
#include <chrono>

#include "Constellation/Matrix.hpp"

int main()
{
    int dim = 4096;

    int *firstValuesInt = new int[dim * dim];
    int *secondValuesInt = new int[dim * dim];

    for (int n = 0; n < dim * dim; n++)
    {
        firstValuesInt[n] = rand() % 10 + 3;
        secondValuesInt[n] = rand() % 10 + 3;
    }

    Constellation::Matrix<int> f(dim, dim, firstValuesInt);
    Constellation::Matrix<int> g(dim, dim, secondValuesInt);

    auto begin = std::chrono::high_resolution_clock::now();

    Constellation::Matrix<int> c = f + 3;

    auto end = std::chrono::high_resolution_clock::now();

    auto dur = end - begin;
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(dur).count();

    std::cout << "Duration in ns: " << ns << std::endl;

    return 0;
}
