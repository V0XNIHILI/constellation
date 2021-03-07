//
// Created by Douwe den Blanken on 08/02/2021.
//

#include <vector>
#include <thread>

namespace Constellation {
    template<typename U>
    Matrix <U> Matrix<U>::operator+(U const &a) const {
        U *summedMatrixValues = new U[size];

//        const size_t numberOfThreads = std::thread::hardware_concurrency();
//
//        std::vector<std::thread> threads(numberOfThreads);
//        std::mutex critical;
//
//        for (int t = 0; t < numberOfThreads; t++) {
//            threads[t] = std::thread(std::bind(
//                    [&](const int bi, const int ei, const int t) {
//                        // loop over all items
//                        for (int i = bi; i < ei; i++) {
//                            // inner loop
//                            {
//                                summedMatrixValues[i] = values[i] + a;
//                                // (optional) make output critical
////                                std::lock_guard<std::mutex> lock(critical);
//                            }
//                        }
//                    }, t * size / numberOfThreads,
//                    (t + 1) == numberOfThreads ? size : (t + 1) * size / numberOfThreads, t));
//        }
//        std::for_each(threads.begin(), threads.end(), [](std::thread &x) { x.join(); });

        for (int i = 0; i < size; i++)
        {
            summedMatrixValues[i] = values[i] + a;
        }

        Matrix<U> c(width, height, summedMatrixValues, true);

        return c;
    }
}; // namespace Constellation