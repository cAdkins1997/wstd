
#include <algorithm>
#include <vector>
#include <iostream>

#include "datastructures/arraylist.h"
#include "math/random.h"
#include "math/vectors.h"

#include "datastructures/linkedlist.h"
#include "math/functions.h"

#include "string/string.h"

using namespace wstd;

int main() {
    arraylist<linkedlist<vec3<float>>> parent(10);
    for (int i = 0; i < 10; i++) {
        linkedlist<vec3<float>> child;
        for (int j = 0; j < 10; j++) {
            vec3<float> u(
                randomf(10.0f, 0.0f),
                randomf(10.0f, 0.0f),
                randomf(10.0f, 0.0f)
            );

            child.append(u);
        }

        parent.push_back(child);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; i < 10; i++) {
            const vec3<float> u = parent[i][j];
            std::cout << u << '\n';
        }
    }
}