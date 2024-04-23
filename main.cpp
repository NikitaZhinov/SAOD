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
    StackInt stack;
    size_t size = 10;

    stack.FillInc(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", stack.pop());
    std::println("");

    stack.FillDec(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", stack.pop());
    std::println("");

    stack.FillRand(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", stack.pop());
    std::println("");

    std::println("\nQueue");
    QueueInt queue;

    queue.FillInc(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", queue.pop());
    std::println("");

    queue.FillDec(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", queue.pop());
    std::println("");

    queue.FillRand(size);
    for (int i = 0; i < size; i++)
        std::print("{} ", queue.pop());
    std::println("");

    std::println("\nList");
    ListInt list;

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
