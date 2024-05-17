#include "BaseArrFuncs.hpp"
#include "Lists.hpp"
#include "Search.hpp"
#include "Sorts.hpp"

#include <locale>

int main() {
    std::setlocale(LC_ALL, "rus");

    list<int> test;
    test.fill_inc(10);
    for (int i = 0; i < 10; i++)
        std::cout << test(i) << " ";

    return 0;
}
