#include <cmath>
#include <cstdio>
#include <vector>

import BaseArrFuncs;
import Sorts;

int main() {
    // printf("| Size array |        Theoretical shell         |           M + C shell            |\n");
    // printf("|            | decreasing | middle | increasing | decreasing | random | increasing |\n");
    // printf("|------------|------------|--------|------------|------------|--------|------------|\n");

    printf("| Size array |           M + C shell            |\n");
    printf("|            | decreasing | random | increasing |\n");
    printf("|------------|------------|--------|------------|\n");

    for (size_t len_arr = 100; len_arr <= 500; len_arr += 100) {
        std::vector<int> Amin(len_arr);
        std::vector<int> Amax(len_arr);
        std::vector<int> Arand(len_arr);

        FillDec(Amin, len_arr);
        FillInc(Amax, len_arr);
        FillRand(Arand, len_arr);

        printf("| %10lu ", len_arr);

        // printf("| %10lu ", len_arr * len_arr);
        // printf("| %6lu ", len_arr * log(len_arr) * log(len_arr));
        // printf("| %10lu ", len_arr);

        printf("| %10lu ", ShellSort(Amin, len_arr));
        printf("| %6lu ", ShellSort(Arand, len_arr));
        printf("| %10lu |\n", ShellSort(Amax, len_arr));
    }

    return 0;
}
