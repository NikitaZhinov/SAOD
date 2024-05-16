#pragma once

#include <iostream>
#include <random>

template <typename T>
struct NodeList {
    NodeList *next_, *prev_;
    T value_;

    NodeList(const T &value) :
        next_(nullptr), prev_(nullptr), value_(value) {}
};

template <typename T> class list {
private:
    NodeList<T> *first_, *last_;
    std::size_t size_;

public:
    list() :
        first_(nullptr), last_(nullptr), size_(0) {}

    list(const list<T> &other);
    list(list<T> &&other);
    ~list();

    void clear();
    std::size_t get_size();
    void push_back(const T &value);
    void push_front(const T &value);
    T pop_back();
    T pop_front();
    void fill(const T &value);

    T operator()(std::size_t index) const;

    void print();
    std::size_t merge(const list<T> &a, const list<T> &b, list<T> &c);
    std::size_t split(list<T> &a, list<T> &b); // возможно не работает
    std::size_t merge_sort();                  // не работает
};

template <typename T> class stack {
private:
    NodeList<T> *first_, *last_;
    std::size_t size_;

public:
    stack() :
        first_(nullptr), last_(nullptr), size_(0) {}

    stack(const stack<T> &other);
    stack(stack<T> &&other);
    ~stack();

    void clear();
    std::size_t get_size();
    void push(const T &value);
    T pop();
    T check();

    void fill_inc(std::size_t size);
    void fill_dec(std::size_t size);
    void fill_rand(std::size_t size);
};

template <typename T> class queue {
private:
    NodeList<T> *first_, *last_;
    std::size_t size_;

public:
    queue() :
        first_(nullptr), last_(nullptr), size_(0) {}

    queue(const queue<T> &other);
    queue(queue<T> &&other);
    ~queue();

    void clear();
    std::size_t get_size();
    void push(const T &value);
    T pop();
    T check();

    void fill_inc(std::size_t size);
    void fill_dec(std::size_t size);
    void fill_rand(std::size_t size);
};
