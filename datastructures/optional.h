
#ifndef OPTIONAL_H
#define OPTIONAL_H


template<typename T>
class optional {
    union { char dummy; T value; };
    bool has_value{};

    optional() : dummy(0) {}
    explicit optional(const T& t) : value(t), has_value(true) {}
};

#endif //OPTIONAL_H
