
#include <algorithm>
#include <vector>
#include <iostream>

#include "math/random.h"
#include "math/vectors.h"

#include "datastructures/linkedlist.h"

using namespace wstd;

int main() {
    linkedlist<vec3<float>> linkedlist;
    for (int i = 0; i < 10; i++) {
        const auto indexf = static_cast<float>(i);
        linkedlist.append(vec3<float>(indexf, indexf, indexf));
    }

    for (int i = 0; i < 10; i++) {
        std::cout << linkedlist[i] << '\n';
    }
}