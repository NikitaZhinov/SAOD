#include <iostream>
#include <vector>
#include <locale>

#include "BaseArrFuncs.hpp"
#include "Sorts.hpp"
#include "Search.hpp"
#include "Contaners.hpp"

int main() {
    std::setlocale(0, "rus");

    std::cout << "Stack" << std::endl;
    Stack<int> stack;
    size_t size = 10;

    stack.FillInc();
    for (int i = 0; i < size; i++)
        std::cout << stack.pop() << " ";
    std::cout << std::endl;

    stack.FillDec();
    for (int i = 0; i < size; i++)
        std::cout << stack.pop() << " ";
    std::cout << std::endl;

    stack.FillRand();
    for (int i = 0; i < size; i++)
        std::cout << stack.pop() << " ";
    std::cout << std::endl;

    std::cout << "\nQueue" << std::endl;
    Queue<int> queue;

    queue.FillInc();
    for (int i = 0; i < size; i++)
        std::cout << queue.pop() << " ";
    std::cout << std::endl;

    queue.FillDec();
    for (int i = 0; i < size; i++)
        std::cout << queue.pop() << " ";
    std::cout << std::endl;

    queue.FillRand();
    for (int i = 0; i < size; i++)
        std::cout << queue.pop() << " ";
    std::cout << std::endl;

    std::cout << "\nList" << std::endl;
    List<int> list;

    // заполнение списка
    for (int i = 0; i < size; i++)
        list.push_back(i);

    list.print();

    std::cout << "Контрольная сумма: " << list.CheckSum() << std::endl;
    std::cout << "Количество серий " << list.RunNumber() << std::endl;

    list.clear();
    std::cout << "Clear list" << std::endl;
    list.print();

    return 0;
}
