
#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <chrono>

namespace wstd {
    using namespace std::chrono;

    template<typename T>
    requires std::is_floating_point_v<T>
    T randomf(const T floor, const T ceiling) {
        const auto currentTime = system_clock::now().time_since_epoch().count();
        std::mt19937_64 generator(currentTime);
        std::uniform_real_distribution<T> distribution(floor, ceiling);
        return distribution(generator);
    }

    template<typename T>
    requires std::is_integral_v<T>
    T random(const T floor, const T ceiling) {
        const auto currentTime = system_clock::now().time_since_epoch().count();
        std::mt19937_64 generator(currentTime);
        std::uniform_int_distribution<T> distribution(floor, ceiling);
        return distribution(generator);
    }
}

#endif //RANDOM_H
