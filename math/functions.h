
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <limits>

#include "vectors.h"

namespace wstd {
    template<typename T>
    requires std::is_floating_point_v<T> || std::is_integral_v<T>
    T x_intercept(vec2<T> p1, vec2<T> p2)  {
        T deltaX = p1.x - p2.x;
        T deltaY = p1.y - p2.y;

        if (deltaX == 0 || deltaY == 0) {
            return std::numeric_limits<T>::infinity();
        }

        double slope = deltaX / (deltaY * 1.0);

        const double c  = p1.x - slope * p1.y;

        return (0 - c) / (slope * 1.0);
    }

    template<typename T>
    requires std::is_arithmetic_v<T>
    T y_intercept(const vec2<T> p1, const vec2<T> p2) {
        T deltaX = p1.x - p2.x;
        T deltaY = p1.y - p2.y;

        if (deltaX == 0 || deltaY == 0) {
            return std::numeric_limits<T>::infinity();
        }

        double slope = deltaX / (deltaY * 1.0);

        const double c  = p1.y - slope * p1.x;

        return slope * p1.x + c;
    }

    template<typename T>
    requires std::is_floating_point_v<T> || std::is_integral_v<T>
    T power_rule(T n, T p) {
        return pow(n, p + 1) / p + 1;
    }
}

#endif //FUNCTIONS_H
