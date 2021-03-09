//
// Created by Douwe den Blanken on 09/03/2021.
//

#ifndef CONSTELLATION_TRIGONOMETRY_HPP
#define CONSTELLATION_TRIGONOMETRY_HPP

#include "../Matrix.hpp"

namespace Constellation {
    namespace Trigonometry {
        template<typename U>
        Matrix<U> sin(Matrix<U> const &a);

        template<typename U>
        Matrix<U> cos(Matrix<U> const &a);
    }
}

#endif //CONSTELLATION_TRIGONOMETRY_HPP
