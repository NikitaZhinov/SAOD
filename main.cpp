#include <locale>
#include <print>
#include <vector>

import BaseArrFuncs;
import Sorts;
import Search;
import Contaners;

int main() {
    std::setlocale(LC_ALL, "rus");

    std::println("Stack");
    stack<int> stack;
    size_t size = 10;

    stack.fill_inc(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", stack.pop());
    std::println("");

    stack.fill_dec(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", stack.pop());
    std::println("");

    stack.fill_rand(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", stack.pop());
    std::println("");

    std::println("\nQueue");
    queue<int> queue;

    queue.fill_inc(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", queue.pop());
    std::println("");

    queue.fill_dec(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", queue.pop());
    std::println("");

    queue.fill_rand(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", queue.pop());
    std::println("");

    std::println("\nList");
    list<int> list;

    // заполнение списка
    for (int i = 0; i < size; i++)
        list.push_back(i);

    list.print();

    std::println("Контрольная сумма: {}", list.CheckSum());
    std::println("Количество серий {}", list.RunNumber());

    list.clear();
    std::println("Clear list");
    list.print();

    return 0;
}
