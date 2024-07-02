
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
    /*arraylist<linkedlist<int>> array(4);
    for (int i = 0; i < 10; i++) {
        linkedlist<int> linkedlist;
        for (int j = 0; j < 10; j++) {
            linkedlist.append(i + j);
        }
        array.push_back(linkedlist);e
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << array[i][j] << '\n';
        }
    }*/

    linkedlist<arraylist<int>> linkedlist;
    for (int i = 0; i < 3; i++) {
        arraylist<int> array(3);
        for (int j = 0; j < 3; j++) {
            array.push_back(i);
        }
        linkedlist.append(array);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << linkedlist[i][j] <<'\n';
        }
    }
}