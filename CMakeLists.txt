# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( constellation )

# flags
set(CMAKE_CXX_FLAGS "-std=c++17 -Ofast -march=native -flto -fomit-frame-pointer -mavx2 -fno-tree-vectorize")

# files

# include( ./src/simd/addition/int32_matrix_addition.cpp )
file(GLOB src
     "**/*.h"
     "**/*.cpp"
)

# include
include_directories( ./include ./src )

# target
add_executable( binary ./src/main.cpp )

# external libs
