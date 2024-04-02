#include <locale>
#include <print>
#include <vector>

import BaseArrFuncs;
import Sorts;
import Search;

int main() {
    std::setlocale(0, "rus");

    std::println("|  N  | M + C теоретик |          M + C factic          |");
    std::println("|     |                | decriment | random | increment |");
    std::println("|-----|----------------|-----------|--------|-----------|");

    for (size_t len = 100; len <= 500; len += 100) {
        std::vector<int> arr(len);

        std::print("|{:4} ", len);
        std::print("|{:15} ", (int)(2 * len * std::log2(len) + len + 2 + len * std::log2(len) + 6.5 * len - 4));

        FillDec(arr, len);
        std::print("|{:10} ", HeapSort(arr));
        FillRand(arr, len);
        std::print("|{:7} ", HeapSort(arr));
        FillInc(arr, len);
        std::println("|{:10} |", HeapSort(arr));
    }

    return 0;
}
