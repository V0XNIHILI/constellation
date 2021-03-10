# Constellation

High performance linear algebra library for C++.

## Description

The library has support for the AVX/SSE instruction set and is, in its current form, made to
resemble real world mathematics. For example, multiplying an identity matrix by a value, leads to a
scalar matrix. Or, when a zero matrix is added to a scalar matrix, the same scalar matrix is
returned.

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
