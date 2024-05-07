#include <iostream>
#include <vector>
#include <locale>

#include "BaseArrFuncs.hpp"
#include "Sorts.hpp"
#include "Search.hpp"
#include "Contaners.hpp"

int main() {
    std::setlocale(0, "rus");

    printf("| Size array | M + C teor |              M + C               |\n");
    printf("|            |            | decreasing | random | increasing |\n");
    printf("|------------|------------|------------|--------|------------|\n");

    for (size_t len_arr = 100; len_arr <= 500; len_arr += 100) {
        List<int> Amin(len_arr, 0);
        List<int> Amax(len_arr, 0);
        List<int> Arand(len_arr, 0);

        Amin.FillDec();
        Amax.FillInc();
        Arand.FillRand();

        printf("| %10lu ", len_arr);

        printf("|%11lu ", len_arr);

        printf("|%11lu ", Amin.MergeSort());
        printf("|%7lu ", Arand.MergeSort());
        printf("|%11lu |\n", Amax.MergeSort());
    }

    return 0;
}
