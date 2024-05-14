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
        list<int> Amin;
        list<int> Amax;
        list<int> Arand;

        Amin.fill_dec(len_arr);
        Amax.fill_inc(len_arr);
        Arand.fill_rand(len_arr);

        printf("| %10lu ", len_arr);

        printf("|%11lu ", len_arr);

        printf("|%11lu ", Amin.merge_sort());
        printf("|%7lu ", Arand.merge_sort());
        printf("|%11lu |\n", Amax.merge_sort());
    }

    return 0;
}
