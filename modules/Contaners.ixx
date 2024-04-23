#include <print>
#include <random>

export module Contaners;

class ContanerInt {
protected:
    int *__data;
    size_t __size;

public:
    ContanerInt() {
        __size = 0;
        __data = new int[__size];
    }

    ~ContanerInt() {
        delete[] __data;
    }

    void FillInc(size_t value) {
        for (size_t i = 0; i < value; i++)
            push(i);
    }

    void FillDec(size_t value) {
        for (size_t i = 0; i < value; i++)
            push(value - i);
    }

    void FillRand(size_t value) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 100);
        for (size_t i = 0; i < value; i++)
            push(dist(gen));
    }

    void push(int value) {
        if (__size == 0) {
            __size++;
            __data = new int[__size];
            __data[0] = value;
        } else {
            int *data_copy = new int[__size];
            for (int i = 0; i < __size; i++)
                data_copy[i] = __data[i];
            delete[] __data;
            __data = new int[++__size];
            for (int i = 0; i < __size - 1; i++)
                __data[i] = data_copy[i];
            delete[] data_copy;
            __data[__size - 1] = value;
        }
    }

    virtual int pop() = 0;
    virtual int check() = 0;
};

export class StackInt : public ContanerInt {
public:
    int pop() override {
        int *data_copy = new int[__size];
        for (int i = 0; i < __size; i++)
            data_copy[i] = __data[i];
        delete[] __data;
        __data = new int[--__size];
        for (int i = 0; i < __size; i++)
            __data[i] = data_copy[i];
        int res = data_copy[__size];
        delete[] data_copy;
        return res;
    }

    int check() override {
        return __data[__size - 1];
    }
};

export class QueueInt : public ContanerInt {
public:
    int pop() override {
        int *data_copy = new int[__size];
        for (int i = 0; i < __size; i++)
            data_copy[i] = __data[i];
        delete[] __data;
        __data = new int[--__size];
        for (int i = 1; i < __size + 1; i++)
            __data[i - 1] = data_copy[i];
        int res = data_copy[0];
        delete[] data_copy;
        return res;
    }

    int check() override {
        return __data[0];
    }
};

export class NodeListInt {
public:
    NodeListInt *prev, *next;
    int __value;

    NodeListInt(int value) :
        prev(nullptr), next(nullptr), __value(value) {}
};

export class ListInt {
private:
    NodeListInt *__first;
    NodeListInt *__last;
    size_t __size;

public:
    ListInt() :
        __first(nullptr), __last(nullptr), __size(0) {}

    ~ListInt() {
        clear();
    }

    void clear() {
        while (__size > 0)
            pop_back();
    }

    void pop_back() {
        if (__size == 0)
            return;
        if (__size == 1) {
            delete __first;
            __first = __last = nullptr;
        } else {
            NodeListInt *p = __last;
            __last = __last->prev;
            __last->next = nullptr;
            delete p;
        }
        __size--;
    }

    void push_back(int value) {
        NodeListInt *p = new NodeListInt(value);

        if (__first == nullptr) {
            __first = p;
            __last = p;
        } else {
            p->prev = __last;
            __last->next = p;
            __last = p;
        }
        __size++;
    }

    void print() {
        if (__size != 0) {
            NodeListInt *p = __first;
            for (int i = 0; i < __size; i++) {
                std::print("{} ", p->__value);
                p = p->next;
            }
            std::println("");
        } else
            std::println("List is empty!");
    }

    int operator[](size_t index) {
        int res = INT32_MAX;
        if (index < __size and __first != nullptr) {
            NodeListInt *p = __first;
            for (size_t i = 0; i < index; i++)
                p = p->next;
            res = p->__value;
        }
        return res;
    }

    NodeListInt *get(size_t index) {
        if (__first == nullptr)
            return nullptr;
        NodeListInt *p = __first;
        for (size_t i = 0; i < index; i++) {
            p = p->next;
            if (!p)
                return nullptr;
        }
        return p;
    }

    int CheckSum() {
        int sum = 0;
        for (size_t i = 0; i < __size; i++)
            sum += (*this)[i];
        return sum;
    }

    size_t RunNumber() {
        size_t res = 1;
        for (size_t i = 1; i < __size; i++)
            if ((*this)[i - 1] > (*this)[i])
                res++;
        return res;
    }
};
