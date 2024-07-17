
#include <algorithm>
#include <vector>
#include <iostream>

#include "datastructures/arraylist.h"
#include "math/random.h"
#include "math/vectors.h"
#include "math/matrix.h"

#include "datastructures/linkedlist.h"
#include "math/functions.h"

#include "string/string.h"

using namespace wstd;
using namespace std::chrono;

int main() {
    arraylist<linkedlist<int>> array(2);
    for (int i = 0; i < 4; i++) {
        linkedlist<int> list;
        for (int j = 0; j < 4; j++) {
            list.append(i);
        }
        array.push_back(list);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int number = array[i][j];
            std::cout << number << '\n';
        }
    }
}