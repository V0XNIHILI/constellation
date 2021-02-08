# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( constellation )

# cpp version

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# flags
set(CMAKE_CXX_FLAGS "-Ofast -march=native -flto -fomit-frame-pointer -mavx2 -fno-tree-vectorize")

# files

# include
include_directories( ./include ./src )

# target
add_executable( binary ./src/main.cpp )

# tests
#enable_testing()
add_executable(all_tests tests/main.cpp)
set(INSTALL_GTEST OFF)
add_subdirectory(libs/googletest)
target_link_libraries(all_tests gtest gtest_main)
#add_test( all_tests all_tests )