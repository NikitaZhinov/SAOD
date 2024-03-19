﻿#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <locale>
#include <print>
#include <vector>

import BaseArrFuncs;
import Sorts;
import Search;

int main() {
    std::setlocale(LC_ALL, "rus");

    int x;

    std::print("Введите значение: ");
    std::cin >> x;

    // printf("| Size array |        Theoretical shell         |           M + C shell            |\n");
    // printf("|            | decreasing | middle | increasing | decreasing | random | increasing |\n");
    // printf("|------------|------------|--------|------------|------------|--------|------------|\n");

    std::println("| Size array | Binary Search 1 | Binary Search 2 |");
    std::println("|------------|-----------------|-----------------|");

    for (size_t len_arr = 100; len_arr <= 1000; len_arr += 100) {
        std::vector<int> arr(len_arr);

        FillInc(arr, len_arr);

        BinarySearch1(arr, len_arr, x);
        BinarySearch2(arr, len_arr, x);

        std::print("|{:11} ", len_arr);
        std::print("|{:16} ", COMPARE_BINARY_SEARCH_1);
        std::print("|{:16} ", COMPARE_BINARY_SEARCH_2);
        std::println("|");
    }

    return 0;
}
