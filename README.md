# Constellation

Linear algebra library for C++.

## Description

The library has support for the AVX/SSE instruction set and is, in its current form, made to
resemble real world mathematics. For example, multiplying an identity matrix (class = `Identity`) by a value, leads to a
scalar matrix (class = `Scalar`). Or, when a zero matrix (class = `Zero`) is added to a scalar matrix, the same scalar matrix is
returned. Furthermore, for special matrix types, such as a zero or identity matrix, the amount of space needed in memory to use them is independent of their size.

Constellation makes extensive of C++ templates allowing you to make binary as well as floating point matrices with the same ease.

## Coverage/tests

Tests are written using [Google's GoogleTest](https://github.com/google/googletest); the tests cover some of the basic properties and operations for the various types of matrices. 

## What's next

Future plans include adding Strassen matrix multiplication, CUDA support, trigonometric functions, fixed size arrays, saving and reading the matrices in binary format and the possiblity to create a simple neural
network. Also, compile time checks of matrix compatibility in equations and expression templates are in the pipeline.

Finally, integrating [Google's Highway](https://github.com/google/highway)
with this library and compile time calculations are being looked into.
## Sample

```cpp
#include <iostream>

#include <Constellation/Matrix.hpp>
#include <Constellation/Trigonometry/Trigonometry.hpp>

using namespace Constellation;
using namespace Constellation::Trigonometry;

int main() {
    float values[4] = {16, 2, 77, 40};

    Matrix<float> a(2, 2, values);

    auto b = cos(sin(a) + 3).replace('>', 0, -10);

    std::cout << b << std::endl

    return 0;
}
```

[LICENSE](./LICENSE)
