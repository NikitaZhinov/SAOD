﻿#include "Lists.hpp"
#include "Sorts.hpp"
#include <cmath>
#include <iostream>

int main() {
    std::setlocale(LC_ALL, "rus");

    // DIGITAL SORT
    std::cout << " N  | Teor | Dec  | Rand | Inc" << std::endl;

    for (int len = 100; len <= 500; len += 100) {
        list<int> up;
        list<int> down;
        list<int> rand;

        up.fill_inc(len);
        down.fill_dec(len);
        rand.fill_rand(len, 0, 100);

        std::cout << len << " | " << sizeof(int) * (len + 256) << " | " << digitalSort(down)
                  << " | " << digitalSort(rand) << " | " << digitalSort(up) << std::endl;
    }

    return 0;
}
