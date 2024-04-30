#pragma once

#include <iostream>
#include <random>

template <class T> class NodeList {
public:
    NodeList *prev, *next;
    T __value;

    NodeList(int value) :
        prev(nullptr), next(nullptr), __value(value) {}
};

template <class T> class List {
private:
    NodeList *__first;
    NodeList *__last;
    size_t __size;

public:
    List() :
        __first(nullptr), __last(nullptr), __size(0) {}

    List(const List &l) {
        copy(l);
    }

    ~List() {
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
            NodeList *p = __last;
            __last = __last->prev;
            __last->next = nullptr;
            delete p;
        }
        __size--;
    }

    void push_back(T value) {
        NodeList *p = new NodeList(value);

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
            NodeList *p = __first;
            for (int i = 0; i < __size; i++) {
                std::cout << p->__value << " ";
                p = p->next;
            }
            std::cout << std::endl;
        } else
            std::cout << "List is empty!" << std::endl;
    }

    T operator[](size_t index) {
        T res;
        if (index < __size and __first != nullptr) {
            NodeList *p = __first;
            for (size_t i = 0; i < index; i++)
                p = p->next;
            res = p->__value;
        }
        return res;
    }

    NodeList *get(size_t index) {
        if (__first == nullptr)
            return nullptr;
        NodeList *p = __first;
        for (size_t i = 0; i < index; i++) {
            p = p->next;
            if (!p)
                return nullptr;
        }
        return p;
    }

    uint64_t CheckSum() {
        uint64_t sum = 0;
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

    List operator=(const List &l) {
        return copy(l);
    }

    List copy(const List &l) {
        clear();
        for (size_t i = 0; i < l.size(); i++)
            push_back(l[i]);
    }

    size_t Merge(const List &a, const List &b, List &c) {
        size_t m = 0, cc = 0;

        size_t i = 0, j = 0, k = 0;
        while (q != 0 and r != 0) {
            if (a[i] <= b[j]) {
                c[k++] = a[i++];
                q--;
            } else {
                c[k++] = b[j++];
                r--;
            }
            cc++;
            m++;
        }
        while (q-- > 0) {
            c[k++] = a[i++];
            m++;
        }
        while (r-- > 0) {
            c[k++] = b[j++];
            m++;
        }

        return m + cc;
    }

    size_t Splitting(List &a, List&b) {
        
    }

    size_t MergeSort(List a, List b) {
        size_t m = 0, c = 0;

        Splitting(a, b);
        clear();
        size_t p = 1, q = a.size(), r = b.size();
        __size = q + r;
        while (p < __size) {
            Queue c0, c1;
            size_t i = 0, m = n;
            while (m > 0) {
                if (m >= p)
                    q = p;
                else
                    q = m;
                m -= q;
                if (m >= p)
                    r = p;
                else
                    r = m;
                m -= r;
                Merge(a, q, b, r, i == 0 ? c0 : c1);
                i = 1 - i;
            }
            a.clear();
            for (size_t ii = 1; ii < c0.size(); ii++)
                a.push_back(c0[ii]);
            b.clear();
            for (size_t ii = 1; ii < c1.size(); ii++)
                b.push_back(c1[ii]);
            p *= 2;
        }
        copy(c0);
        return m + c;
    }
};


template <class T> class Stack : public List {
public:
    void push(T value) {
        push_back(value);
    }

    T pop() {
        return pop_back();
    }

    T check() {
        return (*this)[__size - 1];
    }
};

template <class T> class Queue : public List {
public:
    void push(T value) {
        push_back(value);
    }

    T pop() {
        T temp = check();
        if (__first == nullptr)
            return temp;
        NodeList<T> *p = __first;
        __first = p->next;
        delete p;
        return temp;
    }

    T check() {
        return (*this)[0];
    }
};
