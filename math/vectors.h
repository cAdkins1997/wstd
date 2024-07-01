
#ifndef VECTORS_H
#define VECTORS_H

#include <cstdlib>
#include <ostream>

namespace wstd {
    template<typename T>
struct vec3 {
        T x, y, z;

        vec3<T> operator + (const vec3<T> v) {
            return vec3<T> { x + v.x, y + v.y, z+ v.z };
        }

        vec3<T> operator - (const vec3<T> v) {
            return vec3<T> { x - v.x, y - v.y, z - v.z };
        }

        vec3<T> operator * (const size_t scalar) {
            return vec3<T> { x * scalar, y * scalar, z * scalar };
        }

        vec3<T> operator / (const size_t scalar) {
            return vec3<T> { x / scalar, y / scalar, z / scalar };
        }
    };

    template<typename T>
    std::ostream& operator << (std::ostream& ostream, const vec3<T> u) {
        return ostream << "X: " << u.x << " Y: " << u.y << " Z: " << u.z;
    }

    template<typename T>
    T dot(const vec3<T>& u, const vec3<T>& v) {
        return (u[0] * v[0]) + (u[1] * v[1]) + (u[2] * v[2]);
    }

    template<typename T>
    vec3<T> cross(const vec3<T> u, const vec3<T> v) {
        return vec3<T> {  };
    }

    template<typename T>
    struct vec2 {
        T components[2];

        T operator [] (const char index) const { return components[index]; }

        vec3<T> operator + (const vec3<T> u) {
            return vec3<T> { u[0] + this[0], u[1] + this[1] };
        }

        vec3<T> operator - (const vec3<T> u) {
            return vec3<T> { this[0] - u[0], this[1] - u[1] };
        }

        vec3<T> operator * (const size_t scalar) {
            return vec3<T> { this[0] * scalar, this[1] * scalar };
        }

        vec3<T> operator / (const size_t scalar) {
            return vec3<T> { this[0] / scalar, this[1] / scalar };
        }
    };

    template<typename T>
    T dot(const vec2<T>& u, const vec2<T>& v) {
        return (u[0] * v[0]) + (u[1] * v[1]);
    }

    template<typename T>
    vec2<T> cross(const vec2<T> u, const vec2<T> v) {
        return vec2<T> {  };
    }
}

#endif //VECTORS_H
