
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
    linkedlist<linkedlist<int>> parent;
    for (int i = 0; i < 4; i++) {
        linkedlist<int> child;
        for (int j = 0; j < 4; j++) {
            child.append(i + j);
        }
        parent.append(child);
    }

    for (int i = 0; i < 4; i++) {
        std::cout << parent[i];
    }
}