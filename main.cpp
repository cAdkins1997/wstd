
#include <iostream>

#include "string/string.h"
#include "datastructures/arraylist.h"
#include "datastructures/linkedlist.h"

using namespace wstd;

int main() {
    linkedlist<arraylist<int>> list;
    for (int i = 0; i < 4; i++) {
        arraylist<int> array(3);
        for (int j = 0; j < 4; j++) {
            array.push_back(i);
        }
        list.append(array);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << list[i][j];
        }
    }
}