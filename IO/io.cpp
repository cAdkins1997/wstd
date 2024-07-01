
#include "io.h"

namespace wstd {
    template<typename T>
    T getUserInput(const std::string_view& outputMessage) {
        std::cout << outputMessage << ": \n";
        T input;
        std::cin >> input;
        return input;
    }
}