

#ifndef IO_H
#define IO_H

#include <iostream>

namespace wstd {
    template<typename T>
    T getUserInput(const std::string_view& outputMessage);
}

#endif //IO_H
