#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <locale>

import BaseArrFuncs;
import Sorts;
import Search;

int main() {
    std::setlocale(LC_ALL, "rus");

    int x;

    std::cout << "¬ведите значение: ";
    std::cin >> x;
    std::cout << std::endl;

    // printf("| Size array |        Theoretical shell         |           M + C shell            |\n");
    // printf("|            | decreasing | middle | increasing | decreasing | random | increasing |\n");
    // printf("|------------|------------|--------|------------|------------|--------|------------|\n");

    std::cout << "| Size array | Binary Search 1 | Binary Search 2 |" << std::endl;
    std::cout << "|------------|-----------------|-----------------|" << std::endl;

    for (size_t len_arr = 100; len_arr <= 1000; len_arr += 100) {
        std::vector<int> arr(len_arr);
        
        FillInc(arr, len_arr);

        BinarySearch1(arr, len_arr, x);
        BinarySearch2(arr, len_arr, x);

        std::cout << "|" << std::setw(11) << len_arr << ' ';
        std::cout << "|" << std::setw(16) << COMPARE_BINARY_SEARCH_1 << ' ';
        std::cout << "|" << std::setw(16) << COMPARE_BINARY_SEARCH_2 << ' ';
        std::cout << "|" << std::endl;
    }

    return 0;
}
