#include <iostream>
#include <chrono>

#include "Matrix.h"
#include "Vector.h"
#include "Vector3.h"

int main() {
    int dim = 2048;

    float *firstValues = new float[dim * dim];
    float *secondValues = new float[dim * dim];

    int *firstValuesInt = new int[dim * dim];
    int *secondValuesInt = new int[dim * dim];

    for (int n = 0; n < dim * dim; n++) {
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

    Constellation::Matrix<int> c = f + 1;

    auto end = std::chrono::high_resolution_clock::now();

    auto dur = end - begin;
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(dur).count();

    std::cout << "duration in ns: " << ns << std::endl;

//    std::cout << f.getValueAt(2047, 2047) << std::endl;
//    std::cout << c.getValueAt(2047, 2047) << std::endl;

//    std::cout << "------" << std::endl;
//    std::cout << f.getValueAt(358, 7) << std::endl;
//    std::cout << g.getValueAt(358, 7) << std::endl;
//    std::cout << c.getValueAt(358, 7) << std::endl;
//    std::cout << "------" << std::endl;









//    int intValues1[3] = {1, 2, 3};
//    Constellation::Vector3<int> q(intValues1);
//
//    auto beginint = std::chrono::high_resolution_clock::now();
//
//    for (int n = 0; n < dim * dim; n++) {
//        int iSecret1 = rand() % 10 + 1;
//        int iSecret2 = rand() % 10 + 1;
//        int iSecret3 = rand() % 10 + 1;
//
//        int intValues2[3] = {iSecret1, iSecret2, iSecret3};
//
//        Constellation::Vector3<int> p(intValues2);
//
//        Constellation::Vector3<int> r = q.cross(p);
//    }
//
//    auto endint = std::chrono::high_resolution_clock::now();
//    auto durint = endint - beginint;
//
//    auto msint = std::chrono::duration_cast<std::chrono::milliseconds>(durint).count();
//
//    std::cout << msint << std::endl;

    return 0;
}

