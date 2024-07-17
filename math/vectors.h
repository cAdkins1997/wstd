
#ifndef VECTORS_H
#define VECTORS_H

#include <cstdlib>
#include <ostream>

namespace wstd {
    template<typename T>
struct vec3 {
        T x, y, z;

        vec3(const T _x, const T _y, const T _z) : x(_x), y(_y), z(_z) {};
        explicit vec3(const T _s) : x(_s), y(_s), z(_s) {};
        vec3(const vec3<T>& other) : x(other.x), y(other.y), z(other.z) {};
        vec3(const vec3<T>&& other)  noexcept : x(std::move(other.x)), y(std::move(other.y)), z(std::move(other.z)) {};

        vec3<T>& operator = (const vec3<T>& other) {
            x = other.x;
            y = other.y;
            z = other.z;
            return *this;
        }

        vec3<T>& operator = (vec3<T>&& other)  noexcept {
            x = std::move(other.x);
            y = std::move(other.y);
            z = std::move(other.z);

            other.x = 0;
            other.y = 0;
            other.z = 0;
            return *this;
        }

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

        std::string to_string() {
            std::string string;
            string.append("x: " + std::to_string(x) + "y: " + std::to_string(y) + "z: " + std::to_string(z));
            return string;
        }
    };

    template<typename T>
    std::ostream& operator << (std::ostream& ostream, const vec3<T> u) {
        return ostream << "X: " << u.x << " Y: " << u.y << " Z: " << u.z;
    }

    template<typename T>
    T dot(const vec3<T>& u, const vec3<T>& v) {
        return (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
    }

    template<typename T>
    vec3<T> cross(const vec3<T> u, const vec3<T> v) {
        return vec3<T> {  };
    }

    template<typename T>
    struct vec2 {
        T x, y;

        vec3<T> operator + (const vec3<T> v) {
            return vec3<T> { x + v.x, y + v.y };
        }

        vec3<T> operator - (const vec3<T> v) {
            return vec3<T> { x - v.x, y - v.y };
        }

        vec3<T> operator * (const size_t scalar) {
            return vec3<T> { x * scalar, y * scalar };
        }

        vec3<T> operator / (const size_t scalar) {
            return vec3<T> { x / scalar, y / scalar };
        }
    };

    template<typename T>
    std::ostream& operator << (std::ostream& ostream, const vec2<T> u) {
        return ostream << "X: " << u.x << " Y: " << u.y;
    }

    template<typename T>
    T dot(const vec2<T>& u, const vec2<T>& v) {
        return (u.x * v.y) + (u.x * v.y);
    }

    template<typename T>
    vec2<T> cross(const vec2<T> u, const vec2<T> v) {
        return vec2<T> {  };
    }
}

#endif //VECTORS_H
