//
// Created by Douwe den Blanken on 01/02/2021.
//

#ifndef CONSTELLATION_VECTOR3_HPP
#define CONSTELLATION_VECTOR3_HPP

#endif //CONSTELLATION_VECTOR3_HPP

#include <immintrin.h>

namespace Constellation {
    template<typename U>
    /**
     * Vector3 class
     *
     * @tparam U type of data that the matrix should hold
     */
    class Vector3 : public Vector<U> {
    public:
        /**
         * @brief Construct a new Vector3 object using gives x, y, z values
         *
         * @todo Probably make this into a class where the values is a 3-element long array on the stack
         *
         * @param v Values that should be stored in the Vector3
         */
        Vector3(U *v) : Vector<U>(3, v) {}

        /**
         * Calculate the cross product of two 3 dimensional vectors
         *
         * @param a Vector to calculate the cross product with
         * @return Vector3
         */
        Vector3<U> cross(Vector3<U> const &a) const;
    };

    template<typename U>
    Vector3<U> Vector3<U>::cross(Vector3<U> const &a) const {
        U crossProductValues[3] {0};

        U *vector3AValues = a.getValues();

        crossProductValues[0] = this->values[1] * vector3AValues[2] - this->values[2] * vector3AValues[1];
        crossProductValues[1] = this->values[2] * vector3AValues[0] - this->values[0] * vector3AValues[2];
        crossProductValues[2] = this->values[0] * vector3AValues[1] - this->values[1] * vector3AValues[0];

        Vector3<U> c(crossProductValues);

        return c;
    }

    template <>
    Vector3<int> Vector3<int>::cross(Vector3<int> const &a) const {
        int *vector3AValues = a.getValues();

        __m128i first = _mm_set_epi32(this->values[1] * vector3AValues[2], this->values[2] * vector3AValues[0], this->values[0] * vector3AValues[1], 0);
        __m128i second = _mm_set_epi32(this->values[2] * vector3AValues[1], this->values[0] * vector3AValues[2], this->values[1] * vector3AValues[0], 0);
        __m128i result = _mm_sub_epi32(first, second);

        int* crossProductValues = (int*) &result;

        Vector3<int> c(crossProductValues);

        return c;
    }
}

