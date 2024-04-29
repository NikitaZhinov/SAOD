#include <iostream>
#include <vector>

#include <BaseArrFuncs.hpp>
#include <Sorts.hpp>
#include <Search.hpp>
#include <Contaners.hpp>

int main() {
    std::cout << "Stack" << std::endl;
    StackInt stack;
    size_t size = 10;

    stack.FillInc(size);
    for (int i = 0; i < size; i++)
        std::cout << stack.pop() << " ";
    std::cout << std::endl;

    stack.FillDec(size);
    for (int i = 0; i < size; i++)
        std::cout << stack.pop() << " ";
    std::cout << std::endl;

    stack.FillRand(size);
    for (int i = 0; i < size; i++)
        std::cout << stack.pop() << " ";
    std::cout << std::endl;

    std::cout << "\nQueue" << std::endl;
    QueueInt queue;

    queue.FillInc(size);
    for (int i = 0; i < size; i++)
        std::cout << queue.pop() << " ";
    std::cout << std::endl;

    queue.FillDec(size);
    for (int i = 0; i < size; i++)
        std::cout << queue.pop() << " ";
    std::cout << std::endl;

    queue.FillRand(size);
    for (int i = 0; i < size; i++)
        std::cout << queue.pop() << " ";
    std::cout << std::endl;

    std::cout << "\nList" << std::endl;
    ListInt list;

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
