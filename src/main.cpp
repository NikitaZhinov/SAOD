#include "BaseArrFuncs.h"
#include "Lists.h"
#include "Search.h"
#include "Sorts.h"

#include <locale>

int main() {
    std::setlocale(LC_ALL, "rus");

    stack<int> test;
    test.fill_inc(10);
    for (int i = 0; i < 10; i++)
        std::cout << test.pop() << " ";

    return 0;
}
