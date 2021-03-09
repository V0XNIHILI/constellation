# Constellation

High performance linear algebra library for C++.

The library has support for the AVX/SSE instruction set and is, in its current form, made to resemble real world mathematics. For example, multiplying an identity matrix by a value, leads to a scalar matrix. Or, when a zero matrix is added to a scalar matrix, the same scalar matrix is returned.

Future plans include adding Strassen matrix multiplication, CUDA support, trigonometric functions, saving and reading the matrices in binary format and the possiblity to create a simple neural network.

[LICENSE](./LICENSE)
