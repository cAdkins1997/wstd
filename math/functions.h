
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <limits>

#include "vectors.h"

namespace wstd {
    template<typename T>
    constexpr T x_intercept(const vec2<T> p1, const vec2<T> p2) {

        T deltaX = p1[0] - p2[0];
        T deltaY = p1[1] - p2[1];

        if (deltaX == 0 || deltaY == 0) {
            return std::numeric_limits<T>::infinity();
        }

        double slope = deltaX / (deltaY * 1.0);

        const double c  = p1[1] - slope * p1[0];

        return (0 - c) / (slope * 1.0);
    }

    template<typename T>
    constexpr T y_intercept(const vec2<T> p1, const vec2<T> p2) {
        T deltaX = p1[0] - p2[0];
        T deltaY = p1[1] - p2[1];

        if (deltaX == 0 || deltaY == 0) {
            return std::numeric_limits<T>::infinity();
        }

        double slope = deltaX / (deltaY * 1.0);

        const double c  = p1[1] - slope * p1[0];

        return slope * p1[0] + c;
    }
}

#endif //FUNCTIONS_H
